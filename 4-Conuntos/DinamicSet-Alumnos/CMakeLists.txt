cmake_minimum_required(VERSION 3.17)
project(DinamicSet C)

set(CMAKE_C_STANDARD 11)

add_executable(ListaEnlazadaSimple main.c TElemento.h TElemento.c TConjuntoDinamico.c TConjuntoDinamico.h)