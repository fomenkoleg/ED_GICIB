cmake_minimum_required(VERSION 3.20)
project(ejercicioPila C)

set(CMAKE_C_STANDARD 99)

add_executable(ejercicioPila main.c Lista/listaEnlazadaDinamica.c Lista/listaEnlazadaDinamica.h PilaDinamica.c PilaDinamica.h TElemento.h TElemento.c)
