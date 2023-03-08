//
// Created by Oleg Fomenkov on 21/2/23.
//

#ifndef LISTADINAMICA_LISTAENLAZADASIMPLE_H
#include "tElemento.h"
#define DIM 50
typedef struct listaEstatica{
    tElemento almacen[DIM];
    int posVacia;
}TLista;

void crearListaVacia(TLista* l);
void mostrarLista(TLista l);
void insertarLista(tElemento e, TLista* l);
void primeroLsita(tElemento* e, TLista* l);
int esListaVacia(TLista l);
int estaLlena(TLista l);
int obtenerNumeroElementos(TLista l);
void obtenerElementoEnPos(TLista l, int pos, tElemento *e);

#define LISTADINAMICA_LISTAENLAZADASIMPLE_H

#endif //LISTADINAMICA_LISTAENLAZADASIMPLE_H
