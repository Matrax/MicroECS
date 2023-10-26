#CMake version
cmake_minimum_required(VERSION 3.20)

# options
option(BUILD_TESTS "Build the tests" OFF)

# Project
project(MicroECS 
        DESCRIPTION "C++17 ECS library"
        VERSION 1.0
        LANGUAGES CXX)

# Add the interface library
add_library(MicroECS INTERFACE)

# C++ properties
target_compile_features(MicroECS INTERFACE cxx_std_17)

# include directories
target_include_directories(MicroECS INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/includes")

# Tests
if(BUILD_TESTS)
        add_executable(microecs_test "tests/test.cpp")
        target_link_libraries(microecs_test MicroECS)
endif()