import argparse
import heterocl as hcl
from lenet_model import lenet
from utils.functions import gen_vitis_script, gen_weights_cpp_header
import optimize

hcl.init(hcl.Fixed(10, 4))

def create_lenet(batch_size, target, args, image_size=[32,32], kernel_size=[5, 5]):
    image_h, image_w = image_size
    kernel_h, kernel_w = kernel_size

    input = hcl.placeholder((batch_size, 1, image_h, image_w), "input_image")

    conv1 = hcl.placeholder((6, 1, kernel_h, kernel_w), "c1_weight")
    bias1 = hcl.placeholder((6,), "c1_bias")

    conv21 = hcl.placeholder((16, 6, kernel_h, kernel_w), "c21_weight")
    bias21 = hcl.placeholder((16,), "c21_bias")
    
    conv22 = hcl.placeholder((16, 6, kernel_h, kernel_w), "c22_weight")
    bias22 = hcl.placeholder((16,), "c22_bias")

    conv3 = hcl.placeholder((120, 16, kernel_h, kernel_w), "c3_weight")
    bias3 = hcl.placeholder((120,), "c3_bias")

    fc_weight1 = hcl.placeholder((84, 120), "fc4_weight")
    fc_bias1 = hcl.placeholder((84,), "fc4_bias")

    fc_weight2 = hcl.placeholder((10, 84), "fc5_weight")
    fc_bias2 = hcl.placeholder((10,), "fc5_bias")
    
    lenet_inputs = [input, conv1, bias1, conv21, bias21, conv22, bias22, conv3, bias3, fc_weight1, fc_bias1, fc_weight2, fc_bias2]
    
    sm = hcl.create_scheme(
        lenet_inputs,
        lenet
    )

    s = hcl.create_schedule_from_scheme(sm)

    if args.weight_h:
        gen_weights_cpp_header(lenet, "../../weights/lenet/batchsize2.pth_dat/", "./c_lenet/weights.h")
    # Buffer
    if args.buffer:
        conv_layers = optimize.conv_buffer(s, lenet)

    # outline
    if args.outline:
        optimize.function_outline(s, lenet, [])

    # Array partition
    if args.partition:
        optimize.array_partition(s, lenet_inputs)

    return hcl.build(s, target=target)


def run(batch_size, args, target='llvm'):
    f = create_lenet(batch_size, target, args)
    if target == 'vhls':
        return
        with open(f"./c_lenet/{args.cpp}", 'w') as file:
            file.write(f)
        return


if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("-prj",help="Vitis project name",required=True)
    arg_parser.add_argument("-cpp",help="Generated cpp name",required=True)
    arg_parser.add_argument("-type",help="[csynth,csim,cosim]",default="csynth")
    arg_parser.add_argument("-sol",help="The solution name",required=True)
    arg_parser.add_argument("-part",help="The part you want vitis to use. Eg. virtex7",default="virtex7")
    arg_parser.add_argument("-period",help="The nanosecond of a clock cycle",default=13)

    # arg_parser.add_argument("-loop_aggr",help="Enable loop aggregation optimization",action="store_true",default=False)
    arg_parser.add_argument("-outline",help="Enable function outline",action="store_true",default=False)
    # arg_parser.add_argument("-fifo",help="Enable fifo to pass intermediate variables",action="store_true",default=False)
    arg_parser.add_argument("-buffer",help="Enable buffer for conv layers",action="store_true",default=False)
    arg_parser.add_argument("-partition",help="Enable partition for arrays",action="store_true",default=False)
    # arg_parser.add_argument("-pipeline",help="Enable pipeline for convolution",action="store_true",default=False)
    arg_parser.add_argument("-top",help="Top function name", default="top")
    arg_parser.add_argument("-model",help="Model name",default="lenet")
    arg_parser.add_argument("-weight_h",help="Enable generation of weight.h",action="store_true",default=False)


    args = arg_parser.parse_args()
    run(2, args, "vhls")
    gen_vitis_script(args)