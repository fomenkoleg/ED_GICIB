//
// Created by Oleg Fomenkov on 21/3/23.
//

#ifndef COLADINAMICA_COLADINAMICA_H
#define COLADINAMICA_COLADINAMICA_H

#include "TElemento.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo* sig;
}TNodo;

typedef struct {
    TNodo* head;
    TNodo* tail;
}TCola;

int esColaVacia(TCola* l);
void crearColaVacia(TCola* l);
void mostrarCola(TCola* l);

void desencolar(TCola* l);
void encolar(TCola* l, TElemento* elem);

int eliminarElementoCola(TCola* l, TElemento* elem);
void obtenerPrimeroCola(TCola* l, TElemento* elem);
int obtenerNumeroElementos(TCola l);


void obtenerCimaCola(TCola* l, TElemento* elem);
void destruirCola(TCola *l);
void asignarCola(TCola* orig, TCola* dest);
int contieneCola(TCola* l, TElemento elem);
int esIgualCola(TCola* uno, TCola* dos);
void concatenarCola(TCola* uno, TCola* dos);

void borrarNPirmeros(int n, TCola *l);

#endif //COLADINAMICA_COLADINAMICA_H
