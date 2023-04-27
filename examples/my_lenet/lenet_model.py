import heterocl.op.nn as nn
import heterocl as hcl
import sys
import os
root_dir = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.append(root_dir)
from utils.functions import linear, relu, maxpool2d, logsoftmax2d, conv2d_nchw_bias

def conv_layer_0(input, weight_conv, bias_conv, prefix="c0"):
    conv = conv2d_nchw_bias(input, weight_conv, bias_conv, name=f"{prefix}_conv1")
    _relu = relu(conv, name=f"{prefix}_relu1")
    max_pool = maxpool2d(_relu, name=f"{prefix}_maxpool")
    return max_pool


def conv_layer_1(input, weight_conv, bias_conv, prefix="c1"):
    conv = conv2d_nchw_bias(input, weight_conv, bias_conv, name=f"{prefix}_conv1")
    _relu = relu(conv, name=f"{prefix}_relu1")
    return _relu


def fc_layer_0(input, fc_weight, fc_bias, prefix="f0"):
    l = linear(input, fc_weight, fc_bias, f"{prefix}_linear1")
    _relu = relu(l, name=f"{prefix}_relu1")
    return _relu


def fc_layer_1(input, fc_weight, fc_bias, prefix="f1"):
    l = linear(input, fc_weight, fc_bias, f"{prefix}_linear1")
    sm = logsoftmax2d(l, name=f"{prefix}_logsoftmax1")
    return sm

def lenet(input_image, conv1, bias1, conv2_1, bias2_1, conv2_2, bias2_2, conv3, bias3, fc_weight1, fc_bias1, fc_weight2, fc_bias2):
    output = conv_layer_0(input_image, conv1, bias1, prefix="c1")
    c2_1 = conv_layer_0(output, conv2_1, bias2_1, prefix="c2_1")
    c2_2 = conv_layer_0(output, conv2_2, bias2_2, prefix="c2_2")
    out = hcl.compute(c2_1.shape, lambda *s: c2_1[s] + c2_2[s], name="add")
    c3 = conv_layer_1(out, conv3, bias3, prefix="c3")
    c3_view = hcl.compute((c3.shape[0],c3.shape[1]), lambda b, c: c3[b, c, 0, 0],name="c3_view")
    f4 = fc_layer_0(c3_view, fc_weight1, fc_bias1, prefix="f4")
    f5 = fc_layer_1(f4, fc_weight2, fc_bias2, prefix="f5")
    return f5