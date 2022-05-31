cmake_minimum_required(VERSION 3.22)
project(DIY)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DIY
        Bar.cpp
        Bar.h
        BarChart.cpp
        BarChart.h
        barTester.cpp
        main.cpp)
