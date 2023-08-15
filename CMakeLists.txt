# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Name the project
project(govtest VERSION 0.1)

# Define a variable containing a list of source files for the project
set(SRC_FILES
    107-6.cpp
    )

# Define the build target for the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Werror -pedantic-errors")