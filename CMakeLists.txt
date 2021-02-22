cmake_minimum_required(VERSION 3.5.1)
option(EMCC "Compiles to webasambly WASM with emcc" OFF)

# set project name and add src
project (ludo VERSION 1.0)
add_executable(ludo src/Main.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(EMCC)
    message(STATUS "Setting compilation target to WASM")
    set_target_properties(ludo PROPERTIES LINK_FLAGS "-O3 -s WASM=1")
else(EMCC)
    message(STATUS "Setting compilation target to local")
endif(EMCC)
