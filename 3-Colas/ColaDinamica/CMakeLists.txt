cmake_minimum_required(VERSION 3.20)
project(ColaDinamica C)

set(CMAKE_C_STANDARD 99)

add_executable(ColaDinamica main.c ColaDinamica.c ColaDinamica.h TElemento.c TElemento.h)
