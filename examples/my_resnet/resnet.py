import heterocl as hcl
from resnet_model import resnet18


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

    return in_channel, out_channel, conv_weights


def create_resnet(batch_size, target, image_size=[32, 32], resnet_scale=18, in_channel=64, kernel_size=3, num_classes=100):
    '''batch, channel, height, width'''
    image_h, image_w = image_size
    scale = hcl.placeholder((), "scale")
    num_blocks = hcl.placeholder((4), "num_blocks")

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

    in_channel, out_channel, conv2_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv2_depth, 2, 1)
    conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2, conv2_0_conv_s, conv2_0_bn_ws, conv2_0_bn_bs = conv2_weights[
        0]
    conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2, conv2_1_conv_s, conv2_1_bn_ws, conv2_1_bn_bs = conv2_weights[
        1]

    in_channel, out_channel, conv3_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv3_depth, 3, 2)
    conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_conv_s, conv3_0_bn_ws, conv3_0_bn_bs = conv3_weights[
        0]
    conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2, conv3_1_conv_s, conv3_1_bn_ws, conv3_1_bn_bs = conv3_weights[
        1]

    in_channel, out_channel, conv4_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv4_depth, 4, 2)
    conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_conv_s, conv4_0_bn_ws, conv4_0_bn_bs = conv4_weights[
        0]
    conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2, conv4_1_conv_s, conv4_1_bn_ws, conv4_1_bn_bs = conv4_weights[
        1]

    in_channel, out_channel, conv5_weights = gen_weights(
        in_channel, out_channel, kernel_size, expansion, conv5_depth, 5, 2)
    conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_conv_s, conv5_0_bn_ws, conv5_0_bn_bs = conv5_weights[
        0]
    conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2, conv5_1_conv_s, conv5_1_bn_ws, conv5_1_bn_bs = conv5_weights[
        1]

    fc_weight = hcl.placeholder((num_classes, out_channel), "full_connection")

    s = hcl.create_schedule(
        [input_image,
         conv1_x_weight, bn1_x_weight, bn1_x_bias,
         conv2_0_conv1, conv2_0_bn_w1, conv2_0_bn_b1, conv2_0_conv2, conv2_0_bn_w2, conv2_0_bn_b2, conv2_0_conv_s, conv2_0_bn_ws, conv2_0_bn_bs,
         conv2_1_conv1, conv2_1_bn_w1, conv2_1_bn_b1, conv2_1_conv2, conv2_1_bn_w2, conv2_1_bn_b2, conv2_1_conv_s, conv2_1_bn_ws, conv2_1_bn_bs,
         conv3_0_conv1, conv3_0_bn_w1, conv3_0_bn_b1, conv3_0_conv2, conv3_0_bn_w2, conv3_0_bn_b2, conv3_0_conv_s, conv3_0_bn_ws, conv3_0_bn_bs,
         conv3_1_conv1, conv3_1_bn_w1, conv3_1_bn_b1, conv3_1_conv2, conv3_1_bn_w2, conv3_1_bn_b2, conv3_1_conv_s, conv3_1_bn_ws, conv3_1_bn_bs,
         conv4_0_conv1, conv4_0_bn_w1, conv4_0_bn_b1, conv4_0_conv2, conv4_0_bn_w2, conv4_0_bn_b2, conv4_0_conv_s, conv4_0_bn_ws, conv4_0_bn_bs,
         conv4_1_conv1, conv4_1_bn_w1, conv4_1_bn_b1, conv4_1_conv2, conv4_1_bn_w2, conv4_1_bn_b2, conv4_1_conv_s, conv4_1_bn_ws, conv4_1_bn_bs,
         conv5_0_conv1, conv5_0_bn_w1, conv5_0_bn_b1, conv5_0_conv2, conv5_0_bn_w2, conv5_0_bn_b2, conv5_0_conv_s, conv5_0_bn_ws, conv5_0_bn_bs,
         conv5_1_conv1, conv5_1_bn_w1, conv5_1_bn_b1, conv5_1_conv2, conv5_1_bn_w2, conv5_1_bn_b2, conv5_1_conv_s, conv5_1_bn_ws, conv5_1_bn_bs,
         fc_weight
         ],
        resnet18
    )
    return hcl.build(s, target=target)


f = create_resnet(32, 'vhls')
print(f)
