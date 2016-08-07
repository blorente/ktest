cmake_minimum_required(VERSION 2.8.9)
project(ktest)

# Set an output directory for our binaries
set(BIN_DIR ${ktest}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include)

add_executable(example src/main.cpp src/examples.cpp include/ktest/ktest.cpp)
