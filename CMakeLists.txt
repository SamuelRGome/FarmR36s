cmake_minimum_required(VERSION 3.13)
project(FarmR36s)

add_executable(Farmr36s Game/main.cpp)

find_package(SDL2 REQUIRED)

target_link_libraries(Farmr36s PRIVATE SDL2::SDL2)
