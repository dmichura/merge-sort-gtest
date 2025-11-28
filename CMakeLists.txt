cmake_minimum_required(VERSION 3.14)
project(MergeSortProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(MergeSortApp src/main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(runTests tests/test_mergesort.cpp)
target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)