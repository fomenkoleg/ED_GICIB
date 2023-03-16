cmake_minimum_required(VERSION 3.20)
project(ListaEnlazadaSimple C)

set(CMAKE_C_STANDARD 99)

add_executable(ListaEnlazadaSimple main.c listaEnlazadaDinamica.h listaEnlazadaDinamica.c tElemento.c tElemento.h)
