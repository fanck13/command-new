cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(command-new LANGUAGES CXX)

file(GLOB SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(command-new ${SRC})