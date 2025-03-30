cmake_minimum_required(VERSION 3.12.0)
project(pong_game VERSION 0.1.0 LANGUAGES C CXX)
include(CTest)
enable_testing()

add_executable(pong_game src/main.cpp
    src/ball.cpp
    src/paddle.cpp
    src/Game.cpp)
include_directories(include)
set_property(TARGET pong_game PROPERTY CXX_STANDARD 17)