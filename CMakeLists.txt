# cmake_minimum_required(VERSION <specify CMake version here>)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(linkedList linkedList.cpp)
add_executable(CPP  main.cpp  kmp.cpp peak.cpp )

add_executable(str instr2.cpp)

add_executable(ch ch.cpp)

add_executable(fi fi.cpp)
add_executable(new new.cpp)
add_executable(detectCapitalUse detectCapitalUse.cpp)
add_executable(addTwoNumbers addTwoNumbers.cpp)

add_executable(lengthOfLongestSubstring lengthOfLongestSubstring.cpp)
add_executable(maxProduct maxProduct.cpp)
add_executable(findMedianSortedArrays findMedianSortedArrays.cpp)