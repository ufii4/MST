cmake_minimum_required(VERSION 3.17)
project(MST)

set(CMAKE_CXX_STANDARD 11)

add_executable(MST src/kruskaltest.cpp src/Graph.cpp src/Graph.h src/DisjointSet.cpp src/DisjointSet.h src/SortingAlgorithms.h)

add_subdirectory(src/tests)