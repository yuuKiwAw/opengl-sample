cmake_minimum_required(VERSION 3.0.0)
project(opengl-sample VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

aux_source_directory(./src SrcFiles)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
add_executable(main ${SrcFiles})

target_link_libraries(main PRIVATE glfw glad::glad)
