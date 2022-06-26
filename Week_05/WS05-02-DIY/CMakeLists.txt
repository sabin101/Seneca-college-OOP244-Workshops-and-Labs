cmake_minimum_required(VERSION 3.22)
project(DIY)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DIY
        Hero.cpp
        Hero.h
        main.cpp
        Power.cpp
        Power.h)
