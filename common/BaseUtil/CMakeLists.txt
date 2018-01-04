#minimum version of cmake
cmake_minimum_required(VERSION 2.8)

#project name
project(BaseUtil)

set (LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR/../../libs})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../libs})

include_directories ("${PROJECT_SOURCE_DIR}")

add_library(LinxErrorHelper.lib ${PROJECT_SOURCE_DIR}/LinuxErrorHelper.cpp)
