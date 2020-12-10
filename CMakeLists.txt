cmake_minimum_required(VERSION 3.10)
project(MST)

set(CMAKE_CXX_STANDARD 11)

add_executable(MST src/kruskaltest.cpp src/Graph.cpp src/SortingAlgorithms.h src/HelplerFunctions.h src/DisjointSet.cpp)

add_subdirectory(src/tests)
