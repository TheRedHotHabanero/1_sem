cmake_minimum_required(VERSION 3.17)
project(list)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")

add_executable(list subforwardlist_profiler.cpp)
