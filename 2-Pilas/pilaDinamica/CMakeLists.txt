cmake_minimum_required(VERSION 3.20)
project(pilaDinamica C)

set(CMAKE_C_STANDARD 99)

add_executable(pilaDinamica main.c PilaDinamica.c PilaDinamica.h TElemento.c TElemento.h)
