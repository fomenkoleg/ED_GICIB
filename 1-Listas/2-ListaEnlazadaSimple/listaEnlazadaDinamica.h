//
// Created by Oleg Fomenkov on 28/2/23.
//

#ifndef LISTADINAMICA_LISTAENLAZADADINAMICA_H
#define LISTADINAMICA_LISTAENLAZADADINAMICA_H

#include "tElemento.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo* sig;
}TNodo;

typedef TNodo * TLista;

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
int contieneLista(TLista* l, TElemento elem);
int esIgualLista(TLista* uno, TLista* dos);
void concatenarLista(TLista* uno, TLista* dos);


void borrarNPirmeros(int n, TLista *l);

void unique(TLista* l);
/*

void unique(TLista* l);
void borrarUltimo(TLista* lista);
void invertir(TLista* l1);
void borrarCada(TLista *l, int n);
int listaContieneLista(TLista *original, TLista* sublista);
int listaContieneListaEnOrden(TLista *original, TLista* sublista);
*/

#endif //LISTADINAMICA_LISTAENLAZADADINAMICA_H
