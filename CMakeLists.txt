cmake_minimum_required(VERSION 3.17)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(tic_tac_toe
        Game.cpp
        Game.h
        main.cpp
        matrix.cpp
        matrix.h
        Player.cpp
        Player.h
        catch/catch_main.cpp
        Tests.cpp
        )
