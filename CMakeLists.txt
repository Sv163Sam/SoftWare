cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp main.cpp main.h)

target_link_libraries(untitled ${OpenCV_LIBS})