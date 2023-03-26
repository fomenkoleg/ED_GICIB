//
// Created by Oleg Fomenkov on 19/2/22.
//

#ifndef LISTAESTATICA_TLISTACIRCULARESTATICA_H
#define LISTAESTATICA_TLISTACIRCULARESTATICA_H

#include <stdio.h>
#include "TElemento.h"

#define DIM 10

typedef struct l{
    TElemento store[DIM];
    int start;
    int end;
    int occupied;
} TLista;

void createEmptyList(TLista *l);
int isEmptyList(TLista *l);
int lengthOfList(TLista *l);
void firstInList(TLista *l, TElemento* elem);
void subtractList(TLista* l);
void lastInList(TLista* l, TElemento* elem);
void destroyList(TLista* l);
void showList(TLista* l);
void insertInList(TElemento* elem, TLista* l);
void assignList(TLista* orig, TLista* dest);
void insertFinalList(TElemento *elem, TLista* l);
int containsList(TElemento* elem, TLista* l);
int isEqualList(TLista *l1, TLista *l2);
int deleteElemFromList(TElemento *elem, TLista* l);
void concatenateLists(TLista* l1, TLista* l2);

#endif //LISTAESTATICA_TLISTACIRCULARESTATICA_H
