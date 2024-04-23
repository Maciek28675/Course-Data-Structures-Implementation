cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
file(GLOB SOURCES "main.cpp")

# Add the executable
add_executable(Projekt1 ${SOURCES})

# Optionally copy resource files to build directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resource/data.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
