cmake_minimum_required(VERSION 3.16)
project(GS3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/libs)
set(CMAKE_WIN32_EXECUTABLE OFF)

include_directories(
    ${SRC_DIR}
    ${SRC_DIR}/phys
    ${SRC_DIR}/platform
    ${LIBS_DIR}/glfw/include
    ${LIBS_DIR}/glad/include
)

file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/platform/*.cpp
    ${LIBS_DIR}/glad/src/glad.c
)

add_executable(EOD ${SOURCES})

# link_directories(${LIBS_DIR}/glfw/lib)

target_link_libraries(
    EOD 
    ${LIBS_DIR}/glfw/build/src/libglfw3.a
    opengl32 
    gdi32
)

set_target_properties(EOD PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output
)