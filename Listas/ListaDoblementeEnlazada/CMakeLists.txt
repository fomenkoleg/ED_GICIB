cmake_minimum_required(VERSION 3.20)
project(ListaDoblementeEnlazada C)

set(CMAKE_C_STANDARD 99)

add_executable(ListaDoblementeEnlazada main.c ListaDoblementeEnlazada.c ListaDoblementeEnlazada.h TElemento.c TElemento.h)
