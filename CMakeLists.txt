cmake_minimum_required(VERSION 3.7)
project(a0)

set(CMAKE_STATIC "-static-libgcc -static-libstdc++ -static")
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_STATIC}" )

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Tests)

set(SOURCE_FILES main.cpp sorts.h)
add_executable(a0 ${SOURCE_FILES})
