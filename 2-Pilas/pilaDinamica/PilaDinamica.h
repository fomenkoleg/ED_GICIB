//
// Created by Oleg Fomenkov on 14/3/23.
//

#ifndef PILADINAMICA_PILADINAMICA_H
#define PILADINAMICA_PILADINAMICA_H


#include <stdio.h>
#include "TElemento.h"
#include <stdlib.h>



typedef struct TNodo{
    TElemento info;
    struct TNodo* sig;
}TNodo;

typedef struct TNodo* TPila;

void crearPilaVacia(TPila* s);
int esPilaVacia(TPila* s);
void push(TPila* s, TElemento* elem);
void pop(TPila* s);
void cima(TPila* s, TElemento *elem);
int longitudPila(TPila* s);
void copiarPila(TPila* s1, TPila* s2);
void destruirPila(TPila* s);
void mostrarPila(TPila* s);

#endif //PILADINAMICA_PILADINAMICA_H
