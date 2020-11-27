project(unit_tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GraphTests GraphTests.cpp ../Graph.cpp ../Graph.h ../DisjointSet.cpp ../DisjointSet.h)

target_link_libraries(GraphTests gtest gtest_main)
