cmake_minimum_required(VERSION 3.25)
project(ponc)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(ponc src/main.cpp
        src/Ball.cpp
        src/Paddle.cpp
        src/GameState.cpp
        include/Ball.h
        include/Paddle.h
        include/GameState.h)

configure_file(bit5x3.ttf bit5x3.ttf COPYONLY)
configure_file(bounce.wav bounce.wav COPYONLY)

target_link_libraries(ponc sfml-audio sfml-graphics sfml-window sfml-system)
