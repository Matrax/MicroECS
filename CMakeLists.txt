#CMake version
cmake_minimum_required(VERSION 3.20)

# options
option(BUILD_TESTS "Build the tests" OFF)

# Set CMake properties
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# MicroECS variables
set(MICROECS_LIB_NAME "MicroECS")
set(MICROECS_LIB_VERSION 1.0)
set(MICROECS_TESTS "tests/test.cpp")
set(MICROECS_INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")

# Project
project(${MICROECS_LIB_NAME}  
        DESCRIPTION "C++17 ECS library"
        VERSION ${MICROECS_LIB_VERSION} 
        LANGUAGES CXX)

# Add the interface library
add_library(${MICROECS_LIB_NAME} INTERFACE)
target_include_directories(${MICROECS_LIB_NAME} INTERFACE ${MICROECS_INCLUDES_DIR})

# Tests
if(BUILD_TESTS)
        add_executable(microecs_test ${MICROECS_TESTS})
        target_link_libraries(microecs_test ${MICROECS_LIB_NAME})
endif()

