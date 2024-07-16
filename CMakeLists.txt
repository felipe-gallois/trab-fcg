cmake_minimum_required(VERSION 3.5)

project(trab-fcg)

# C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable LSP to function correctly 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set directories for compiled artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set CMP0079 policy to NEW
if (POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

find_package(OpenGL REQUIRED)

add_subdirectory(src)
add_subdirectory(lib)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE include
)

target_link_libraries(
    ${PROJECT_NAME}
    glfw
    glad
    OpenGL::GL
)

