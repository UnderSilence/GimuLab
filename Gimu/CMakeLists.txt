cmake_minimum_required(VERSION 3.17)

add_subdirectory(ThirdParty)

project(Gimu)
aux_source_directory(Source/Gimu/Core GIMU_CORE_SRCS)
aux_source_directory(Source/Gimu/Events GIMU_EVENTS_SRCS)
aux_source_directory(Source/Gimu/ImGui GIMU_IMGUI_SRCS)
aux_source_directory(Source/Platform/Windows PLATFORM_WINDOWS_SRCS)
aux_source_directory(Source/Platform/OpenGL PLATFORM_OPENGL_SRCS)

set(ENGINE_API_INCLUDES "Source")
#Configuration ThirdParty Dependency

set(ThirdPartyIncludeDirs
        ThirdParty/spdlog/include
        ThirdParty/GLFW/include
        ThirdParty/Glad/include
        ThirdParty/imgui
        ThirdParty/eigen)

include_directories(${ENGINE_API_INCLUDES} ${ThirdPartyIncludeDirs})

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
find_package(OpenGL REQUIRED)

add_definitions(-DGIMU_BUILD_DLL)
add_library(Gimu SHARED ${GIMU_CORE_SRCS} ${GIMU_EVENTS_SRCS} ${GIMU_IMGUI_SRCS} ${PLATFORM_WINDOWS_SRCS} ${PLATFORM_OPENGL_SRCS})
target_precompile_headers(Gimu PUBLIC Source/gmpch.h)

target_link_libraries(Gimu glfw spdlog glad ImGui ${OPENGL_LIBRARIES} eigen)

