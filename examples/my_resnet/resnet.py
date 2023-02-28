import heterocl as hcl
from resnet_model import resnet18
from resnet_functions import CIFAR100_TEST_MEAN, CIFAR100_TEST_STD, get_test_dataloader
import torch
import numpy as np

hcl.init(hcl.Float())


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


def gen_weights(in_channel, out_channel, kernel_size, expansion, depth, id, stride):
    conv_weights = []
    for _ in range(depth):
        conv1_weight = hcl.placeholder(
            (out_channel, in_channel, kernel_size, kernel_size), f"conv{id}_weight1")
        bn1_weight = hcl.placeholder((out_channel,), f"bn{id}_weight1")
        bn1_bias = hcl.placeholder((out_channel,), f"bn{id}_bias1")
        conv2_weight = hcl.placeholder(
            (out_channel, out_channel, kernel_size, kernel_size), f"conv{id}_weight2")
        bn2_weight = hcl.placeholder((out_channel,), f"bn{id}_weight2")
        bn2_bias = hcl.placeholder((out_channel,), f"bn{id}_bias2")
        conv3_weight = hcl.placeholder(
            (out_channel, in_channel, 1, 1), f"conv{id}_shortcut_weight")
        bn3_weight = hcl.placeholder(
            (out_channel,), f"bn{id}_shortcut_weight")
        bn3_bias = hcl.placeholder((out_channel,), f"bn{id}_shortcut_bias")

        in_channel = out_channel * expansion
        conv_weights.append([conv1_weight, bn1_weight, bn1_bias,
                             conv2_weight, bn2_weight, bn2_bias, conv3_weight, bn3_weight, bn3_bias])

    return conv_weights


def create_resnet18(batch_size, target, image_size=[32, 32], resnet_scale=18, in_channel=64, kernel_size=3, num_classes=100):
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
    bn1_x_weight = hcl.placeholder((out_channel,), "bn1_weight")
    bn1_x_bias = hcl.placeholder((out_channel,), "bn1_bias")

    conv2_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv2_depth, 2, 1)
    conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2, _, _, _ = conv2_weights[
        0]
    conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2, _, _, _ = conv2_weights[
        1]

    out_channel = 128

    conv3_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv3_depth, 3, 2)
    conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_conv_s, conv3_0_bn_ws, conv3_0_bn_bs = conv3_weights[
        0]
    conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2, _, _, _ = conv3_weights[
        1]

    in_channel = 128
    out_channel = 256

    conv4_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv4_depth, 4, 2)
    conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_conv_s, conv4_0_bn_ws, conv4_0_bn_bs = conv4_weights[
        0]
    conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2, _, _, _ = conv4_weights[
        1]

    in_channel = 256
    out_channel = 512

    conv5_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv5_depth, 5, 2)
    conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_conv_s, conv5_0_bn_ws, conv5_0_bn_bs = conv5_weights[
        0]
    conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2, _, _, _ = conv5_weights[
        1]

    fc_weight = hcl.placeholder((num_classes, out_channel), "fc_weight")
    fc_bias = hcl.placeholder((num_classes,), "fc_bias")

    s = hcl.create_schedule(
        [input_image,
         conv1_x_weight, bn1_x_weight, bn1_x_bias,
         conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2,
         conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2,
         conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_conv_s, conv3_0_bn_ws, conv3_0_bn_bs,
         conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2,
         conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_conv_s, conv4_0_bn_ws, conv4_0_bn_bs,
         conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2,
         conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_conv_s, conv5_0_bn_ws, conv5_0_bn_bs,
         conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2,
         fc_weight, fc_bias
         ],
        resnet18
    )
    return hcl.build(s, target=target)


def linearize_batchnorm(weight, bias, mean, var):
    '''y = \frac{x - \mathrm{E}[x]}{ \sqrt{\mathrm{Var}[x] + \epsilon}} * \gamma + \beta'''
    eps = 1e-5
    denominator = (var + eps).rsqrt()
    linearized_weight = weight * denominator
    linearized_bias = bias - mean * denominator * weight

    return linearized_weight.numpy(), linearized_bias.numpy()


def load_np_params18(pt_name):
    model = torch.load(pt_name, map_location=torch.device('cpu'))

    conv1_x_weight = model['conv1.0.weight'].numpy()
    bn1_x_weight, bn1_x_bias = linearize_batchnorm(
        model['conv1.1.weight'], model['conv1.1.bias'], model['conv1.1.running_mean'], model['conv1.1.running_var'])

    conv2_0_conv1 = model['conv2_x.0.residual_function.0.weight'].numpy()
    conv2_0_bn_w1, conv2_0_bn_b1 = linearize_batchnorm(model['conv2_x.0.residual_function.1.weight'], model['conv2_x.0.residual_function.1.bias'],
                                                       model['conv2_x.0.residual_function.1.running_mean'], model['conv2_x.0.residual_function.1.running_var'])
    conv2_0_conv2 = model['conv2_x.0.residual_function.3.weight'].numpy()
    conv2_0_bn_w2, conv2_0_bn_b2 = linearize_batchnorm(model['conv2_x.0.residual_function.4.weight'], model['conv2_x.0.residual_function.4.bias'],
                                                       model['conv2_x.0.residual_function.4.running_mean'], model['conv2_x.0.residual_function.4.running_var'])
    conv2_1_conv1 = model['conv2_x.1.residual_function.0.weight'].numpy()
    conv2_1_bn_w1, conv2_1_bn_b1 = linearize_batchnorm(model['conv2_x.1.residual_function.1.weight'], model['conv2_x.1.residual_function.1.bias'],
                                                       model['conv2_x.1.residual_function.1.running_mean'], model['conv2_x.1.residual_function.1.running_var'])
    conv2_1_conv2 = model['conv2_x.1.residual_function.3.weight'].numpy()
    conv2_1_bn_w2, conv2_1_bn_b2 = linearize_batchnorm(model['conv2_x.1.residual_function.4.weight'], model['conv2_x.1.residual_function.4.bias'],
                                                       model['conv2_x.1.residual_function.4.running_mean'], model['conv2_x.1.residual_function.4.running_var'])

    conv3_0_conv1 = model['conv3_x.0.residual_function.0.weight'].numpy()
    conv3_0_bn_w1, conv3_0_bn_b1 = linearize_batchnorm(model['conv3_x.0.residual_function.1.weight'], model['conv3_x.0.residual_function.1.bias'],
                                                       model['conv3_x.0.residual_function.1.running_mean'], model['conv3_x.0.residual_function.1.running_var'])
    conv3_0_conv2 = model['conv3_x.0.residual_function.3.weight'].numpy()
    conv3_0_bn_w2, conv3_0_bn_b2 = linearize_batchnorm(model['conv3_x.0.residual_function.4.weight'], model['conv3_x.0.residual_function.4.bias'],
                                                       model['conv3_x.0.residual_function.4.running_mean'], model['conv3_x.0.residual_function.4.running_var'])
    conv3_0_convs = model['conv3_x.0.shortcut.0.weight'].numpy()
    conv3_0_bn_ws, conv3_0_bn_bs = linearize_batchnorm(model['conv3_x.0.shortcut.1.weight'], model['conv3_x.0.shortcut.1.bias'],
                                                       model['conv3_x.0.shortcut.1.running_mean'], model['conv3_x.0.shortcut.1.running_var'])
    conv3_1_conv1 = model['conv3_x.1.residual_function.0.weight'].numpy()
    conv3_1_bn_w1, conv3_1_bn_b1 = linearize_batchnorm(model['conv3_x.1.residual_function.1.weight'], model['conv3_x.1.residual_function.1.bias'],
                                                       model['conv3_x.1.residual_function.1.running_mean'], model['conv3_x.1.residual_function.1.running_var'])
    conv3_1_conv2 = model['conv3_x.1.residual_function.3.weight'].numpy()
    conv3_1_bn_w2, conv3_1_bn_b2 = linearize_batchnorm(model['conv3_x.1.residual_function.4.weight'], model['conv3_x.1.residual_function.4.bias'],
                                                       model['conv3_x.1.residual_function.4.running_mean'], model['conv3_x.1.residual_function.4.running_var'])

    conv4_0_conv1 = model['conv4_x.0.residual_function.0.weight'].numpy()
    conv4_0_bn_w1, conv4_0_bn_b1 = linearize_batchnorm(model['conv4_x.0.residual_function.1.weight'], model['conv4_x.0.residual_function.1.bias'],
                                                       model['conv4_x.0.residual_function.1.running_mean'], model['conv4_x.0.residual_function.1.running_var'])
    conv4_0_conv2 = model['conv4_x.0.residual_function.3.weight'].numpy()
    conv4_0_bn_w2, conv4_0_bn_b2 = linearize_batchnorm(model['conv4_x.0.residual_function.4.weight'], model['conv4_x.0.residual_function.4.bias'],
                                                       model['conv4_x.0.residual_function.4.running_mean'], model['conv4_x.0.residual_function.4.running_var'])
    conv4_0_convs = model['conv4_x.0.shortcut.0.weight'].numpy()
    conv4_0_bn_ws, conv4_0_bn_bs = linearize_batchnorm(model['conv4_x.0.shortcut.1.weight'], model['conv4_x.0.shortcut.1.bias'],
                                                       model['conv4_x.0.shortcut.1.running_mean'], model['conv4_x.0.shortcut.1.running_var'])
    conv4_1_conv1 = model['conv4_x.1.residual_function.0.weight'].numpy()
    conv4_1_bn_w1, conv4_1_bn_b1 = linearize_batchnorm(model['conv4_x.1.residual_function.1.weight'], model['conv4_x.1.residual_function.1.bias'],
                                                       model['conv4_x.1.residual_function.1.running_mean'], model['conv4_x.1.residual_function.1.running_var'])
    conv4_1_conv2 = model['conv4_x.1.residual_function.3.weight'].numpy()
    conv4_1_bn_w2, conv4_1_bn_b2 = linearize_batchnorm(model['conv4_x.1.residual_function.4.weight'], model['conv4_x.1.residual_function.4.bias'],
                                                       model['conv4_x.1.residual_function.4.running_mean'], model['conv4_x.1.residual_function.4.running_var'])

    conv5_0_conv1 = model['conv5_x.0.residual_function.0.weight'].numpy()
    conv5_0_bn_w1, conv5_0_bn_b1 = linearize_batchnorm(model['conv5_x.0.residual_function.1.weight'], model['conv5_x.0.residual_function.1.bias'],
                                                       model['conv5_x.0.residual_function.1.running_mean'], model['conv5_x.0.residual_function.1.running_var'])
    conv5_0_conv2 = model['conv5_x.0.residual_function.3.weight'].numpy()
    conv5_0_bn_w2, conv5_0_bn_b2 = linearize_batchnorm(model['conv5_x.0.residual_function.4.weight'], model['conv5_x.0.residual_function.4.bias'],
                                                       model['conv5_x.0.residual_function.4.running_mean'], model['conv5_x.0.residual_function.4.running_var'])
    conv5_0_convs = model['conv5_x.0.shortcut.0.weight'].numpy()
    conv5_0_bn_ws, conv5_0_bn_bs = linearize_batchnorm(model['conv5_x.0.shortcut.1.weight'], model['conv5_x.0.shortcut.1.bias'],
                                                       model['conv5_x.0.shortcut.1.running_mean'], model['conv5_x.0.shortcut.1.running_var'])
    conv5_1_conv1 = model['conv5_x.1.residual_function.0.weight'].numpy()
    conv5_1_bn_w1, conv5_1_bn_b1 = linearize_batchnorm(model['conv5_x.1.residual_function.1.weight'], model['conv5_x.1.residual_function.1.bias'],
                                                       model['conv5_x.1.residual_function.1.running_mean'], model['conv5_x.1.residual_function.1.running_var'])
    conv5_1_conv2 = model['conv5_x.1.residual_function.3.weight'].numpy()
    conv5_1_bn_w2, conv5_1_bn_b2 = linearize_batchnorm(model['conv5_x.1.residual_function.4.weight'], model['conv5_x.1.residual_function.4.bias'],
                                                       model['conv5_x.1.residual_function.4.running_mean'], model['conv5_x.1.residual_function.4.running_var'])

    fc_weight = model['fc.weight'].numpy()
    fc_bias = model['fc.bias'].numpy()

    return [
        conv1_x_weight, bn1_x_weight, bn1_x_bias,
        conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2,
        conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2,
        conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_convs, conv3_0_bn_ws, conv3_0_bn_bs,
        conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2,
        conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_convs, conv4_0_bn_ws, conv4_0_bn_bs,
        conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2,
        conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_convs, conv5_0_bn_ws, conv5_0_bn_bs,
        conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2,
        fc_weight, fc_bias
    ]


def run(batch_size):
    [
        conv1_x_weight, bn1_x_weight, bn1_x_bias,
        conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2,
        conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2,
        conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_convs, conv3_0_bn_ws, conv3_0_bn_bs,
        conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2,
        conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_convs, conv4_0_bn_ws, conv4_0_bn_bs,
        conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2,
        conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_convs, conv5_0_bn_ws, conv5_0_bn_bs,
        conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2,
        fc_weight, fc_bias
    ] = load_np_params18("../../weights/resnet18/resnet18-199-best.pth")

    hcl_conv1_x_weight = hcl.asarray(conv1_x_weight.astype(float))
    hcl_bn1_x_weight = hcl.asarray(bn1_x_weight.astype(float))
    hcl_bn1_x_bias = hcl.asarray(bn1_x_bias.astype(float))

    hcl_conv2_0_conv1 = hcl.asarray(conv2_0_conv1.astype(float))
    hcl_conv2_0_bn_w1 = hcl.asarray(conv2_0_bn_w1.astype(float))
    hcl_conv2_0_bn_b1 = hcl.asarray(conv2_0_bn_b1.astype(float))
    hcl_conv2_0_conv2 = hcl.asarray(conv2_0_conv2.astype(float))
    hcl_conv2_0_bn_w2 = hcl.asarray(conv2_0_bn_w2.astype(float))
    hcl_conv2_0_bn_b2 = hcl.asarray(conv2_0_bn_b2.astype(float))

    hcl_conv2_1_conv1 = hcl.asarray(conv2_1_conv1.astype(float))
    hcl_conv2_1_bn_w1 = hcl.asarray(conv2_1_bn_w1.astype(float))
    hcl_conv2_1_bn_b1 = hcl.asarray(conv2_1_bn_b1.astype(float))
    hcl_conv2_1_conv2 = hcl.asarray(conv2_1_conv2.astype(float))
    hcl_conv2_1_bn_w2 = hcl.asarray(conv2_1_bn_w2.astype(float))
    hcl_conv2_1_bn_b2 = hcl.asarray(conv2_1_bn_b2.astype(float))

    hcl_conv3_0_conv1 = hcl.asarray(conv3_0_conv1.astype(float))
    hcl_conv3_0_bn_w1 = hcl.asarray(conv3_0_bn_w1.astype(float))
    hcl_conv3_0_bn_b1 = hcl.asarray(conv3_0_bn_b1.astype(float))
    hcl_conv3_0_conv2 = hcl.asarray(conv3_0_conv2.astype(float))
    hcl_conv3_0_bn_w2 = hcl.asarray(conv3_0_bn_w2.astype(float))
    hcl_conv3_0_bn_b2 = hcl.asarray(conv3_0_bn_b2.astype(float))
    hcl_conv3_0_convs = hcl.asarray(conv3_0_convs.astype(float))
    hcl_conv3_0_bn_ws = hcl.asarray(conv3_0_bn_ws.astype(float))
    hcl_conv3_0_bn_bs = hcl.asarray(conv3_0_bn_bs.astype(float))

    hcl_conv3_1_conv1 = hcl.asarray(conv3_1_conv1.astype(float))
    hcl_conv3_1_bn_w1 = hcl.asarray(conv3_1_bn_w1.astype(float))
    hcl_conv3_1_bn_b1 = hcl.asarray(conv3_1_bn_b1.astype(float))
    hcl_conv3_1_conv2 = hcl.asarray(conv3_1_conv2.astype(float))
    hcl_conv3_1_bn_w2 = hcl.asarray(conv3_1_bn_w2.astype(float))
    hcl_conv3_1_bn_b2 = hcl.asarray(conv3_1_bn_b2.astype(float))

    hcl_conv4_0_conv1 = hcl.asarray(conv4_0_conv1.astype(float))
    hcl_conv4_0_bn_w1 = hcl.asarray(conv4_0_bn_w1.astype(float))
    hcl_conv4_0_bn_b1 = hcl.asarray(conv4_0_bn_b1.astype(float))
    hcl_conv4_0_conv2 = hcl.asarray(conv4_0_conv2.astype(float))
    hcl_conv4_0_bn_w2 = hcl.asarray(conv4_0_bn_w2.astype(float))
    hcl_conv4_0_bn_b2 = hcl.asarray(conv4_0_bn_b2.astype(float))
    hcl_conv4_0_convs = hcl.asarray(conv4_0_convs.astype(float))
    hcl_conv4_0_bn_ws = hcl.asarray(conv4_0_bn_ws.astype(float))
    hcl_conv4_0_bn_bs = hcl.asarray(conv4_0_bn_bs.astype(float))

    hcl_conv4_1_conv1 = hcl.asarray(conv4_1_conv1.astype(float))
    hcl_conv4_1_bn_w1 = hcl.asarray(conv4_1_bn_w1.astype(float))
    hcl_conv4_1_bn_b1 = hcl.asarray(conv4_1_bn_b1.astype(float))
    hcl_conv4_1_conv2 = hcl.asarray(conv4_1_conv2.astype(float))
    hcl_conv4_1_bn_w2 = hcl.asarray(conv4_1_bn_w2.astype(float))
    hcl_conv4_1_bn_b2 = hcl.asarray(conv4_1_bn_b2.astype(float))

    hcl_conv5_0_conv1 = hcl.asarray(conv5_0_conv1.astype(float))
    hcl_conv5_0_bn_w1 = hcl.asarray(conv5_0_bn_w1.astype(float))
    hcl_conv5_0_bn_b1 = hcl.asarray(conv5_0_bn_b1.astype(float))
    hcl_conv5_0_conv2 = hcl.asarray(conv5_0_conv2.astype(float))
    hcl_conv5_0_bn_w2 = hcl.asarray(conv5_0_bn_w2.astype(float))
    hcl_conv5_0_bn_b2 = hcl.asarray(conv5_0_bn_b2.astype(float))
    hcl_conv5_0_convs = hcl.asarray(conv5_0_convs.astype(float))
    hcl_conv5_0_bn_ws = hcl.asarray(conv5_0_bn_ws.astype(float))
    hcl_conv5_0_bn_bs = hcl.asarray(conv5_0_bn_bs.astype(float))

    hcl_conv5_1_conv1 = hcl.asarray(conv5_1_conv1.astype(float))
    hcl_conv5_1_bn_w1 = hcl.asarray(conv5_1_bn_w1.astype(float))
    hcl_conv5_1_bn_b1 = hcl.asarray(conv5_1_bn_b1.astype(float))
    hcl_conv5_1_conv2 = hcl.asarray(conv5_1_conv2.astype(float))
    hcl_conv5_1_bn_w2 = hcl.asarray(conv5_1_bn_w2.astype(float))
    hcl_conv5_1_bn_b2 = hcl.asarray(conv5_1_bn_b2.astype(float))

    hcl_fc_weight = hcl.asarray(fc_weight.astype(float))
    hcl_fc_bias = hcl.asarray(fc_bias.astype(float))

    # hcl_conv1_out = hcl.asarray(np.zeros((batch_size, 64, 32, 32)))
    # hcl_conv2_out = hcl.asarray(np.zeros((batch_size, 64, 32, 32)))
    # hcl_conv3_out = hcl.asarray(np.zeros((batch_size, 128, 16, 16)))
    # hcl_conv4_out = hcl.asarray(np.zeros((batch_size, 256, 8, 8)))
    # hcl_conv5_out = hcl.asarray(np.zeros((batch_size, 512, 4, 4)))
    # hcl_avg_out = hcl.asarray(np.zeros((batch_size, 512)))
    hcl_out = hcl.asarray(
        np.zeros((batch_size, 100)).astype(float))

    f = create_resnet18(batch_size, 'llvm')

    cifar100_test_loader = get_test_dataloader(
        CIFAR100_TEST_MEAN, CIFAR100_TEST_STD, num_workers=2, batch_size=batch_size)

    correct_1 = 0.0
    correct_5 = 0.0

    for n_iter, (image, label) in enumerate(cifar100_test_loader):
        if label.shape[0] == batch_size:
            hcl_input = hcl.asarray(image.numpy().astype(float))
            print(f'Iter {n_iter} run started')
            f(
                hcl_input,
                hcl_conv1_x_weight, hcl_bn1_x_weight, hcl_bn1_x_bias,
                hcl_conv2_0_conv1, hcl_conv2_0_bn_w1, hcl_conv2_0_bn_b1, hcl_conv2_0_conv2, hcl_conv2_0_bn_w2, hcl_conv2_0_bn_b2,
                hcl_conv2_1_conv1, hcl_conv2_1_bn_w1, hcl_conv2_1_bn_b1, hcl_conv2_1_conv2, hcl_conv2_1_bn_w2, hcl_conv2_1_bn_b2,
                hcl_conv3_0_conv1, hcl_conv3_0_bn_w1, hcl_conv3_0_bn_b1, hcl_conv3_0_conv2, hcl_conv3_0_bn_w2, hcl_conv3_0_bn_b2, hcl_conv3_0_convs, hcl_conv3_0_bn_ws, hcl_conv3_0_bn_bs,
                hcl_conv3_1_conv1, hcl_conv3_1_bn_w1, hcl_conv3_1_bn_b1, hcl_conv3_1_conv2, hcl_conv3_1_bn_w2, hcl_conv3_1_bn_b2,
                hcl_conv4_0_conv1, hcl_conv4_0_bn_w1, hcl_conv4_0_bn_b1, hcl_conv4_0_conv2, hcl_conv4_0_bn_w2, hcl_conv4_0_bn_b2, hcl_conv4_0_convs, hcl_conv4_0_bn_ws, hcl_conv4_0_bn_bs,
                hcl_conv4_1_conv1, hcl_conv4_1_bn_w1, hcl_conv4_1_bn_b1, hcl_conv4_1_conv2, hcl_conv4_1_bn_w2, hcl_conv4_1_bn_b2,
                hcl_conv5_0_conv1, hcl_conv5_0_bn_w1, hcl_conv5_0_bn_b1, hcl_conv5_0_conv2, hcl_conv5_0_bn_w2, hcl_conv5_0_bn_b2, hcl_conv5_0_convs, hcl_conv5_0_bn_ws, hcl_conv5_0_bn_bs,
                hcl_conv5_1_conv1, hcl_conv5_1_bn_w1, hcl_conv5_1_bn_b1, hcl_conv5_1_conv2, hcl_conv5_1_bn_w2, hcl_conv5_1_bn_b2,
                hcl_fc_weight, hcl_fc_bias,
                hcl_out
            )

            print(f'Iter {n_iter} run finished')
            np_out = hcl_out.asnumpy()
            tensor_out = torch.tensor(np_out)

            # np_conv1 = hcl_conv1_out.asnumpy()
            # tensor_conv1_out = torch.tensor(np_conv1, dtype=torch.float64)
            # np_conv2 = hcl_conv2_out.asnumpy()
            # tensor_conv2_out = torch.tensor(np_conv2, dtype=torch.float64)
            # np_conv3 = hcl_conv3_out.asnumpy()
            # tensor_conv3_out = torch.tensor(np_conv3, dtype=torch.float64)
            # np_conv4 = hcl_conv4_out.asnumpy()
            # tensor_conv4_out = torch.tensor(np_conv4, dtype=torch.float64)
            # np_conv5 = hcl_conv5_out.asnumpy()
            # tensor_conv5_out = torch.tensor(np_conv5, dtype=torch.float64)
            # np_avg = hcl_avg_out.asnumpy()
            # tensor_avg_out = torch.tensor(np_avg, dtype=torch.float64)
            # print(tensor_out)

            _, pred = tensor_out.topk(5, 1, largest=True, sorted=True)
            label = label.view(label.size(0), -1).expand_as(pred)
            # print(pred)
            # return
            correct = pred.eq(label).float()

            # compute top 5
            correct_5 += correct[:, :5].sum()

            # compute top1
            correct_1 += correct[:, :1].sum()

    print("Top 1 err: ", 1 - correct_1 / len(cifar100_test_loader.dataset))
    print("Top 5 err: ", 1 - correct_5 / len(cifar100_test_loader.dataset))


if __name__ == "__main__":
    run(4)
