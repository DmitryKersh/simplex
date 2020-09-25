cmake_minimum_required(VERSION 3.17)
project(simplex)

set(CMAKE_CXX_STANDARD 17)

add_executable(simplex main.cpp table.cpp table.h parsers.cpp parsers.h Rational.cpp Rational.h)