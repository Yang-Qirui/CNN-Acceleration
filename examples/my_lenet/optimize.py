import heterocl as hcl

def conv_buffer(s:hcl.Schedule, func):
    print("Strating create buffers")

    conv_layers = []

    def create_buffer(input, conv, prefix):
        WB = s.reuse_at(input, s[conv], conv.axis[3], f"{prefix}_window_buffer")
        s.partition(WB, dim=3)
        conv_layers.append(conv.name)

    create_buffer(func.c1_maxpool, func.c2_1_conv1, "c2_1")
    create_buffer(func.c1_maxpool, func.c2_2_conv1, "c2_2")
    create_buffer(func.add, func.c3_conv1, "c3")
    print("Finish create buffers")

    return conv_layers

def function_outline(s:hcl.Schedule,func,aggr_ops):
    print("Starting outline")
    # BUG: 和其他功能同时使用常常会出问题，待解决
    for op, stage in hcl.Stage._mapping:
        if op.name not in aggr_ops:
            s[getattr(func,op.name)].outline()
    print("Finish outline")
    

def array_partition(s:hcl.Schedule, arrays):
    print("Starting array_partition")
    for arr in arrays:
        if len(arr.shape): # An nchw array
            s.partition(arr, dim=3)
            s.partition(arr, dim=4)
    print("Finish array_partition")
    