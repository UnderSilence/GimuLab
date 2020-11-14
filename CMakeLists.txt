cmake_minimum_required(VERSION 3.17)
project(GimuDev)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

message(STATUS "Operating system is ${CMAKE_SYSTEM}")

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Target platform: Windows")
    add_definitions(-DGIMU_PLATFORM_WINDOWS)
endif()

set(ENGINE_API_INCLUDES "Gimu/Source")

include_directories(${ENGINE_API_INCLUDES})
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Binaries")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Binaries")

add_subdirectory(Gimu)
add_subdirectory(Sandbox)
