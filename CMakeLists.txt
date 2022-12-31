cmake_minimum_required(VERSION 3.15)

set(CMAKE_INCLUDE_PATH "/usr/include")
set(CMAKE_LIBRARY_PATH "/usr/lib64/libncurses.so")

project(outer)

find_package(Curses REQUIRED)

include_directories(include)
include_directories(src/configs/include)
set(SOURCES src/gameobjects/person.cpp src/concepts/currentState.cpp srcigamestates/update.cpp src/configs/config.cpp src/main.cpp src/commons.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_LIBRARY_PATH})
