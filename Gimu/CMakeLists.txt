cmake_minimum_required(VERSION 3.17)

project(Gimu)

aux_source_directory(Source/Gimu GIMU_SRCS)
aux_source_directory(Source/Gimu/Events GIMU_EVENTS_SRCS)

message(STATUS "found engine srcs: ${GIMU_SRCS}")

set(ENGINE_API_INCLUDES "Source")
#Configuration ThirdParty Dependency
include_directories(${ENGINE_API_INCLUDES})

add_definitions(-DGIMU_BUILD_DLL)
add_library(Gimu SHARED ${GIMU_SRCS} ${GIMU_EVENTS_SRCS} Source/Gimu.h Source/Gimu/Events/AppEvent.h Source/Gimu/Events/Event.h Source/Gimu/Events/KeyEvent.h Source/Gimu/Events/MouseEvent.h Source/Gimu/Base.h)
target_include_directories (Gimu PUBLIC include)