cmake_minimum_required(VERSION 3.17)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(src)

option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
        enable_testing()
        add_subdirectory(tests)
endif()
