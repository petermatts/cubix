# todo

cmake_minimum_required(VERSION 3.14)
project(Cubix VERSION 1.0 LANGUAGES CXX)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------
# Executable
# ---------------------
add_executable(cubix
    src/cube.cpp
    src/moves.cpp
    src/common.cpp
)

target_include_directories(cubix PRIVATE ${CMAKE_SOURCE_DIR}/src)

# ---------------------
# Google Test Setup
# ---------------------
include(CTest)
enable_testing()
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(cubix_tests
    tests/test_main.cpp
)

target_link_libraries(cubix_tests GTest::gtest_main)
target_include_directories(cubix_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
include(GoogleTest)
gtest_discover_tests(cubix_tests)

# ---------------------
# SWIG + Python Module
# ---------------------
find_package(SWIG REQUIRED)
include(UseSWIG)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
include_directories(${Python3_INCLUDE_DIRS})

set(CMAKE_SWIG_FLAGS "")
set_source_files_properties(interface/cubix.i PROPERTIES CPLUSPLUS ON)
swig_add_library(cubix_python
    TYPE MODULE
    LANGUAGE python
    SOURCES interface/cubix.i
            src/cube.cpp
            src/moves.cpp
            src/common.cpp
)

target_include_directories(cubix_python PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(cubix_python ${Python3_LIBRARIES})