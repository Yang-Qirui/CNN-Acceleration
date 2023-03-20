open_project prj_cosim_unroll -reset
set_top default_function
add_files resnet18.cpp -cflags "-O3"
add_files -tb resnet18_test.cpp -cflags "-O3"
# add_files resnet18.cpp -cflags "-O3 -isystem\"/home1/yangqr/Xilinx/Vitis_HLS/2021.2/tps/lnx64/gcc-6.2.0/include/c++/6.2.0/\" -isystem\"/home1/yangqr/Xilinx/Vitis_HLS/2021.2/tps/lnx64/gcc-6.2.0/include/c++/6.2.0/x86_64-pc-linux-gnu/\""
# add_files -tb resnet18_test.cpp -cflags "-O3 -isystem\"/home1/yangqr/Xilinx/Vitis_HLS/2021.2/tps/lnx64/gcc-6.2.0/include/c++/6.2.0/\" -isystem\"/home1/yangqr/Xilinx/Vitis_HLS/2021.2/tps/lnx64/gcc-6.2.0/include/c++/6.2.0/x86_64-pc-linux-gnu/\""
open_solution "solution1" -reset

set_part virtex7

create_clock -period 13 -name default

config_export -version 2.0.1;

# csim_design -O 
csynth_design
cosim_design -disable_depchk -O