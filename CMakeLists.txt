cmake_minimum_required(VERSION 3.24)
project(RationalNumberCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(RationalNumberCalculator src/main.cpp src/rational.cpp inc/rational.h)
