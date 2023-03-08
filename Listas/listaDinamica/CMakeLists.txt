cmake_minimum_required(VERSION 3.20)
project(listaDinamica C)

set(CMAKE_C_STANDARD 99)

add_executable(listaDinamica main.c listaEnlazadaSimple/tElemento.h listaEnlazadaSimple/listaEnlazadaSimple.h listaEnlazadaSimple/tElemento.c listaEnlazadaSimple/listaEnlazadaSimple.c listaEnlazadaSimple/listaEnlazadaDinamica.c listaEnlazadaSimple/listaEnlazadaDinamica.h)
