open_project prj -reset
set_top default_function
add_files resnet18.h
add_files -tb -cflags "/home1/yangqr/Xilinx/Vitis_HLS/2021.2/tps/lnx64/gcc-6.2.0/include/c++/6.2.0" resnet18_test.cpp
open_solution "solution1" -reset
# set_part virtex7

# create_clock -period 13 -name default

config_export -version 2.0.1;

csim_design