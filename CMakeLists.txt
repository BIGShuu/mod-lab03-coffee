cmake_minimum_required(VERSION 3.5)
project(mod-lab03-automata)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main library
set(SOURCES src/Automata.cpp)
set(HEADERS include/Automata.h)

add_library(automata_lib ${SOURCES} ${HEADERS})
target_include_directories(automata_lib PUBLIC include)

# Main executable
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} automata_lib)

# Tests
enable_testing()
add_subdirectory(test)
