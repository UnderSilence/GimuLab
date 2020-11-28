
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)

add_subdirectory(GLFW)
add_subdirectory(spdlog)
add_subdirectory(Glad)
add_subdirectory(eigen)

project(ImGui)

include_directories(imgui GLFW/include Glad/include)
aux_source_directory(imgui IMGUI_SRCS)

set(IMGUI_BACKENDS_SRCS
        imgui/backends/imgui_impl_glfw.h
        imgui/backends/imgui_impl_opengl3.h
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        )

add_library(ImGui STATIC ${IMGUI_SRCS} ${IMGUI_BACKENDS_SRCS})
target_link_libraries(ImGui glfw glad ${OPENGL_LIBRARIES})
