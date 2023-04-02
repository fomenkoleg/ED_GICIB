//
// Created by Oleg Fomenkov on 7/3/23.
//

#ifndef LISTADINAMICAPUNTEROPRINCIPIOFIN_LISTAENLAZADAPUNTEROPRINCIPIOFIN_H
#define LISTADINAMICAPUNTEROPRINCIPIOFIN_LISTAENLAZADAPUNTEROPRINCIPIOFIN_H

#include "TElemento.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo* sig;
}TNodo;

typedef struct {
    TNodo* head;
    TNodo* tail;
}TLista;

int esListaVacia(TLista* l);
void crearListaVacia(TLista* l);
void mostrarLista(TLista* l);

void restoLista(TLista* l);
void insertarListaCabecera(TLista* l, TElemento* elem);
void insertarListaFinal(TLista* l, TElemento* elem);

int eliminarElementoLista(TLista* l, TElemento* elem);
void obtenerPrimeroLista(TLista* l, TElemento* elem);
int obtenerNumeroElementos(TLista l);


void obtenerUltimoLista(TLista* l, TElemento* elem);
void destruirLista(TLista *l);
void asignarLista(TLista* orig, TLista* dest);
int borrarSecuencia(TLista* l, TElemento* e1, TElemento*e2);
int contieneLista(TLista* l, TElemento elem);
int esIgualLista(TLista* uno, TLista* dos);
void concatenarLista(TLista* uno, TLista* dos);

void borrarNPirmeros(int n, TLista *l);


#endif //LISTADINAMICAPUNTEROPRINCIPIOFIN_LISTAENLAZADAPUNTEROPRINCIPIOFIN_H
