###############################################################################
# imports
###############################################################################

import heterocl as hcl
import heterocl.tvm as tvm
from collections import OrderedDict
import numpy as np
from torch.utils.data import DataLoader
import torchvision
import torchvision.transforms as transforms

CIFAR100_TEST_MEAN = (0.5088964127604166,
                      0.48739301317401956, 0.44194221124387256)
CIFAR100_TEST_STD = (0.2682515741720801,
                     0.2573637364478126, 0.2770957707973042)

###############################################################################
# helper functions
###############################################################################


def simplify(expr):
    return tvm.ir_pass.Simplify(expr) if isinstance(expr, tvm.expr.Expr) else expr


def get_pad_tuple(padding, kernel):
    pad_h = pad_w = padding * 2
    pad_top = ((pad_h + 1) // 2)
    pad_left = ((pad_w + 1) // 2)
    return pad_top, pad_left, pad_h - pad_top, pad_w - pad_left


def pad(data, pad_before, pad_after=None, pad_value=0.0, name="pad"):
    n = len(data.shape)
    pad_after = pad_after if pad_after else pad_before
    if len(pad_before) != n:
        raise ValueError(
            "Input dimension and pad_before dismatch : %d vs %d" %
            (n, len(pad_before)))
    if len(pad_after) != n:
        raise ValueError(
            "Input dimension and pad_after dismatch : %d vs %d" %
            (n, len(pad_after)))
    out_shape = tuple(
        tvm.ir_pass.Simplify(
            (data.shape[i] + tvm.const(pad_before[i] + pad_after[i]))
        ) for i in range(n))
    pad_value = pad_value if isinstance(
        pad_value, tvm.expr.Expr) else tvm.const(pad_value, data.dtype)

    def _pad(*indices):
        not_zero = []
        index_tuple = []
        for i in range(n):
            if pad_before[i] == 0 and pad_after[i] == 0:
                index_tuple.append(indices[i])
            else:
                index_tuple.append(indices[i] - pad_before[i])
                not_zero.append(indices[i] >= pad_before[i])
                not_zero.append(indices[i] < data.shape[i] + pad_before[i])
        if not_zero:
            not_zero = tvm.all(*not_zero)
            return tvm.select(not_zero, data[tuple(index_tuple)], pad_value)
        return data[tuple(index_tuple)]

    # Use this for CPU backend
    # return hcl.compute(out_shape, _pad, name=name)
    # Use this for HLS backend
    return hcl.compute(out_shape, _pad, dtype=data.dtype, name=name)


###############################################################################
# conv2d computation layer
# this function is the heteroCL equivalent of the torch.nn.Conv2d function
# in the PyTorch library.
###############################################################################
def conv2d(Input, Filter, name="conv2d", stride=[1, 1], padding=[[1, 1], [1, 1]], out_dtype=hcl.Float(), print_out=False):
    batch, in_channel, in_height, in_width = Input.shape
    num_filter, channel, kernel_h, kernel_w = Filter.shape
    stride_h, stride_w = stride
    [pad_top, pad_left], [pad_down, pad_right] = padding
    # compute the output shape
    out_channel = num_filter
    out_height = simplify(
        (in_height - kernel_h + pad_top + pad_down) // stride_h + 1)
    out_width = simplify(
        (in_width - kernel_w + pad_left + pad_right) // stride_w + 1)
    # compute graph
    pad_before = [0, 0, pad_top, pad_left]
    pad_after = [0, 0, pad_down, pad_right]
    if padding != [[0, 0], [0, 0]]:
        Input = pad(Input, pad_before, pad_after, name=name+"_pad")
    rc = hcl.reduce_axis(0, in_channel)
    ry = hcl.reduce_axis(0, kernel_h)
    rx = hcl.reduce_axis(0, kernel_w)

    return hcl.compute(
        (batch, out_channel, out_height, out_width),
        lambda nn, ff, yy, xx: hcl.sum(
            Input[nn, rc, yy * stride_h + ry, xx * stride_w + rx] *
            Filter[ff, rc, ry, rx],
            axis=[rc, ry, rx],
            dtype=out_dtype),
        name=name,
        attrs=OrderedDict([
            ('p', kernel_h),
            ('q', kernel_w),
            ('in_num', in_channel),
            ('out_num', out_channel),
            ('out_img_w', out_width),
            ('out_img_h', out_height),
            ('cin_dtype', tvm.make.StringImm(Input.dtype)),
            ('filter_dtype', tvm.make.StringImm(Filter.dtype)),
            ('app_name', tvm.make.StringImm('cnn'))]))


def relu(data, name='relu'):
    # CPU Backend
    # x1 = hcl.compute(data.shape, lambda *y: hcl.select(
    #     data[y] < 0, hcl.cast(data.dtype, 0), data[y]), name=name+'_x1')
    # x2 = hcl.compute(
    #     x1.shape, lambda *y: hcl.select(x1[y] > 1, hcl.cast(data.dtype, 1), x1[y]), name=name)
    # return x2
    # HLS Backend
    return hcl.compute(data.shape, lambda *y:
                       hcl.select(data[y] <= 0,
                                  0, data[y]),
                       name=name, dtype=data.dtype)


def linear(data, weight, bias, name='linear'):
    batch, in_feature = data.shape
    out_feature, w = weight.shape  # h=100, w=512
    weight_T = hcl.compute((w, out_feature), lambda x, y: weight[y, x])
    # with hcl.for_(0, h) as i:
    #     with hcl.for_(0, w) as j:
    #         weight_T[j, i] = weight[i, j]
    # kernel_h, out_feature = weight_T.shape
    out = hcl.placeholder((batch, out_feature), name=name)
    with hcl.for_(0, batch) as i:
        with hcl.for_(0, out_feature) as k:
            with hcl.for_(0, w) as j:
                out[i, k] = data[i, j] * weight_T[j, k] + out[i, k]
            out[i, k] = out[i, k] + bias[k]

    return out
    # batch, in_feature = data.shape
    # h, w = weight.shape
    # weight_transpose = hcl.compute(
    #     (weight.shape[1], weight.shape[0]), lambda x, y: weight[y, x])
    # _, out_feature = w, h
    # din_feature = hcl.reduce_axis(0, in_feature)
    # return hcl.compute((batch, out_feature), lambda x, y: hcl.sum(
    #     data[x, din_feature] * weight_transpose[din_feature, x], axis=[din_feature]
    # ) + bias[y], name=name, dtype=data.dtype)


def avgpool2d(data, stride=1, name='avg_pool2d'):
    batch, channel, height, width = data.shape
    avg = hcl.reducer(
        0,
        lambda x, y: x / (width * height) + y,
        data.dtype)
    pooling_h = height
    pooling_w = width
    dheight = hcl.reduce_axis(0, pooling_h)
    dwidth = hcl.reduce_axis(0, pooling_w)
    return hcl.compute(
        (batch, channel, 1, 1),
        lambda i, c, h, w: avg(data[i, c, h +
                                    dheight, w +
                                    dwidth], axis=[dheight, dwidth]),
        name=name, dtype=data.dtype,
    )


###############################################################################
# MaxPool2d computation layer
# this function is the heteroCL equivalent of the torch.nn.MaxPool2d function
# in the PyTorch library.
###############################################################################


def maxpool2d(data, pool_size=2, stride=2, padding=0, name='max_pool2d'):
    pooling = pool_size
    max = hcl.reducer(
        0,
        lambda x, y: tvm.make.Max(x, y),
        data.dtype)
    pooling_h = pooling_w = pooling
    stride_h = stride_w = stride
    batch, channel, height, width = data.shape
    pad_top = pad_left = pad_bottom = pad_right = padding

    pad_before = [0, 0, pad_top, pad_left]
    pad_after = [0, 0, pad_bottom, pad_right]

    # HLS backend: comment out
    data = pad(data, pad_before, pad_after, pad_value=0, name=name+"_pad")
    out_height = simplify(
        (height - pooling_h + pad_top + pad_bottom) // stride_h + 1)
    out_width = simplify(
        (width - pooling_w + pad_left + pad_right) // stride_w + 1)
    dheight = hcl.reduce_axis(0, pooling_h)
    dwidth = hcl.reduce_axis(0, pooling_w)
    return hcl.compute(
        (batch, channel, out_height, out_width),
        lambda i, c, h, w: max(data[i, c, h *
                                    stride_h +
                                    dheight, w *
                                    stride_w +
                                    dwidth], axis=[dheight, dwidth]),
        name=name, dtype=data.dtype,
        attrs=OrderedDict([
            ('out_img_w', out_width),
            ('out_img_h', out_height),
            ('in_num', channel),
            ('kernel_h', pooling),
            ('kernel_w', pooling),
            ('stride_h', stride),
            ('stride_w', stride),
            ('app_name', tvm.make.StringImm('max_pool'))]))

# batch normalization


def batchnorm2d(data, a, b, name="batch_norm", out_dtype=hcl.Float()):
    out = hcl.compute(data.shape, lambda i, c, h, w: a[c]
                      * data[i, c, h, w] + b[c], dtype=out_dtype, name=name)
    # observe = hcl.compute((data.shape[-1], ), lambda x : out[0, 0, 0, x], name="observe")
    # data_val = hcl.compute((data.shape[-1], ), lambda x : data[0, 0, 0, x], name="data_val")
    # if print_out:
    # hcl.print(data_val)
    # hcl.print(observe)
    return out

# def batchnorm2d(data, a, b, axis=1, name="batch_norm", out_dtype=hcl.Float(), print_out=False):
#     def get_axis(axis, *indices):
#         indices = list(indices[0])
#         return (indices[axis],)

#     out = hcl.compute(data.shape, lambda *x: a[get_axis(axis, x)]
#                       * data[x] + b[get_axis(axis, x)], dtype=out_dtype, name=name)
#     # observe = hcl.compute((data.shape[-1], ), lambda x : out[0, 0, 0, x], name="observe")
#     # data_val = hcl.compute((data.shape[-1], ), lambda x : data[0, 0, 0, x], name="data_val")
#     # if print_out:
#     # hcl.print(data_val)
#     # hcl.print(observe)
#     return out


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
