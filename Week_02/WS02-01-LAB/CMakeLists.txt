cmake_minimum_required(VERSION 3.22)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        File.cpp
        File.h
        gradeReport.cpp
        Student.cpp
        Student.h)
