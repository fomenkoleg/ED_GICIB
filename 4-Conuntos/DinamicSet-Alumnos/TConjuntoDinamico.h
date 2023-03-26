//
// Created by alfon on 09/03/2021.
//

#ifndef ConjuntoENLAZADASIMPLE_TConjuntoENLAZADASIMPLE_H
#define ConjuntoENLAZADASIMPLE_TConjuntoENLAZADASIMPLE_H
#include "TElemento.h"

typedef struct NodoC{
    TElemento info;
    struct NodoC* sig;
}TNodoC;

typedef TNodoC* TConjunto;


void crearConjuntoVacio (TConjunto* l);
void mostrarConjunto (TConjunto l);
void poner (TConjunto* l,TElemento* e);
int quitar (TConjunto* l, TElemento* e);
int esConjuntoVacio (TConjunto* l);
int cardinal (TConjunto* l);
int pertenece (TConjunto* l,TElemento* e);
void elegir (TConjunto* l,TElemento* e);
void unir (TConjunto* l1, TConjunto* l2, TConjunto* u);
void interseccion (TConjunto* l1, TConjunto* l2, TConjunto* i);
void diferencia (TConjunto* l1, TConjunto* l2, TConjunto* d);
int esSubconjunto (TConjunto* l1, TConjunto* l2);
int igualConjunto (TConjunto* l1, TConjunto* l2);
void asignarConjunto (TConjunto* dest, TConjunto* orig);
void destruirConjunto(TConjunto* l);



#endif //ConjuntoENLAZADASIMPLE_TConjuntoENLAZADASIMPLE_H
