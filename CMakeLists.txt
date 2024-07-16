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

add_subdirectory (src)

target_include_directories (
    ${PROJECT_NAME}
    PUBLIC include
)

