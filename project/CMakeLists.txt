cmake_minimum_required(VERSION 3.16.3)
project(project)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(project The_Lion_King_Maze.cpp)
target_link_libraries(project sfml-graphics sfml-audio)