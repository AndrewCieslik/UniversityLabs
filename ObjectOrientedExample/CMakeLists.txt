cmake_minimum_required(VERSION 3.25)
project(OrientedCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OrientedCPP main.cpp Square.cpp Square.h Rectangle.cpp Rectangle.h Triangle.cpp Triangle.h Circle.cpp Circle.h Trapezoid.cpp Trapezoid.h)
