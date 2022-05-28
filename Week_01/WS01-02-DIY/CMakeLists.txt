cmake_minimum_required(VERSION 3.22)
project(DIY_LAB)

set(CMAKE_CXX_STANDARD 14)

add_executable(DIY_LAB w2p2.cpp quiz.cpp quiz.h question.cpp question.h cmake-build-debug/quiz2.txt cmake-build-debug/quiz3.txt cmake-build-debug/quiz4.txt cmake-build-debug/quiz5.txt)
