cmake_minimum_required(VERSION 3.25)
project(HelloC__)

set(CMAKE_CXX_STANDARD 23)

add_executable(HelloC__ main.cpp seq_list_demo.h seq_list_demo.cpp algorithm/kmp.cpp algorithm/kmp.h
        algorithm/matrix_multiply_demo.h algorithm/matrix_multiply_demo.cpp
        demo.cpp
        demo.h)
