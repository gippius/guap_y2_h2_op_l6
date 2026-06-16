cmake_minimum_required(VERSION 3.20)

project(op_lab6_stl_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab6_stl_algorithms
    src/main.cpp
)

target_include_directories(lab6_stl_algorithms PRIVATE include)

