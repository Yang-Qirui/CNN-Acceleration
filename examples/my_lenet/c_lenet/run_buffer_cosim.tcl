open_project prj_mlir_opt -reset
set_top top
add_files buffer.cpp
add_files -tb lenet_tb.cpp
open_solution "buffer" -reset
set_part virtex7
create_clock -period 13 -name default
config_export -version 2.0.1;
csim_design
csynth_design
cosim_design
export_design -flow impl -rtl Verilog
