cmake_minimum_required(VERSION 3.10)
project(AoC_02)
set(CMAKE_CXX_STANDARD 17)

# Set target names
set(BIN_TARGET ${CMAKE_PROJECT_NAME}_bin)

# Add include dir
include_directories(../common/include/)

# Add bin targets
add_executable(${BIN_TARGET}_1 main_part1.cpp)
add_executable(${BIN_TARGET}_2 main_part2.cpp)
