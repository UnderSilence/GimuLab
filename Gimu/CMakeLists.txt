cmake_minimum_required(VERSION 3.17)

project(Gimu)

aux_source_directory(Source/Gimu GIMU_SRCS)
add_definitions(-DGIMU_BUILD_DLL)
add_library(Gimu SHARED ${GIMU_SRCS} Source/Gimu.h)
target_include_directories (Gimu PUBLIC include)