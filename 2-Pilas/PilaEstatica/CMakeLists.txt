cmake_minimum_required(VERSION 3.20)
project(StaticStack C)

set(CMAKE_C_STANDARD 99)

add_executable(StaticStack main.c TElemento.h TElemento.c TStaticStack.c TStaticStack.h)
