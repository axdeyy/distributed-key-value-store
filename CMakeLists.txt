cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(DistributedKVStore VERSION 1.0)

# Specify C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for source and test files
add_subdirectory(src)
add_subdirectory(test)

# Output directory for build files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
