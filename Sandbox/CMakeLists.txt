

set(TARGET_BINARIES_DIR "${CMAKE_SOURCE_DIR}/Binaries")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${TARGET_BINARIES_DIR}")

add_executable(Sandbox main.cpp)
target_link_libraries(Sandbox "${TARGET_BINARIES_DIR}/libGimuEngine.dll")