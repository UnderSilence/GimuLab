
# set(TARGET_BINARIES_DIR "${CMAKE_SOURCE_DIR}/Binaries")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${TARGET_BINARIES_DIR}")
project(Sandbox)

aux_source_directory(Source SANDBOX_SRCS)

add_executable(Sandbox ${SANDBOX_SRCS})
target_link_libraries(Sandbox Gimu)