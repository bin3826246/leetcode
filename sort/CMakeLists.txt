# cmake_minimum_required(VERSION <specify CMake version here>)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(select select_sort.cpp)
add_executable(insertion insertion_sort.cpp)
add_executable(bubble bubble_sort.cpp)
add_executable(shell shell_sort.cpp)