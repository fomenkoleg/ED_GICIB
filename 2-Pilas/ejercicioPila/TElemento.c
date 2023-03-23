//
// Created by Oleg Fomenkov on 14/3/23.
//

#include "TElemento.h"

#include <stdio.h>
#include <string.h>

void mostrarElemento(TElemento t)
{
    printf("%c", t.elem);

}

void asignarElemento(TElemento *destino, TElemento origen)
{
   destino->elem = origen.elem;
}

int igualElemento(TElemento uno, TElemento dos)
{
    return uno.elem == dos.elem;
}

void crearElemento(char elem, TElemento* elemento)
{
   elemento->elem = elem;
}
