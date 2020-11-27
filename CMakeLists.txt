cmake_minimum_required(VERSION 3.17)
project(MST)

set(CMAKE_CXX_STANDARD 11)

add_executable(MST src/main.cpp)

add_subdirectory(src/tests)