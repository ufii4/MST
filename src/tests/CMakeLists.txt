project(unit_tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GraphTests GraphTests.cpp ../Graph.cpp ../Graph.h)

target_link_libraries(GraphTests gtest gtest_main)

add_executable(DisjointSetTests DisjointSetTests.cpp)

target_link_libraries(DisjointSetTests gtest gtest_main)
