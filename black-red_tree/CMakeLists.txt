cmake_minimum_required(VERSION 3.21)
project(black_red_tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(black_red_tree
        BlackRedTree.cpp
        BlackRedTree.h
        main.cpp
        Node.h)
