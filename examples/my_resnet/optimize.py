import heterocl as hcl

FIFO_DEPTH = 128

# Batchnorm + relu
def loop_aggregation(s:hcl.Schedule,func):
    print("Starting loop_aggregate")
    bn = getattr(func,f"conv1_x_0_bn1")
    relu = getattr(func,f"conv1_x_0_relu")
    s[bn].compute_at(s[relu],axis=relu.axis[-1])
    aggr_ops = [bn]
    for block in range(2,6): # 5 layers
        for i in range(2): # each layer have 2 basic blocks
            '''
                for resnet's basic block, thers's two relu layers. 
            '''
            prefix = f"conv{block}_x_{i}"
            bn1 = getattr(func,f"{prefix}_bn1")
            relu1 = getattr(func,f"{prefix}_relu1")
            s[bn1].compute_at(s[relu1],axis=relu1.axis[-1])
            bn2 = getattr(func,f"{prefix}_bn2")
            addition = getattr(func,f"{prefix}_add")
            relu2 = getattr(func,f"{prefix}_relu2")
            s[bn2].compute_at(s[relu2],axis=relu2.axis[-1])
            s[addition].compute_at(s[relu2],axis=relu2.axis[-1])
            aggr_ops += [bn1,bn2,addition]


    print("Finish loop_aggregate")

    return [op.name for op in aggr_ops]


def function_outline(s:hcl.Schedule,func,aggr_ops):
    # BUG: 和其他功能同时使用常常会出问题，待解决
    for op, stage in hcl.Stage._mapping:
        if op.name not in aggr_ops:
            s[getattr(func,op.name)].outline()


def fifo(s:hcl.Schedule,func,aggr_ops):
    # BUG: 暂时别用。一个stage没法同时接受fifo并输出fifo
    '''
    ['conv1_x_0_conv1_pad', 'conv1_x_0_conv1', 'conv1_x_0_relu', 'conv2_x_0_conv1_pad', 'conv2_x_0_conv1', 'conv2_x_0_relu1', 'conv2_x_0_conv2_pad', 'conv2_x_0_conv2', 'conv2_x_0_relu2', 'conv2_x_1_conv1_pad', 'conv2_x_1_conv1', 'conv2_x_1_relu1', 'conv2_x_1_conv2_pad', 'conv2_x_1_conv2', 'conv2_x_1_relu2', 'conv3_x_0_conv1_pad', 'conv3_x_0_conv1', 'conv3_x_0_relu1', 'conv3_x_0_conv2_pad', 'conv3_x_0_conv2', 'conv3_x_0_convs', 'conv3_x_0_bns', 'conv3_x_0_relu2', 'conv3_x_1_conv1_pad', 'conv3_x_1_conv1', 'conv3_x_1_relu1', 'conv3_x_1_conv2_pad', 'conv3_x_1_conv2', 'conv3_x_1_relu2', 'conv4_x_0_conv1_pad', 'conv4_x_0_conv1', 'conv4_x_0_relu1', 'conv4_x_0_conv2_pad', 'conv4_x_0_conv2', 'conv4_x_0_convs', 'conv4_x_0_bns', 'conv4_x_0_relu2', 'conv4_x_1_conv1_pad', 'conv4_x_1_conv1', 'conv4_x_1_relu1', 'conv4_x_1_conv2_pad', 'conv4_x_1_conv2', 'conv4_x_1_relu2', 'conv5_x_0_conv1_pad', 'conv5_x_0_conv1', 'conv5_x_0_relu1', 'conv5_x_0_conv2_pad', 'conv5_x_0_conv2', 'conv5_x_0_convs', 'conv5_x_0_bns', 'conv5_x_0_relu2', 'conv5_x_1_conv1_pad', 'conv5_x_1_conv1', 'conv5_x_1_relu1', 'conv5_x_1_conv2_pad', 'conv5_x_1_conv2', 'conv5_x_1_relu2', 'avg', 'avg_view', 'linear']
    '''
    # conv = getattr(func, "conv1_x_0_conv1")
    # print(conv.axis)
    # assert 0 == 1
    # s.to(func.input_image, s[func.conv1_x_0_conv1_pad], fifo_depth=FIFO_DEPTH)
    s.to(func.conv1_x_0_conv1, s[func.conv1_x_0_relu])
    s.to(func.conv1_x_0_relu, s[func.conv2_x_0_conv1_pad], fifo_depth=FIFO_DEPTH)
    # s.to(func.conv2_x_0_conv1, s[func.conv2_x_0_relu1], fifo_depth=FIFO_DEPTH)

    # stages = [(op, stage) for (op, stage) in hcl.Stage._mapping if stage.name not in aggr_ops]
    # for id, (op, stage) in enumerate(stages[:3]):
        # if id < len(stages) - 1 and op.name[-3:] != "pad": # BUG: cannot add fifo between padding and conv
            # print(op.name, op.name[-3:])
            # next_op, next_stage = stages[id + 1]
            # s.to(getattr(func, op.name), s[getattr(func, next_op.name)], fifo_depth=FIFO_DEPTH)

def conv_buffer(s:hcl.Schedule,func):
    print("Starting create buffers")
    conv_layers = []

    def create_buffer_pad(prefix,idx):
        conv_pad = getattr(func, f"{prefix}_conv{idx}_pad")
        conv = getattr(func, f"{prefix}_conv{idx}")
        LB = s.reuse_at(conv_pad, s[conv], conv.axis[2], f"{prefix}_line_buffer{idx}")
        WB = s.reuse_at(LB, s[conv], conv.axis[3], f"{prefix}_window_buffer{idx}")
        s.partition(LB, dim=2)
        s.partition(WB, dim=3)
        conv_layers.append(conv.name)
    print("Finish create buffers")
    
    create_buffer_pad(prefix="conv1_x_0", idx="1")
    for block in range(2, 6): # 5 layers
        for i in range(2): # each layer have 2 basic blocks
            prefix = f"conv{block}_x_{i}"
            create_buffer_pad(prefix=prefix,idx="1")
            create_buffer_pad(prefix=prefix,idx="2")

    return conv_layers

def array_partition(s:hcl.Schedule, arrays):
    print("Starting array_partition")
    for arr in arrays:
        if len(arr.shape): # An nchw array
            s.partition(arr, dim=3)
            s.partition(arr, dim=4)
    print("Finish array_partition")
        

def pipeline(s:hcl.Schedule, func, conv_layers):
    print("Starting pipeline")
    # stages = [(op, stage) for (op, stage) in hcl.Stage._mapping if stage.name not in aggr_ops]
    conv_stages = [(op, stage) for (op, stage) in hcl.Stage._mapping if stage.name in conv_layers]
    for op, stage in conv_stages:
        # print(op.name)
        # print(stage.axis)
        # print(dir(stage.axis[0]))
        ff_id = next(i for i, s in enumerate(stage.axis) if s.name.startswith('ff'))
        xx_id = next(i for i, s in enumerate(stage.axis) if s.name.startswith('xx'))
        s[getattr(func, op.name)].reorder(stage.axis[ff_id], stage.axis[xx_id])
        # print(ff_id)
        # s[getattr(func, op.name)].pipeline(ff_id)
    print("Finish pipeline")
    
