#CMake version
cmake_minimum_required(VERSION 3.20)

# Set CMake property
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# MicroECS variables
set(LIB_NAME "MicroECS")
set(LIB_VERSION 1.0)

# Project
project(${LIB_NAME}  
        DESCRIPTION "C++17 ECS library"
        VERSION ${LIB_VERSION} 
        LANGUAGES CXX)

# Add the interface library
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Tests
if(DEFINED MICROECS_COMPILE_TESTS)

        add_executable(microecs_test "tests/test.cpp")
        target_link_libraries(microecs_test ${LIB_NAME})

endif()

