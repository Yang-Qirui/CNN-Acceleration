open_project prj_mlir
set_top top
add_files raw.cpp
open_solution "raw" -reset
set_part virtex7
create_clock -period 13 -name default
config_export -version 2.0.1;
csynth_design
