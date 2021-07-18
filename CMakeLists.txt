cmake_minimum_required(VERSION 3.19)
project(Tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tree cmake-build-debug/Testing/stack.h cmake-build-debug/Testing/main.cpp cmake-build-debug/Testing/stack.cpp)