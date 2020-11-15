cmake_minimum_required(VERSION 3.17)
project(GimuDev)

set(CMAKE_CXX_STANDARD 20)
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++17 -Wall ${CMAKE_CXX_FLAGS}")
endif(CMAKE_COMPILER_IS_GNUCXX)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Target platform: Windows")
    add_definitions(-DGIMU_PLATFORM_WINDOWS)
endif(CMAKE_SYSTEM_NAME MATCHES "Windows")

set(ENGINE_API_INCLUDES "Gimu/Source")
set(THIRDPARTY_API_PREFIX "Gimu/ThirdParty")
set(LOG_API_INCLUDES ${THIRDPARTY_API_PREFIX}/spdlog/include)

#Configuration ThirdParty Dependency
set(THIRDPARTY_API_INCLUDES "")
string(APPEND THIRDPARTY_API_INCLUDES ${LOG_API_INCLUDES})
message(STATUS "ThirdParty includes directory: ${THIRDPARTY_API_INCLUDES}")
include_directories(${ENGINE_API_INCLUDES} ${THIRDPARTY_API_INCLUDES})

set(SPECIFIC_OUTPUT_DIR "${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}")
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Binaries/${SPECIFIC_OUTPUT_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Binaries/${SPECIFIC_OUTPUT_DIR}")

add_subdirectory(Gimu)
# add_subdirectory(Gimu/ThirdParty/spdlog)
add_subdirectory(Sandbox)
