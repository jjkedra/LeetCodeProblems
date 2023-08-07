cmake_minimum_required(VERSION 3.16)
project(leet)

set(CMAKE_CXX_STANDARD 17 "-Wall -Wextra -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(2.Add_Two_Numbers 2.Add_Two_Numbers.cpp)