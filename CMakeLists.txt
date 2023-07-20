cmake_minimum_required(VERSION 3.10)
project(GameOfLife)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(GameOfLife Cell.cpp Cell.hpp Grid.hpp Grid.cpp GameOfLife.cpp)