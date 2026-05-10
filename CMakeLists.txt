# Copyright 2026 UNN-IASR
cmake_minimum_required(VERSION 3.5)
project(mod-lab03-coffee)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(automata_lib
  src/Automata.cpp
  include/Automata.h
)
target_include_directories(automata_lib PUBLIC include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} automata_lib)

enable_testing()
add_subdirectory(test)
