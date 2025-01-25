cmake_minimum_required(VERSION 3.28)
project(Super8s)

set(CMAKE_CXX_STANDARD 17)

add_executable(Super8s main.cpp
        Card.cpp
        Game.cpp
        Player.cpp)
