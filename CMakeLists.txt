# cmake_minimum_required(VERSION <specify CMake version here>)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(linkedList linkedList.cpp)
add_executable(CPP  main.cpp  kmp.cpp linearlist.cpp)

add_executable(str instr2.cpp)

add_executable(ch ch.cpp)

add_executable(fi fi.cpp)
add_executable(new new.cpp)
