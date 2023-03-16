//
// Created by Oleg Fomenkov on 21/2/23.
//
#include "TElemento.h"

#include <stdio.h>

void mostrarElemento(TElemento t)
{
    printf("%d", t.elem);

}

void asignarElemento(TElemento *destino, TElemento origen)
{
    destino->elem = origen.elem;
}

int igualElemento(TElemento uno, TElemento dos)
{
    return uno.elem == dos.elem;
}

void crearElemento(int elem, TElemento* elemento)
{
    elemento->elem = elem;
}
