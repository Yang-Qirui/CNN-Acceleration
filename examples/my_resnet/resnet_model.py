import heterocl as hcl

from resnet_functions import conv2d, batchnorm2d, relu, avgpool2d, linear

###############################################################################
# BasicBlock for ResNet
###############################################################################


def basicblock(input,
               weight_conv1, a_batch_norm1, b_batch_norm1, weight_conv2, a_batch_norm2, b_batch_norm2, weight_conv_shortcut=None, a_batch_norm_shortcut=None, b_batch_norm_shortcut=None,
               stride=1):
    # print(weight_conv1.shape, a_batch_norm1.shape, b_batch_norm1.shape,
    #       weight_conv2.shape, a_batch_norm2.shape, b_batch_norm2.shape)
    # if weight_conv_shortcut != None:
    #     print(weight_conv_shortcut.shape, a_batch_norm_shortcut.shape,
    #           b_batch_norm_shortcut.shape)
    expansion = 1
    batch, in_channels, in_height, in_width = input.shape
    out_channels, channel, kernel_h, kernel_w = weight_conv1.shape
    conv1 = conv2d(input, weight_conv1, name="basicblock_conv1",
                   stride=[stride, stride])
    batch_norm1 = batchnorm2d(
        conv1, a_batch_norm1, b_batch_norm1, name="basicblock_bn1")
    _relu = relu(batch_norm1, name='basicblock_relu')
    conv2 = conv2d(_relu, weight_conv2, name="basicblock_conv2")
    batch_norm2 = batchnorm2d(conv2, a_batch_norm2,
                              b_batch_norm2, name="basicblock_bn2")
    if stride != 1 or in_channels != expansion * out_channels:
        shortcut = conv2d(input, weight_conv_shortcut,
                          name="basicblock_conv_shortcut", stride=[stride, stride], padding=[[0, 0], [0, 0]])
        identity = batchnorm2d(shortcut, a_batch_norm_shortcut,
                               b_batch_norm_shortcut, name="basicblock_bn_shortcut")
    else:
        identity = input
    addition = hcl.compute(
        identity.shape, lambda *x: batch_norm2[x] + identity[x])
    out = relu(addition, name='bb_output_relu')
    return out

###############################################################################
# BottleNeck for ResNet
###############################################################################


def bottleneck(input,
               weights,
               name="bottleneck", stride=1
               ):
    expansion = 4
    weight_conv1, a_batch_norm1, b_batch_norm1, weight_conv2, a_batch_norm2, b_batch_norm2, weight_conv3, a_batch_norm3, b_batch_norm3, weight_conv_shortcut, a_batch_norm_shortcut, b_batch_norm_shortcut = weights
    batch, in_channels, in_height, in_width = input.shape
    out_channels, channel, kernel_h, kernel_w = weight_conv1.shape
    identity = input
    conv1 = conv2d(input, weight_conv1, name="bottleneck_conv1")
    batch_norm1 = batchnorm2d(conv1, a_batch_norm1,
                              b_batch_norm1, name="bottleneck_bn1")
    _relu1 = relu(batch_norm1, name="bottleneck_relu1")
    conv2 = conv2d(_relu1, weight_conv2, name="bottleneck_conv2",
                   stride=[stride, stride])
    batch_norm2 = batchnorm2d(conv2, a_batch_norm2,
                              b_batch_norm2, name="bottleneck_bn2")
    _relu2 = relu(batch_norm2, name="bottleneck_relu2")
    conv3 = conv2d(_relu2, weight_conv3, name="bottleneck_conv3")
    batch_norm3 = batchnorm2d(conv3, a_batch_norm3,
                              b_batch_norm3, name="bottleneck_bn3")
    if stride != 1 or in_channels != out_channels * expansion:
        identity = conv2d(identity, weight_conv_shortcut,
                          name="bottleneck_conv_shortcut", stride=[stride, stride])
        identity = batchnorm2d(identity, a_batch_norm_shortcut,
                               b_batch_norm_shortcut, name="bottleneck_bn_shortcut")

    out = batch_norm3 + identity
    out = relu(out, name="bn_output_relu")

    return out


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
            input = basicblock(input, weights[i], stride=stride)
        elif type == 1:  # 1 is bottleneck
            input = bottleneck(input, weights[i], stride=stride)

    return input


def _resnet(input_image, block, num_block,
            weight_conv1, a_batchnorm1, b_batchnorm1,
            weights_conv2_x, weights_conv3_x, weights_conv4_x, weights_conv5_x,
            weight_fc
            ):

    conv1 = conv2d(input_image, weight_conv1,)
    batch_norm1 = batchnorm2d(conv1, a_batchnorm1, b_batchnorm1)
    _relu = relu(batch_norm1)
    print("conv1_finished")

    conv2_x = make_layer(_relu, num_block[0], 1, weights_conv2_x, block)
    conv3_x = make_layer(conv2_x, num_block[1], 2, weights_conv3_x, block)
    conv4_x = make_layer(conv3_x, num_block[2], 2, weights_conv4_x, block)
    conv5_x = make_layer(conv4_x, num_block[3], 2, weights_conv5_x, block)
    avg_pool = avgpool2d(conv5_x)
    avg_view = hcl.compute(
        (avg_pool.shape[0], avg_pool.shape[1]), lambda i, c: avg_pool[i, c, 0, 0])
    fc = linear(avg_view, weight_fc)

    return fc


def resnet18(input_image,
             weight_conv1, a_batchnorm1, b_batchnorm1,
             conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2,
             conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2,
             conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_conv_s, conv3_0_bn_ws, conv3_0_bn_bs,
             conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2,
             conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_conv_s, conv4_0_bn_ws, conv4_0_bn_bs,
             conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2,
             conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_conv_s, conv5_0_bn_ws, conv5_0_bn_bs,
             conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2,
             weight_fc, bias_fc
             ):
    ''' params: basicblock, [2, 2, 2, 2] '''
    conv1 = conv2d(input_image, weight_conv1)
    batch_norm1 = batchnorm2d(conv1, a_batchnorm1, b_batchnorm1)
    _relu = relu(batch_norm1)

    conv2_x_0 = basicblock(_relu, conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2,
                           conv2_0_bn_w2, conv2_0_bn_b2)
    conv2_x_1 = basicblock(conv2_x_0, conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2,
                           conv2_1_bn_w2, conv2_1_bn_b2)

    conv3_x_0 = basicblock(conv2_x_1, conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2,
                           conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_conv_s, conv3_0_bn_ws, conv3_0_bn_bs, stride=2)
    conv3_x_1 = basicblock(conv3_x_0, conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2,
                           conv3_1_bn_w2, conv3_1_bn_b2)

    conv4_x_0 = basicblock(conv3_x_1, conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2,
                           conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_conv_s, conv4_0_bn_ws, conv4_0_bn_bs, stride=2)
    conv4_x_1 = basicblock(conv4_x_0, conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2,
                           conv4_1_bn_w2, conv4_1_bn_b2)

    conv5_x_0 = basicblock(conv4_x_1, conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2,
                           conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_conv_s, conv5_0_bn_ws, conv5_0_bn_bs, stride=2)
    conv5_x_1 = basicblock(conv5_x_0, conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2,
                           conv5_1_bn_w2, conv5_1_bn_b2)

    avg_pool = avgpool2d(conv5_x_1)
    avg_view = hcl.compute(
        (avg_pool.shape[0], avg_pool.shape[1]), lambda b, c: avg_pool[b, c, 0, 0])
    fc = linear(avg_view, weight_fc, bias_fc)

    return fc
