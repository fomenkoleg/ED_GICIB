cmake_minimum_required(VERSION 3.20)
project(listaDinamicaCircular C)

set(CMAKE_C_STANDARD 99)

add_executable(listaDinamicaCircular main.c ListaCircular.c ListaCircular.h TElemento.c TElemento.h)
