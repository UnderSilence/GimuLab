cmake_minimum_required(VERSION 3.17)
project(GimuDev)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

add_subdirectory(Sandbox)
add_subdirectory(Gimu)