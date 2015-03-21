cmake_minimum_required(VERSION 3.1)
project(leo_zadaci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_10 zad10/zad10.cpp)
add_executable(leo_zadaci_10 ${SOURCE_FILES_10})