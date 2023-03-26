cmake_minimum_required(VERSION 3.20)
project(StaticQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(StaticQueue main.c TElemento.h TElemento.c TStaticQueue.h TStaticQueue.c)
