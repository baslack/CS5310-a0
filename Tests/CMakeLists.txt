cmake_minimum_required(VERSION 3.7)
project(test_sorts)

set(CMAKE_STATIC "-static-libgcc -static-libstdc++ -static")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_STATIC}" )

set(TEST_FILES TEST_sorts.cpp ../sorts.h)

#setup google test
link_directories("../../googletest/google-distribution/lib")
include_directories("../../googletest/google-distribution/include")
find_library(GTEST NAMES "gtest"
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../googletest/google-distribution/lib NO_DEFAULT_PATH)
find_library(GTEST_MAIN NAMES "gtest_main"
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../googletest/google-distribution/lib NO_DEFAULT_PATH)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_sorts ${TEST_FILES})
target_link_libraries(test_sorts gtest gtest_main)
