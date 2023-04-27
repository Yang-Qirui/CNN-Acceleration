open_project prj_mlir_opt
set_top top
add_files buffer.cpp
open_solution "buffer" -reset
set_part virtex7
create_clock -period 13 -name default
config_export -version 2.0.1;
csynth_design
