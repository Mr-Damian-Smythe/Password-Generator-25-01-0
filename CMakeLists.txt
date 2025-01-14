# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(RandomPasswordGenerator VERSION 1.0)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable target
add_executable(RandomPasswordGenerator main.c)
