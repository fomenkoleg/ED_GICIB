//
// Created by Oleg Fomenkov on 21/2/23.
//
#include <stdio.h>
#import "listaEnlazadaSimple.h"

void crearListaVacia(tLista* l)
{
    l->posVacia=0;
}

void mostrarLista(tLista l)
{
    printf("[");
    for (int i = 0; i < obtenerNumeroElementos(l); ++i) {
        mostrarElemento(l.almacen[i]);
        //if(i<l.posVacia-1){printf(", ");}
    }
    printf("]");
}

void insertarLista(tElemento e, tLista* l)
{
    int i = obtenerNumeroElementos(*l);
    asignarElemento(&(l->almacen[i]), e);
    l->posVacia++;
}

void primeroLsita(tElemento* e, tLista* l)
{
    asignarElemento(e, (l->almacen[0]));
}

int esListaVacia(tLista l)
{
    return l.posVacia=0;
}

int estaLlena(tLista l)
{
    return l.posVacia==DIM-1;
}

int obtenerNumeroElementos(tLista l)
{
    return l.posVacia;
}

void obtenerElementoEnPos(tLista l, int pos, tElemento *e)
{
    if(pos>=0 && pos<obtenerNumeroElementos(l)){
        asignarElemento(e, (l.almacen[pos]));
    }
    e=NULL;
}

