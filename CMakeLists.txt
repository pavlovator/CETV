cmake_minimum_required(VERSION 3.10)

project(CETV)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/main.cpp)

find_package(raylib REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(cetv ${SOURCES})

target_link_libraries(cetv raylib GL m pthread dl rt X11)
