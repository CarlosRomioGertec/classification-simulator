cmake_minimum_required (VERSION 3.8)

project(classification_simulator VERSION 1.0
    DESCRIPTION "Classification Simulator"
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ativando LTO para melhorar o tempo de build
set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
add_compile_definitions(PROJECT_CLASSIFICATION_SIMULATOR)
set(PROJECT_CLASSIFICATION_SIMULATOR ON)

get_directory_property(PROJETO_COMPILE_DEFINITIONS COMPILE_DEFINITIONS)

# Gather source files
file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
# Exclude build and CMake-specific files
list(FILTER SRC_FILES EXCLUDE REGEX ".*CMakeCXXCompilerId.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${GUI_OPTION} ${SRC_FILES} )

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

file(GLOB DATA_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/data/*
)

foreach(file ${DATA_FILES})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${file}
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endforeach()