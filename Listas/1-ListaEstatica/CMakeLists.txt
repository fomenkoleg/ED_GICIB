cmake_minimum_required(VERSION 3.20)
project(ListaEstatica C)

set(CMAKE_C_STANDARD 99)

add_executable(ListaEstatica main.c TElemento.h TElemento.c TListaEstatica.h TListaEstatica.c)
