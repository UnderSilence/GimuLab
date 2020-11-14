

project(Gimu)

aux_source_directory(Source/Gimu GIMU_SRCS)
add_definitions(-DGIMU_BUILD_DLL)
add_library(Gimu SHARED ${GIMU_SRCS} Source/Test.cpp Source/Test.h Source/Gimu.h)
target_include_directories (Gimu PUBLIC include)