# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/heterocl/examples/my_resnet/c_resnet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/heterocl/examples/my_resnet/c_resnet

# Include any dependencies generated for this target.
include CMakeFiles/resnet18_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/resnet18_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/resnet18_test.dir/flags.make

CMakeFiles/resnet18_test.dir/resnet18_test.cpp.o: CMakeFiles/resnet18_test.dir/flags.make
CMakeFiles/resnet18_test.dir/resnet18_test.cpp.o: resnet18_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/heterocl/examples/my_resnet/c_resnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/resnet18_test.dir/resnet18_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/resnet18_test.dir/resnet18_test.cpp.o -c /home/ubuntu/heterocl/examples/my_resnet/c_resnet/resnet18_test.cpp

CMakeFiles/resnet18_test.dir/resnet18_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/resnet18_test.dir/resnet18_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/heterocl/examples/my_resnet/c_resnet/resnet18_test.cpp > CMakeFiles/resnet18_test.dir/resnet18_test.cpp.i

CMakeFiles/resnet18_test.dir/resnet18_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/resnet18_test.dir/resnet18_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/heterocl/examples/my_resnet/c_resnet/resnet18_test.cpp -o CMakeFiles/resnet18_test.dir/resnet18_test.cpp.s

# Object files for target resnet18_test
resnet18_test_OBJECTS = \
"CMakeFiles/resnet18_test.dir/resnet18_test.cpp.o"

# External object files for target resnet18_test
resnet18_test_EXTERNAL_OBJECTS =

resnet18_test: CMakeFiles/resnet18_test.dir/resnet18_test.cpp.o
resnet18_test: CMakeFiles/resnet18_test.dir/build.make
resnet18_test: /home/ubuntu/libtorch/lib/libc10.so
resnet18_test: /home/ubuntu/libtorch/lib/libkineto.a
resnet18_test: /home/ubuntu/torchvision/lib/libtorchvision.so
resnet18_test: /home/ubuntu/libtorch/lib/libtorch.so
resnet18_test: /home/ubuntu/libtorch/lib/libc10.so
resnet18_test: /usr/local/lib/libpng.so
resnet18_test: /usr/lib/x86_64-linux-gnu/libjpeg.so
resnet18_test: CMakeFiles/resnet18_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/heterocl/examples/my_resnet/c_resnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable resnet18_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/resnet18_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/resnet18_test.dir/build: resnet18_test

.PHONY : CMakeFiles/resnet18_test.dir/build

CMakeFiles/resnet18_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/resnet18_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/resnet18_test.dir/clean

CMakeFiles/resnet18_test.dir/depend:
	cd /home/ubuntu/heterocl/examples/my_resnet/c_resnet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/heterocl/examples/my_resnet/c_resnet /home/ubuntu/heterocl/examples/my_resnet/c_resnet /home/ubuntu/heterocl/examples/my_resnet/c_resnet /home/ubuntu/heterocl/examples/my_resnet/c_resnet /home/ubuntu/heterocl/examples/my_resnet/c_resnet/CMakeFiles/resnet18_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/resnet18_test.dir/depend

