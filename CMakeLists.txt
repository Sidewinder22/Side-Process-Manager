# Main CMake file

cmake_minimum_required(VERSION 3.20)

project(side-process-manager)

# C++20 for constexpr std::array initialization
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(src)
