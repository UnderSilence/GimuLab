cmake_minimum_required(VERSION 3.17)

add_subdirectory(ThirdParty/GLFW)
add_subdirectory(ThirdParty/spdlog)

project(Gimu)
aux_source_directory(Source/Gimu/Core GIMU_SRCS)
aux_source_directory(Source/Gimu/Events GIMU_EVENTS_SRCS)
aux_source_directory(Source/Platform/Windows PLATFORM_SRCS)

message(STATUS "found engine srcs: ${GIMU_SRCS}")

set(ENGINE_API_INCLUDES "Source")
#Configuration ThirdParty Dependency
include_directories(${ENGINE_API_INCLUDES})
include_directories(ThirdParty/spdlog/include ThirdParty/GLFW/include)

add_definitions(-DGIMU_BUILD_DLL)
add_library(Gimu SHARED ${GIMU_SRCS} ${GIMU_EVENTS_SRCS} ${PLATFORM_SRCS} Source/Gimu/Core/Assert.h Source/Gimu/Core/Window.cpp)
target_precompile_headers(Gimu PUBLIC Source/gmpch.h)
target_link_libraries(Gimu glfw spdlog)

