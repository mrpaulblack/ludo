cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(ludo VERSION 1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(${PROJECT_NAME} src/Main.cpp)
