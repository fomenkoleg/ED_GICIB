cmake_minimum_required(VERSION 3.20)
project(ListaDinamicaPunteroPrincipioFin C)

set(CMAKE_C_STANDARD 99)

add_executable(ListaDinamicaPunteroPrincipioFin main.c ListaEnlazadaPunteroPrincipioFin.c ListaEnlazadaPunteroPrincipioFin.h TElemento.c TElemento.h)
