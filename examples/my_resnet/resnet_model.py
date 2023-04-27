import heterocl as hcl
import heterocl.op.nn as nn
import sys
import os
root_dir = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.append(root_dir)
from utils.functions import linear, relu

###############################################################################
# BasicBlock for ResNet
###############################################################################

def nn_basicblock(input,
               weight_conv1, 
               gamma_1,beta_1,mean_1,var_1,
               weight_conv2,
               gamma_2,beta_2,mean_2,var_2,
               weight_conv_shortcut=None,
               gamma_s=None,beta_s=None,mean_s=None,var_s=None,
               stride=1,prefix="basicblock"):
    # print(weight_conv1.shape, a_batch_norm1.shape, b_batch_norm1.shape,
    #       weight_conv2.shape, a_batch_norm2.shape, b_batch_norm2.shape)
    # if weight_conv_shortcut != None:
    #     print(weight_conv_shortcut.shape, a_batch_norm_shortcut.shape,
    #           b_batch_norm_shortcut.shape)
    expansion = 1
    batch, in_channels, in_height, in_width = input.shape
    out_channels, channel, kernel_h, kernel_w = weight_conv1.shape
    conv1 = nn.conv2d_nchw(input,weight_conv1,strides=[stride,stride],name=f"{prefix}_conv1",padding=[1,1])
    batch_norm1, _, _ = nn.batch_norm(conv1,gamma_1,beta_1,mean_1,var_1,name=f"{prefix}_bn1")
    _relu = relu(batch_norm1, name=f"{prefix}_relu1")
    conv2 = nn.conv2d_nchw(_relu, weight_conv2, name=f"{prefix}_conv2",padding=[1,1])
    batch_norm2, _, _ = nn.batch_norm(conv2, gamma_2, beta_2, mean_2, var_2, name=f"{prefix}_bn2")
    if stride != 1 or in_channels != expansion * out_channels:
        shortcut = nn.conv2d_nchw(input, weight_conv_shortcut,
                          name=f"{prefix}_convs", strides=[stride, stride], padding=[0, 0])
        identity, _, _ = nn.batch_norm(shortcut, gamma_s,beta_s,mean_s,var_s,name=f"{prefix}_bns")
    else:
        identity = input
    addition = hcl.compute(
        identity.shape, lambda *x: batch_norm2[x] + identity[x],name=f"{prefix}_add")
    out = relu(addition, name=f"{prefix}_relu2")
    return out

###############################################################################
# BottleNeck for ResNet
###############################################################################


# def bottleneck(input,
#                weights,
#                name="bottleneck", stride=1
#                ):
#     expansion = 4
#     weight_conv1, a_batch_norm1, b_batch_norm1, weight_conv2, a_batch_norm2, b_batch_norm2, weight_conv3, a_batch_norm3, b_batch_norm3, weight_conv_shortcut, a_batch_norm_shortcut, b_batch_norm_shortcut = weights
#     batch, in_channels, in_height, in_width = input.shape
#     out_channels, channel, kernel_h, kernel_w = weight_conv1.shape
#     identity = input
#     conv1 = conv2d(input, weight_conv1, name="bottleneck_conv1")
#     batch_norm1 = batchnorm2d(conv1, a_batch_norm1,
#                               b_batch_norm1, name="bottleneck_bn1")
#     _relu1 = relu(batch_norm1, name="bottleneck_relu1")
#     conv2 = conv2d(_relu1, weight_conv2, name="bottleneck_conv2",
#                    stride=[stride, stride])
#     batch_norm2 = batchnorm2d(conv2, a_batch_norm2,
#                               b_batch_norm2, name="bottleneck_bn2")
#     _relu2 = relu(batch_norm2, name="bottleneck_relu2")
#     conv3 = conv2d(_relu2, weight_conv3, name="bottleneck_conv3")
#     batch_norm3 = batchnorm2d(conv3, a_batch_norm3,
#                               b_batch_norm3, name="bottleneck_bn3")
#     if stride != 1 or in_channels != out_channels * expansion:
#         identity = conv2d(identity, weight_conv_shortcut,
#                           name="bottleneck_conv_shortcut", stride=[stride, stride])
#         identity = batchnorm2d(identity, a_batch_norm_shortcut,
#                                b_batch_norm_shortcut, name="bottleneck_bn_shortcut")

#     out = batch_norm3 + identity
#     out = relu(out, name="bn_output_relu")

#     return out


def make_layer(input, num_blocks, stride, weights, type):
    """make resnet layers(by layer i didnt mean this 'layer' was the
    same as a neuron netowork layer, ex. conv layer), one layer may
    contain more than one residual block

    Args:
        block: block type, basic block or bottle neck block
        out_channels: output depth channel number of this layer
        num_blocks: how many blocks per layer
        stride: the stride of the first block of this layer
        weights = [(weight_conv1, a_batch_norm1, b_batch_norm1,
                weight_conv2, a_batch_norm2, b_batch_norm2,
                weight_conv_shortcut, a_batch_norm_shortcut, b_batch_norm_shortcut),...]

    Return:
        return a resnet layer
    """

    # we have num_block blocks per layer, the first block
    # could be 1 or 2, other blocks would always be 1
    strides = [stride] + [1] * (num_blocks - 1)
    for i, stride in enumerate(strides):
        if type == 0:  # 0 is basicblock
            input = nn_basicblock(input, weights[i], stride=stride)
        elif type == 1:  # 1 is bottleneck
            pass
            # input = bottleneck(input, weights[i], stride=stride)

    return input


def nn_resnet18(input_image,
             weight_conv1, conv1_gamma_1,conv1_beta_1,conv1_mean_1,conv1_var_1,
             conv2_0_conv1, conv2_0_bn_gamma_1, conv2_0_bn_beta_1,conv2_0_bn_mean_1,conv2_0_bn_var_1, conv2_0_conv2, conv2_0_bn_gamma_2, conv2_0_bn_beta_2,conv2_0_bn_mean_2,conv2_0_bn_var_2,
             conv2_1_conv1, conv2_1_bn_gamma_1, conv2_1_bn_beta_1,conv2_1_bn_mean_1,conv2_1_bn_var_1, conv2_1_conv2, conv2_1_bn_gamma_2, conv2_1_bn_beta_2,conv2_1_bn_mean_2,conv2_1_bn_var_2,
             conv3_0_conv1, conv3_0_bn_gamma_1, conv3_0_bn_beta_1,conv3_0_bn_mean_1,conv3_0_bn_var_1, conv3_0_conv2, conv3_0_bn_gamma_2, conv3_0_bn_beta_2,conv3_0_bn_mean_2,conv3_0_bn_var_2, conv3_0_conv_s, conv3_0_bn_gamma_s, conv3_0_bn_beta_s, conv3_0_bn_mean_s, conv3_0_bn_var_s,
             conv3_1_conv1, conv3_1_bn_gamma_1, conv3_1_bn_beta_1,conv3_1_bn_mean_1,conv3_1_bn_var_1, conv3_1_conv2, conv3_1_bn_gamma_2, conv3_1_bn_beta_2,conv3_1_bn_mean_2,conv3_1_bn_var_2,
             conv4_0_conv1, conv4_0_bn_gamma_1, conv4_0_bn_beta_1,conv4_0_bn_mean_1,conv4_0_bn_var_1, conv4_0_conv2, conv4_0_bn_gamma_2, conv4_0_bn_beta_2,conv4_0_bn_mean_2,conv4_0_bn_var_2, conv4_0_conv_s, conv4_0_bn_gamma_s, conv4_0_bn_beta_s, conv4_0_bn_mean_s, conv4_0_bn_var_s,
             conv4_1_conv1, conv4_1_bn_gamma_1, conv4_1_bn_beta_1,conv4_1_bn_mean_1,conv4_1_bn_var_1, conv4_1_conv2, conv4_1_bn_gamma_2, conv4_1_bn_beta_2,conv4_1_bn_mean_2,conv4_1_bn_var_2,
             conv5_0_conv1, conv5_0_bn_gamma_1, conv5_0_bn_beta_1,conv5_0_bn_mean_1,conv5_0_bn_var_1, conv5_0_conv2, conv5_0_bn_gamma_2, conv5_0_bn_beta_2,conv5_0_bn_mean_2,conv5_0_bn_var_2, conv5_0_conv_s, conv5_0_bn_gamma_s, conv5_0_bn_beta_s, conv5_0_bn_mean_s, conv5_0_bn_var_s,
             conv5_1_conv1, conv5_1_bn_gamma_1, conv5_1_bn_beta_1,conv5_1_bn_mean_1,conv5_1_bn_var_1, conv5_1_conv2, conv5_1_bn_gamma_2, conv5_1_bn_beta_2,conv5_1_bn_mean_2,conv5_1_bn_var_2,
             weight_fc, bias_fc
             ):
    ''' params: basicblock, [2, 2, 2, 2] '''
    conv1 = nn.conv2d_nchw(input_image, weight_conv1,name="conv1_x_0_conv1",padding=[1,1])
    batch_norm1, _, _ = nn.batch_norm(conv1, conv1_gamma_1, conv1_beta_1,conv1_mean_1,conv1_var_1,name="conv1_x_0_bn1")
    _relu = relu(batch_norm1,name="conv1_x_0_relu")

    conv2_x_0 = nn_basicblock(_relu, conv2_0_conv1, conv2_0_bn_gamma_1, conv2_0_bn_beta_1,conv2_0_bn_mean_1,conv2_0_bn_var_1, conv2_0_conv2,
                            conv2_0_bn_gamma_2, conv2_0_bn_beta_2,conv2_0_bn_mean_2,conv2_0_bn_var_2,prefix="conv2_x_0")
    conv2_x_1 = nn_basicblock(conv2_x_0, conv2_1_conv1, conv2_1_bn_gamma_1, conv2_1_bn_beta_1,conv2_1_bn_mean_1,conv2_1_bn_var_1, conv2_1_conv2,
                           conv2_1_bn_gamma_2, conv2_1_bn_beta_2,conv2_1_bn_mean_2,conv2_1_bn_var_2,prefix="conv2_x_1")

    conv3_x_0 = nn_basicblock(conv2_x_1, conv3_0_conv1, conv3_0_bn_gamma_1, conv3_0_bn_beta_1,conv3_0_bn_mean_1,conv3_0_bn_var_1, conv3_0_conv2,
                           conv3_0_bn_gamma_2, conv3_0_bn_beta_2,conv3_0_bn_mean_2,conv3_0_bn_var_2, conv3_0_conv_s, conv3_0_bn_gamma_s, conv3_0_bn_beta_s,conv3_0_bn_mean_s,conv3_0_bn_var_s, stride=2,prefix="conv3_x_0")
    conv3_x_1 = nn_basicblock(conv3_x_0, conv3_1_conv1, conv3_1_bn_gamma_1, conv3_1_bn_beta_1,conv3_1_bn_mean_1,conv3_1_bn_var_1, conv3_1_conv2,
                           conv3_1_bn_gamma_2, conv3_1_bn_beta_2,conv3_1_bn_mean_2,conv3_1_bn_var_2,prefix="conv3_x_1")

    conv4_x_0 = nn_basicblock(conv3_x_1, conv4_0_conv1, conv4_0_bn_gamma_1, conv4_0_bn_beta_1,conv4_0_bn_mean_1,conv4_0_bn_var_1, conv4_0_conv2,
                           conv4_0_bn_gamma_2, conv4_0_bn_beta_2,conv4_0_bn_mean_2,conv4_0_bn_var_2, conv4_0_conv_s, conv4_0_bn_gamma_s, conv4_0_bn_beta_s,conv4_0_bn_mean_s,conv4_0_bn_var_s, stride=2,prefix="conv4_x_0")
    conv4_x_1 = nn_basicblock(conv4_x_0, conv4_1_conv1, conv4_1_bn_gamma_1, conv4_1_bn_beta_1,conv4_1_bn_mean_1,conv4_1_bn_var_1, conv4_1_conv2,
                           conv4_1_bn_gamma_2, conv4_1_bn_beta_2,conv4_1_bn_mean_2,conv4_1_bn_var_2, prefix="conv4_x_1")

    conv5_x_0 = nn_basicblock(conv4_x_1, conv5_0_conv1, conv5_0_bn_gamma_1, conv5_0_bn_beta_1,conv5_0_bn_mean_1,conv5_0_bn_var_1, conv5_0_conv2,
                           conv5_0_bn_gamma_2, conv5_0_bn_beta_2,conv5_0_bn_mean_2,conv5_0_bn_var_2, conv5_0_conv_s, conv5_0_bn_gamma_s, conv5_0_bn_beta_s, conv5_0_bn_mean_s, conv5_0_bn_var_s, stride=2,prefix="conv5_x_0")
    conv5_x_1 = nn_basicblock(conv5_x_0, conv5_1_conv1, conv5_1_bn_gamma_1, conv5_1_bn_beta_1,conv5_1_bn_mean_1,conv5_1_bn_var_1, conv5_1_conv2,
                           conv5_1_bn_gamma_2, conv5_1_bn_beta_2,conv5_1_bn_mean_2,conv5_1_bn_var_2, prefix="conv5_x_1")

    avg_pool = nn.avg_pool2d_nchw(conv5_x_1,stride=[1,1],pooling=[conv5_x_1.shape[2],conv5_x_1.shape[3]],padding=[0,0],name="avg")
    avg_view = hcl.compute(
        (avg_pool.shape[0], avg_pool.shape[1]), lambda b, c: avg_pool[b, c, 0, 0],name="avg_view")
    fc = linear(avg_view, weight_fc, bias_fc,name="linear")
    return fc