cmake_minimum_required(VERSION 3.31)
project(NN)

set(CMAKE_CXX_STANDARD 20)

add_executable(NN main.cpp
        matops.hpp
        layer.h)
