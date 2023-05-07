###############################################################################
# imports
###############################################################################

import struct
import heterocl as hcl
import heterocl.op.nn as nn
from collections import OrderedDict
import numpy as np
import os
import json
import torch
from torch.utils.data import DataLoader
import torchvision
import torchvision.transforms as transforms
import pickle

CIFAR100_TEST_MEAN = (0.5088964127604166,
                      0.48739301317401956, 0.44194221124387256)
CIFAR100_TEST_STD = (0.2682515741720801,
                     0.2573637364478126, 0.2770957707973042)

###############################################################################
# helper functions
###############################################################################


def relu(data, name='relu'):
    return hcl.compute(data.shape, lambda *y:
                       hcl.select(data[y] <= 0,
                                  0, data[y]),
                       name=name, dtype=data.dtype)


def linear(data, weight, bias, name='linear'):
    batch, in_feature = data.shape
    h, w = weight.shape
    _, out_feature = w, h
    din_feature = hcl.reduce_axis(0, in_feature)
    return hcl.compute((batch, out_feature), lambda x, y:hcl.sum(
        data[x, din_feature] * weight[y, din_feature], axis=[din_feature], dtype=data.dtype
    ) + bias[y], name=name, dtype=data.dtype)

def maxpool2d(data, pooling=[2, 2], stride=[2, 2], padding=0, name='max_pool2d', dtype=None):    # pooling_h, pooling_w = pooling
    # stride_h, stride_w = stride
    # batch, channel, height, width = data.shape
    # pad_top = pad_left = pad_bottom = pad_right = padding

    # pad_before = [0, 0, pad_top, pad_left]
    # pad_after = [0, 0, pad_bottom, pad_right]

    # # HLS backend: comment out
    # data = nn.pad(data, pad_before, pad_after, pad_value=0, name=name+"_pad")
    # out_height = (height - pooling_h + pad_top + pad_bottom) // stride_h + 1
    # out_width = (width - pooling_w + pad_left + pad_right) // stride_w + 1
    # dheight = hcl.reduce_axis(0, pooling_h)
    # dwidth = hcl.reduce_axis(0, pooling_w)
    # return hcl.compute(
    #     (batch, channel, out_height, out_width),
    #     lambda i, c, h, w: max_(data[i, c, h *
    #                                 stride_h +
    #                                 dheight, w *
    #                                 stride_w +
    #                                 dwidth], axis=[dheight, dwidth]),
    #     name=name, dtype=data.dtype)  
    print(data.dtype)
    assert len(data.shape) == 4, "only support 4-dim pooling"
    assert len(stride) == 2, "only support 2-dim stride"
    if dtype is None:
        dtype = data.dtype
    max_ = hcl.reducer(None, hcl.ast.Max, name="maximum")
    pooling_h, pooling_w = pooling
    stride_h, stride_w = stride
    batch, channel, height, width = data.shape
    pad_top = pad_left = pad_bottom = pad_right = padding

    pad_before = [0, 0, pad_top, pad_left]
    pad_after = [0, 0, pad_bottom, pad_right]

    data = nn.pad(data, pad_before, pad_after, pad_value=0.0, name=name + "_pad")
    out_height = (height - pooling_h + pad_top + pad_bottom) // stride_h + 1
    out_width = (width - pooling_w + pad_left + pad_right) // stride_w + 1
    dheight = hcl.reduce_axis(0, pooling_h)
    dwidth = hcl.reduce_axis(0, pooling_w)
    return hcl.compute(
        (batch, channel, out_height, out_width),
        lambda i, c, h, w: 
            max_(
                data[i, c, h * stride_h + dheight, w * stride_w + dwidth],
                axis=[dheight, dwidth]
            )
        ,
        name=name,
        dtype=dtype,
    )

def logsoftmax2d(data, axis=-1, name="logsoftmax"):
    reduce_axis = hcl.reduce_axis(0, data.shape[axis])

    def axis_sum(x, y):
        if axis == 0:
            return hcl.sum(hcl.exp(data[reduce_axis, y]), axis=[reduce_axis], dtype=data.dtype)
        elif axis == 1 or axis == -1:
            return hcl.sum(hcl.exp(data[x, reduce_axis]), axis=[reduce_axis], dtype=data.dtype)
        raise ValueError(f"axis is not legal. get {axis}, expect 0,1 and -1")
    
    if axis == 0:
        exp_sum = hcl.compute((data.shape[1],), lambda x: hcl.sum(hcl.exp(data[reduce_axis, x]), axis=[reduce_axis], dtype=data.dtype))
        return hcl.compute(
        data.shape, 
        lambda x, y: hcl.log(hcl.exp(data[x, y]) / exp_sum[y]),
        name=name,
        dtype=data.dtype)

    elif axis == 1 or axis == -1:
        exp_sum = hcl.compute((data.shape[0],), lambda x: hcl.sum(hcl.exp(data[x, reduce_axis]), axis=[reduce_axis], dtype=data.dtype), name=f"{name}_expsum")
        return hcl.compute(
        data.shape, 
        lambda x, y: hcl.log(hcl.exp(data[x, y]) / exp_sum[x]),
        name=name,
        dtype=data.dtype)

    else: raise ValueError(f"axis is not legal. get {axis}, expect 0,1 and -1")
    


def get_test_dataloader(mean, std, batch_size=16, num_workers=2, shuffle=False):
    """ return training dataloader
    Args:
        mean: mean of cifar100 test dataset
        std: std of cifar100 test dataset
        path: path to cifar100 test python dataset
        batch_size: dataloader batchsize
        num_workers: dataloader num_works
        shuffle: whether to shuffle
    Returns: cifar100_test_loader:torch dataloader object
    """

    transform_test = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize(mean, std)
    ])
    # cifar100_test = CIFAR100Test(path, transform=transform_test)
    cifar100_test = torchvision.datasets.CIFAR100(
        root="../../dataset/cifar100-python", train=False, download=True, transform=transform_test)
    cifar100_test_loader = DataLoader(
        cifar100_test, shuffle=shuffle, num_workers=num_workers, batch_size=batch_size)

    return cifar100_test_loader


def gen_vitis_script(args):
    assert args.type in ["csynth","csim","cosim"]
    name,_ = args.cpp.split('.',maxsplit=1)
    with open(f'./c_{args.model}/run_{name}_{args.type}.tcl','w') as f:
        f.write(f"open_project {args.prj}\n")
        f.write(f"set_top {args.top}\n")
        f.write(f"add_files {args.cpp}\n")
        if args.type != "csynth":
            f.write(f"add_files -tb {args.model}_tb.cpp\n") # requiring a testbench
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

def conv2d_nchw_bias(
    Input,
    Filter,
    Bias,
    strides=[1, 1],
    padding=[0, 0],
    dilation=[1, 1],
    out_dtype=None,
    groups=1,
    name="conv2d",
):
    if out_dtype is None:
        out_dtype = Input.dtype
    assert isinstance(strides, int) or len(strides) == 2
    assert isinstance(dilation, int) or len(dilation) == 2
    if isinstance(strides, int):
        stride_h = stride_w = strides
    else:
        stride_h, stride_w = strides

    if isinstance(dilation, int):
        dilation_h = dilation_w = dilation
    else:
        dilation_h, dilation_w = dilation

    if groups > 1:
        shape = Filter.shape
        new_shape = (shape[0], groups, shape[2], shape[3])
        Filter = hcl.compute(new_shape, lambda o, i, h, w: Filter[o, 0, h, w])
    batch, _, in_height, in_width = Input.shape
    num_filter, channel, kernel_h, kernel_w = Filter.shape
    # compute the output shape
    dilated_kernel_h = (kernel_h - 1) * dilation_h + 1
    dilated_kernel_w = (kernel_w - 1) * dilation_w + 1
    pad_top, pad_left, pad_down, pad_right = nn.get_pad_tuple(padding)
    out_channel = num_filter
    out_height = (in_height - dilated_kernel_h + pad_top + pad_down) // stride_h + 1
    out_width = (in_width - dilated_kernel_w + pad_left + pad_right) // stride_w + 1
    # compute graph
    pad_before = [0, 0, pad_top, pad_left]
    pad_after = [0, 0, pad_down, pad_right]
    if padding != [0, 0]:
        temp = nn.pad(Input, pad_before, pad_after, name=name + "_pad")
    else:
        temp = Input
    if groups > 1:
        rc = hcl.reduce_axis(0, channel / groups, name="rc")
    else:
        rc = hcl.reduce_axis(0, channel, name="rc")
    ry = hcl.reduce_axis(0, kernel_h, name="ry")
    rx = hcl.reduce_axis(0, kernel_w, name="rx")
    if groups > 1:
        return hcl.compute(
            (batch, out_channel, out_height, out_width),
            lambda nn, ff, yy, xx: hcl.sum(
                temp[
                    nn,
                    ff % groups,
                    yy * stride_h + ry * dilation_h,
                    xx * stride_w + rx * dilation_w,
                ]
                * Filter[ff, rc, ry, rx],
                axis=[rc, ry, rx],
                dtype=out_dtype,
            ) + Bias[ff],
            name=name,
            dtype=out_dtype,
        )
    return hcl.compute(
        (batch, out_channel, out_height, out_width),
        lambda nn, ff, yy, xx: hcl.sum(
            temp[
                nn, rc, yy * stride_h + ry * dilation_h, xx * stride_w + rx * dilation_w
            ]
            * Filter[ff, rc, ry, rx],
            axis=[rc, ry, rx],
            dtype=out_dtype,
        ) + Bias[ff],
        name=name,
        dtype=out_dtype,
    )


def save_weights_dat(path):
    # 读取.pth文件中的模型权重
    state_dict = torch.load(path,map_location=torch.device('cpu'))
    dat_path = f"{path}_dat/"
    if not os.path.exists(dat_path):
        os.mkdir(dat_path)
    # 保存每个层的权重
    config = {}
    cnt = 0
    for key in state_dict.keys():
        if "num_batches_tracked" in key:
            continue
        print(f"Saving {key}...")
        # 生成文件名
        filename = dat_path + f'layer{cnt}.dat'

        # 保存权重为二进制.dat文件
        weights = state_dict[key].data.numpy()
        config[f"layer{cnt}.dat"] = weights.shape
        weights = weights.flatten()
        if weights.shape[0] < 20:
            print(weights)
        np.savetxt(filename, weights, delimiter=',', newline=',')
        cnt += 1

    with open(f"{dat_path}config.json", "w") as f:
        f.write(json.dumps(config))

def gen_weights_cpp_header(func, dat_dir, header_path):
    # !!! Fair use
    arg_names = list(func.__code__.co_varnames)[:func.__code__.co_argcount]

    # 遍历目录下的 .dat 文件
    dat_files = [f for f in os.listdir(dat_dir) if f.endswith('.dat')]

    all_weights_str = []
    type_ = "ap_fixed<10,4>"
    # 创建 .h 文件
    with open(header_path, 'w') as header_file:
        with open(f"{dat_dir}config.json", 'r') as config_file:
            config = json.load(config_file)
        # 添加头文件保护宏
        header_file.write('#ifndef _WEIGHTS_H_\n')
        header_file.write('#define _WEIGHTS_H_\n\n')
        
        #include <ap_fixed.h>
        header_file.write("#include <ap_fixed.h> \n\n")

        # 导入 .dat 文件
        for i, arg_name in enumerate(arg_names[1:]): # ignoring input_image
            dat_file_name = f'layer{i}.dat'
            if dat_file_name in dat_files:
                dat_file_path = os.path.join(dat_dir, dat_file_name)
                shape_str = ""
                for dim in config[f'layer{i}.dat']:
                    shape_str += f"[{dim}]"
                # for convenience (since testbench need manually implement, we give each weight parameter a more simple name. you can also use arg_name to know its actual name.)
                header_file.write('{} {}{} = {{\n\t#include \"../{}\"\n}};\n'.format(
                        type_, f"w_{i}", shape_str, dat_file_path)) # replace f"w_{}" with arg_name to get the actual name
                all_weights_str.append(f"w_{i}")
            else:
                raise ValueError('No matching .dat file found for argument {}'.format(arg_name))

        # 添加结尾宏定义
        header_file.write('\n#endif // _WEIGHTS_H_\n')
        header_file.write('\n// The comment below help you to include weights fast\n')
        # header_file.write('// ' + str(all_weights_str))
        header_file.write('// ' + ', '.join(all_weights_str))


def gen_input(data_test, input_save_dir, batch_size):
    if not os.path.exists(input_save_dir):
        os.mkdir(input_save_dir)
    data_test_loader = DataLoader(data_test, batch_size=batch_size, shuffle=False, num_workers=8)
    cnt = 0
    config = {}
    for data, labels in data_test_loader:
        data_np = data.numpy().flatten()
        labels_np = labels.numpy().flatten()
        print(labels_np)
        if "input_shape" not in config.keys():
            config["input_shape"] = data.shape
            config["label_shape"] = labels.shape
        np.savetxt(f"{input_save_dir}/input_batch{cnt}.dat", data_np, delimiter=',', newline=',')
        np.savetxt(f"{input_save_dir}/label_batch{cnt}.dat", labels_np, delimiter=',', newline=',')
        cnt += 1
    with open(f"{input_save_dir}/config.json", "w") as f:
        f.write(json.dumps(config))
        
    

if __name__ == "__main__":
    save_weights_dat("lenet/batchsize2.pth")