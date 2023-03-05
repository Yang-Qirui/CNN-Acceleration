set(CMAKE_PREFIX_PATH "~/libtorch;~/torchvision")

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(c_resnet)
 
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
find_package(TorchVision REQUIRED)


add_executable(resnet18_test resnet18_test.cpp)
target_link_libraries(resnet18_test PUBLIC "${TORCH_LIBRARIES}" TorchVision::TorchVision)
set_property(TARGET resnet18_test PROPERTY CXX_STANDARD 17)