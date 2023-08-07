cmake_minimum_required(VERSION 3.25)
project(leet)

set(CMAKE_CXX_STANDARD 17 "-Wall -Wextra -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(Two_Sum 1.Two_Sum.cpp)