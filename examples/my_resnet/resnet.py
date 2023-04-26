import heterocl as hcl
from resnet_model import nn_resnet18
import os
import sys
root_dir = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.append(root_dir)
from utils.functions import CIFAR100_TEST_MEAN, CIFAR100_TEST_STD, get_test_dataloader
import torch
import numpy as np
import json
import argparse
import inspect
import optimize

PROJECT_NAME = "prj_mlir"
TOP_FUNC_NAME = "top"

hcl.init(hcl.Fixed(10,6))


def get_resnet_config(scale):
    if scale == 18:
        return "bb", 2, 2, 2, 2
    elif scale == 34:
        return "bb", 3, 4, 6, 3
    elif scale == 50:
        return "bn", 3, 4, 6, 3
    elif scale == 101:
        return "bn", 3, 4, 23, 3
    elif scale == 152:
        return "bn", 3, 8, 36, 3
    else:
        assert (f"No resnet {scale} object")

def nn_gen_weights(in_channel, out_channel, kernel_size, id, shortcut):
    conv_weights = []
    conv1_weight = hcl.placeholder(
        (out_channel, in_channel, kernel_size, kernel_size), f"conv{id}_weight1")
    conv2_weight = hcl.placeholder(
        (out_channel, out_channel, kernel_size, kernel_size), f"conv{id}_weight2")
    if shortcut:
        conv3_weight = hcl.placeholder(
            (out_channel, in_channel, 1, 1), f"conv{id}_shortcut_weight")
        bn = [[],[],[]]
        for i in range(1,4):
            for var in ["gamma","beta","mean","var"]:
                bn[i - 1].append(hcl.placeholder((out_channel,),f"bn{id}_{var}{i}"))

        return [conv1_weight, *bn[0],
                         conv2_weight, *bn[1], conv3_weight, *bn[2]]
    else:
        bn = [[],[],[]]
        for i in range(1,3):
            for var in ["gamma","beta","mean","var"]:
                bn[i - 1].append(hcl.placeholder((out_channel,),f"bn{id}_{var}{i}"))

        return [conv1_weight, *bn[0],
                         conv2_weight, *bn[1]]


def nn_create_resnet18(batch_size, target, args,image_size=[32, 32], resnet_scale=18, in_channel=64, kernel_size=3, num_classes=100):
    '''batch, channel, height, width'''
    image_h, image_w = image_size

    input_image = hcl.placeholder(
        (batch_size, 3, image_h, image_w), "input_image")

    block_type, conv2_depth, conv3_depth, conv4_depth, conv5_depth, = get_resnet_config(
        resnet_scale)

    out_channel = in_channel
    expansion = 1 if block_type == "bb" else 4

    conv1_x_weight = hcl.placeholder(
        (out_channel, 3, kernel_size, kernel_size), "conv1_weight")
    bn1 = []
    for var in ["gamma","beta","mean","var"]:
        bn1.append(hcl.placeholder((out_channel,),f"bn1_{var}"))

    conv2_0_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="2_0",shortcut=False)
    in_channel = out_channel * expansion
    conv2_1_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="2_1",shortcut=False)
    in_channel = out_channel * expansion

    out_channel = 128

    conv3_0_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="3_0",shortcut=True)
    in_channel = out_channel * expansion
    conv3_1_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="3_1",shortcut=False)
    in_channel = out_channel * expansion

    out_channel = 256

    conv4_0_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="4_0",shortcut=True)
    in_channel = out_channel * expansion
    conv4_1_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="4_1",shortcut=False)
    in_channel = out_channel * expansion

    out_channel = 512

    conv5_0_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="5_0",shortcut=True)
    in_channel = out_channel * expansion
    conv5_1_vars = nn_gen_weights(in_channel,out_channel,kernel_size,id="5_1",shortcut=False)
    in_channel = out_channel * expansion

    fc_weight = hcl.placeholder((num_classes, out_channel), "fc_weight")
    fc_bias = hcl.placeholder((num_classes,), "fc_bias")

    resnet_inputs = [input_image,
         conv1_x_weight, *bn1,
         *conv2_0_vars,*conv2_1_vars,
         *conv3_0_vars,*conv3_1_vars,
         *conv4_0_vars,*conv4_1_vars,
         *conv5_0_vars,*conv5_1_vars,
         fc_weight, fc_bias,
         ]

    sm = hcl.create_scheme(
        resnet_inputs,
        nn_resnet18
    )
    
    
    ################################################################
    # optimization
    ################################################################
   

    s = hcl.create_schedule_from_scheme(sm)

    # BatchNorm + ReLU
    ignore_ops = []
    if args.loop_aggr:
        aggr_ops = optimize.loop_aggregation(s, nn_resnet18)
        ignore_ops += aggr_ops

    # LB and WB for conv layer
    if args.buffer:
        conv_layers = optimize.conv_buffer(s, nn_resnet18)

    # Fifo
    if args.fifo:
        optimize.fifo(s, nn_resnet18, ignore_ops)

    # Function outline
    if args.outline:
        optimize.function_outline(s, nn_resnet18, ignore_ops)

    # Array partition
    if args.partition:
        optimize.array_partition(s, resnet_inputs)

    if args.pipeline:
        optimize.pipeline(s, nn_resnet18, conv_layers)

    return hcl.build(s, target=target)


def linearize_batchnorm(weight, bias, mean, var):
    '''y = \frac{x - \mathrm{E}[x]}{ \sqrt{\mathrm{Var}[x] + \epsilon}} * \gamma + \beta'''
    eps = 1e-5
    denominator = (var + eps).rsqrt()
    linearized_weight = weight * denominator
    linearized_bias = bias - mean * denominator * weight

    return linearized_weight.numpy(), linearized_bias.numpy()


def nn_load_np_params18(pt_name):
    model = torch.load(pt_name, map_location=torch.device('cpu'))
    # print(model.keys())

    conv1_x_weight = model['conv1.0.weight'].numpy()
    bn1_x_gamma = model['conv1.1.weight'].numpy()
    bn1_x_beta = model['conv1.1.bias'].numpy()
    bn1_x_mean = model['conv1.1.running_mean'].numpy()
    bn1_x_var = model['conv1.1.running_var'].numpy()

    conv2_0_conv1 = model['conv2_x.0.residual_function.0.weight'].numpy()
    bn20_x_1_gamma = model['conv2_x.0.residual_function.1.weight'].numpy()
    bn20_x_1_beta = model['conv2_x.0.residual_function.1.bias'].numpy()
    bn20_x_1_mean = model['conv2_x.0.residual_function.1.running_mean'].numpy()
    bn20_x_1_var = model['conv2_x.0.residual_function.1.running_var'].numpy()

    conv2_0_conv2 = model['conv2_x.0.residual_function.3.weight'].numpy()
    bn20_x_2_gamma = model['conv2_x.0.residual_function.4.weight'].numpy()
    bn20_x_2_beta = model['conv2_x.0.residual_function.4.bias'].numpy()
    bn20_x_2_mean = model['conv2_x.0.residual_function.4.running_mean'].numpy()
    bn20_x_2_var = model['conv2_x.0.residual_function.4.running_var'].numpy()

    conv2_1_conv1 = model['conv2_x.1.residual_function.0.weight'].numpy()
    bn21_x_1_gamma = model['conv2_x.1.residual_function.1.weight'].numpy()
    bn21_x_1_beta = model['conv2_x.1.residual_function.1.bias'].numpy()
    bn21_x_1_mean = model['conv2_x.1.residual_function.1.running_mean'].numpy()
    bn21_x_1_var = model['conv2_x.1.residual_function.1.running_var'].numpy()

    conv2_1_conv2 = model['conv2_x.1.residual_function.3.weight'].numpy()
    bn21_x_2_gamma = model['conv2_x.1.residual_function.4.weight'].numpy()
    bn21_x_2_beta = model['conv2_x.1.residual_function.4.bias'].numpy()
    bn21_x_2_mean = model['conv2_x.1.residual_function.4.running_mean'].numpy()
    bn21_x_2_var = model['conv2_x.1.residual_function.4.running_var'].numpy()

    conv3_0_conv1 = model['conv3_x.0.residual_function.0.weight'].numpy()
    bn30_x_1_gamma = model['conv3_x.0.residual_function.1.weight'].numpy()
    bn30_x_1_beta = model['conv3_x.0.residual_function.1.bias'].numpy()
    bn30_x_1_mean = model['conv3_x.0.residual_function.1.running_mean'].numpy()
    bn30_x_1_var = model['conv3_x.0.residual_function.1.running_var'].numpy()

    conv3_0_conv2 = model['conv3_x.0.residual_function.3.weight'].numpy()
    bn30_x_2_gamma = model['conv3_x.0.residual_function.4.weight'].numpy()
    bn30_x_2_beta = model['conv3_x.0.residual_function.4.bias'].numpy()
    bn30_x_2_mean = model['conv3_x.0.residual_function.4.running_mean'].numpy()
    bn30_x_2_var = model['conv3_x.0.residual_function.4.running_var'].numpy()

    conv3_0_convs = model['conv3_x.0.shortcut.0.weight'].numpy()
    bn30_x_s_gamma = model['conv3_x.0.shortcut.1.weight'].numpy()
    bn30_x_s_beta = model['conv3_x.0.shortcut.1.bias'].numpy()
    bn30_x_s_mean = model['conv3_x.0.shortcut.1.running_mean'].numpy()
    bn30_x_s_var = model['conv3_x.0.shortcut.1.running_var'].numpy()

    conv3_1_conv1 = model['conv3_x.1.residual_function.0.weight'].numpy()
    bn31_x_1_gamma = model['conv3_x.1.residual_function.1.weight'].numpy()
    bn31_x_1_beta = model['conv3_x.1.residual_function.1.bias'].numpy()
    bn31_x_1_mean = model['conv3_x.1.residual_function.1.running_mean'].numpy()
    bn31_x_1_var = model['conv3_x.1.residual_function.1.running_var'].numpy()
    
    conv3_1_conv2 = model['conv3_x.1.residual_function.3.weight'].numpy()
    bn31_x_2_gamma = model['conv3_x.1.residual_function.4.weight'].numpy()
    bn31_x_2_beta = model['conv3_x.1.residual_function.4.bias'].numpy()
    bn31_x_2_mean = model['conv3_x.1.residual_function.4.running_mean'].numpy()
    bn31_x_2_var = model['conv3_x.1.residual_function.4.running_var'].numpy()

    conv4_0_conv1 = model['conv4_x.0.residual_function.0.weight'].numpy()
    bn40_x_1_gamma = model['conv4_x.0.residual_function.1.weight'].numpy()
    bn40_x_1_beta = model['conv4_x.0.residual_function.1.bias'].numpy()
    bn40_x_1_mean = model['conv4_x.0.residual_function.1.running_mean'].numpy()
    bn40_x_1_var = model['conv4_x.0.residual_function.1.running_var'].numpy()

    conv4_0_conv2 = model['conv4_x.0.residual_function.3.weight'].numpy()
    bn40_x_2_gamma = model['conv4_x.0.residual_function.4.weight'].numpy()
    bn40_x_2_beta = model['conv4_x.0.residual_function.4.bias'].numpy()
    bn40_x_2_mean = model['conv4_x.0.residual_function.4.running_mean'].numpy()
    bn40_x_2_var = model['conv4_x.0.residual_function.4.running_var'].numpy()

    conv4_0_convs = model['conv4_x.0.shortcut.0.weight'].numpy()
    bn40_x_s_gamma = model['conv4_x.0.shortcut.1.weight'].numpy()
    bn40_x_s_beta = model['conv4_x.0.shortcut.1.bias'].numpy()
    bn40_x_s_mean = model['conv4_x.0.shortcut.1.running_mean'].numpy()
    bn40_x_s_var = model['conv4_x.0.shortcut.1.running_var'].numpy()

    conv4_1_conv1 = model['conv4_x.1.residual_function.0.weight'].numpy()
    bn41_x_1_gamma = model['conv4_x.1.residual_function.1.weight'].numpy()
    bn41_x_1_beta = model['conv4_x.1.residual_function.1.bias'].numpy()
    bn41_x_1_mean = model['conv4_x.1.residual_function.1.running_mean'].numpy()
    bn41_x_1_var = model['conv4_x.1.residual_function.1.running_var'].numpy()

    conv4_1_conv2 = model['conv4_x.1.residual_function.3.weight'].numpy()
    bn41_x_2_gamma = model['conv4_x.1.residual_function.4.weight'].numpy()
    bn41_x_2_beta = model['conv4_x.1.residual_function.4.bias'].numpy()
    bn41_x_2_mean = model['conv4_x.1.residual_function.4.running_mean'].numpy()
    bn41_x_2_var = model['conv4_x.1.residual_function.4.running_var'].numpy()
    
    conv5_0_conv1 = model['conv5_x.0.residual_function.0.weight'].numpy()
    bn50_x_1_gamma = model['conv5_x.0.residual_function.1.weight'].numpy()
    bn50_x_1_beta = model['conv5_x.0.residual_function.1.bias'].numpy()
    bn50_x_1_mean = model['conv5_x.0.residual_function.1.running_mean'].numpy()
    bn50_x_1_var = model['conv5_x.0.residual_function.1.running_var'].numpy()

    conv5_0_conv2 = model['conv5_x.0.residual_function.3.weight'].numpy()
    bn50_x_2_gamma = model['conv5_x.0.residual_function.4.weight'].numpy()
    bn50_x_2_beta = model['conv5_x.0.residual_function.4.bias'].numpy()
    bn50_x_2_mean = model['conv5_x.0.residual_function.4.running_mean'].numpy()
    bn50_x_2_var = model['conv5_x.0.residual_function.4.running_var'].numpy()
    
    conv5_0_convs = model['conv5_x.0.shortcut.0.weight'].numpy()
    bn50_x_s_gamma = model['conv5_x.0.shortcut.1.weight'].numpy()
    bn50_x_s_beta = model['conv5_x.0.shortcut.1.bias'].numpy()
    bn50_x_s_mean = model['conv5_x.0.shortcut.1.running_mean'].numpy()
    bn50_x_s_var = model['conv5_x.0.shortcut.1.running_var'].numpy()
    
    conv5_1_conv1 = model['conv5_x.1.residual_function.0.weight'].numpy()
    bn51_x_1_gamma = model['conv5_x.1.residual_function.1.weight'].numpy()
    bn51_x_1_beta = model['conv5_x.1.residual_function.1.bias'].numpy()
    bn51_x_1_mean = model['conv5_x.1.residual_function.1.running_mean'].numpy()
    bn51_x_1_var = model['conv5_x.1.residual_function.1.running_var'].numpy()

    conv5_1_conv2 = model['conv5_x.1.residual_function.3.weight'].numpy()
    bn51_x_2_gamma = model['conv5_x.1.residual_function.4.weight'].numpy()
    bn51_x_2_beta = model['conv5_x.1.residual_function.4.bias'].numpy()
    bn51_x_2_mean = model['conv5_x.1.residual_function.4.running_mean'].numpy()
    bn51_x_2_var = model['conv5_x.1.residual_function.4.running_var'].numpy()

    fc_weight = model['fc.weight'].numpy()
    fc_bias = model['fc.bias'].numpy()

    return [
        conv1_x_weight, bn1_x_gamma,bn1_x_beta,bn1_x_mean,bn1_x_var,
        conv2_0_conv1, bn20_x_1_gamma,bn20_x_1_beta,bn20_x_1_mean,bn20_x_1_var, conv2_0_conv2, bn20_x_2_gamma,bn20_x_2_beta,bn20_x_2_mean,bn20_x_2_var,
        conv2_1_conv1, bn21_x_1_gamma,bn21_x_1_beta,bn21_x_1_mean,bn21_x_1_var, conv2_1_conv2, bn21_x_2_gamma,bn21_x_2_beta,bn21_x_2_mean,bn21_x_2_var,
        conv3_0_conv1, bn30_x_1_gamma,bn30_x_1_beta,bn30_x_1_mean,bn30_x_1_var, conv3_0_conv2, bn30_x_2_gamma,bn30_x_2_beta,bn30_x_2_mean,bn30_x_2_var, conv3_0_convs, bn30_x_s_gamma,bn30_x_s_beta,bn30_x_s_mean,bn30_x_s_var,
        conv3_1_conv1, bn31_x_1_gamma,bn31_x_1_beta,bn31_x_1_mean,bn31_x_1_var, conv3_1_conv2, bn31_x_2_gamma,bn31_x_2_beta,bn31_x_2_mean,bn31_x_2_var,
        conv4_0_conv1, bn40_x_1_gamma,bn40_x_1_beta,bn40_x_1_mean,bn40_x_1_var, conv4_0_conv2, bn40_x_2_gamma,bn40_x_2_beta,bn40_x_2_mean,bn40_x_2_var, conv4_0_convs, bn40_x_s_gamma,bn40_x_s_beta,bn40_x_s_mean,bn40_x_s_var,
        conv4_1_conv1, bn41_x_1_gamma,bn41_x_1_beta,bn41_x_1_mean,bn41_x_1_var, conv4_1_conv2, bn41_x_2_gamma,bn41_x_2_beta,bn41_x_2_mean,bn41_x_2_var,
        conv5_0_conv1, bn50_x_1_gamma,bn50_x_1_beta,bn50_x_1_mean,bn50_x_1_var, conv5_0_conv2, bn50_x_2_gamma,bn50_x_2_beta,bn50_x_2_mean,bn50_x_2_var, conv5_0_convs, bn50_x_s_gamma,bn50_x_s_beta,bn50_x_s_mean,bn50_x_s_var,
        conv5_1_conv1, bn51_x_1_gamma,bn51_x_1_beta,bn51_x_1_mean,bn51_x_1_var, conv5_1_conv2, bn51_x_2_gamma,bn51_x_2_beta,bn51_x_2_mean,bn51_x_2_var,
        fc_weight, fc_bias
    ]
  

def nn_run(batch_size, save_path,target='llvm'):
    variables = nn_load_np_params18("../../weights/resnet18/resnet18-199-best.pth")
    hcl_variables = []

    for _, var in enumerate(variables):
        hcl_variables.append(hcl.asarray(var.astype(np.float32)))

    f = nn_create_resnet18(batch_size, target, args)
    if target == 'vhls':
        return
        with open(f"./c_resnet/{save_path}", 'w') as file:
            file.write(f)
        return

    cifar100_test_loader = get_test_dataloader(
        CIFAR100_TEST_MEAN, CIFAR100_TEST_STD, num_workers=2, batch_size=batch_size)

    correct_1 = 0.0
    correct_5 = 0.0

    for n_iter, (image, label) in enumerate(cifar100_test_loader):
        if label.shape[0] == batch_size:
            hcl_input = hcl.asarray(image.numpy().astype(np.float32))
            hcl_out = hcl.asarray(
                np.zeros((batch_size, 100)).astype(np.float32))

            print(f'Iter {n_iter} run started')
            f(hcl_input,*hcl_variables,hcl_out)

            np_out = hcl_out.asnumpy()
            tensor_out = torch.tensor(np_out)

            _, pred = tensor_out.topk(5, 1, largest=True, sorted=True)
            print(pred)
            print(label)
            label = label.view(label.size(0), -1).expand_as(pred)

            # return
            correct = pred.eq(label).float()

            # compute top 5
            correct_5 += correct[:, :5].sum()

            # compute top1
            correct_1 += correct[:, :1].sum()

    print("Top 1 err: ", 1 - correct_1 / len(cifar100_test_loader.dataset))
    print("Top 5 err: ", 1 - correct_5 / len(cifar100_test_loader.dataset))


def save_weight(batchsize):
    weight_list = nn_load_np_params18(
        "../../weights/resnet18/resnet18-50-regular.pth")
    os.mkdir(f"../../weights/resnet18-weights-json-batchsize{batchsize}")
    for i, weight in enumerate(weight_list):
        data = {}
        data[str(i)] = weight.tolist()
        with open(f'../../weights/resnet18-weights-json-batchsize{batchsize}/layer{i}.json', 'w') as f:
            jdata = json.dumps(data)
            f.write(jdata)

def gen_vitis_script(args):
    assert args.type in ["csynth","csim","cosim"]
    name,_ = args.cpp.split('.',maxsplit=1)
    with open(f'./c_resnet/run_{name}_{args.type}.tcl','w') as f:
        f.write(f"open_project {args.prj}\n")
        f.write(f"set_top {TOP_FUNC_NAME}\n")
        f.write(f"add_files {args.cpp}\n")
        if args.type != "csynth":
            f.write(f"add_files -tb {name}_test.cpp\n") # requiring a testbench
        f.write(f"open_solution \"{args.sol}\" -reset\n")
        f.write(f"set_part {args.part}\n")
        f.write(f"create_clock -period {args.period} -name default\n")
        f.write("config_export -version 2.0.1;\n")
        if args.type == "csim":
            f.write("csim_design\n")
        elif args.type == "csynth":
            f.write("csynth_design\n")
        else:
            f.write("csim_design\n")
            f.write("csynth_design\n")
            f.write("cosim_design\n")
    f.close()



if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("-prj",help="Vitis project name",required=True)
    arg_parser.add_argument("-cpp",help="Generated cpp name",required=True)
    arg_parser.add_argument("-type",help="[csynth,csim,cosim]",default="csynth")
    arg_parser.add_argument("-sol",help="The solution name",required=True)
    arg_parser.add_argument("-part",help="The part you want vitis to use. Eg. virtex7",default="virtex7")
    arg_parser.add_argument("-period",help="The nanosecond of a clock cycle",default=13)

    arg_parser.add_argument("-loop_aggr",help="Enable loop aggregation optimization",action="store_true",default=False)
    arg_parser.add_argument("-outline",help="Enable function outline",action="store_true",default=False)
    arg_parser.add_argument("-fifo",help="Enable fifo to pass intermediate variables",action="store_true",default=False)
    arg_parser.add_argument("-buffer",help="Enable buffer for conv layers",action="store_true",default=False)
    arg_parser.add_argument("-partition",help="Enable partition for arrays",action="store_true",default=False)
    arg_parser.add_argument("-pipeline",help="Enable pipeline for convolution",action="store_true",default=False)

    args = arg_parser.parse_args()
    # run(2, args.cpp,'vhls')
    # save_weight(2)
    nn_run(2,args.cpp,"vhls")
    gen_vitis_script(args)
