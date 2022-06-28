# Main CMake file

cmake_minimum_required(VERSION 3.20)

project(side-process-manager)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(src)
