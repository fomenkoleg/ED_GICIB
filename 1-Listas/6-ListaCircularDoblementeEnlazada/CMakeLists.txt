cmake_minimum_required(VERSION 3.20)
project(ListaCircularDoblementeEnlazada C)

set(CMAKE_C_STANDARD 99)

add_executable(ListaCircularDoblementeEnlazada main.c listaCircularDoblementeEnlazada.c listaCircularDoblementeEnlazada.h TElemento.c TElemento.h)
