//
// Created by Oleg Fomenkov on 14/3/23.
//

#include "PilaDinamica.h"

void crearPilaVacia(TPila* s){
    *s = NULL;
}
int esPilaVacia(TPila* s){
    return *s == NULL;
}
void push(TPila* s, TElemento* elem){
    TNodoPila* nuevoElemento = (TNodoPila*) malloc(sizeof(TNodoPila));
    asignarElemento(&nuevoElemento->info, *elem);
    nuevoElemento->sig = *s;
    *s = nuevoElemento;
}

void pop(TPila* s){
    if(!esPilaVacia(s)){
        TNodoPila* paraBorrar = *s;
        *s = (*s)->sig;
        free(paraBorrar);
    }
}

void cima(TPila* s, TElemento *elem){
    if(!esPilaVacia(s)){
        asignarElemento(elem, (*s)->info);
    }
}

int longitudPila(TPila* s){
    if(!esPilaVacia(s)){
        TNodoPila* recorrer = *s;
        int contador=0;
        while(recorrer!=NULL){
            contador++;
            recorrer = recorrer->sig;
        }
        return contador;
    }
    return 0;
}

void copiarPila(TPila* s1, TPila* s2){
    if(!esPilaVacia(s1)){
        destruirPila(s2);
        TNodoPila* recorrerUno = *s1;
        TNodoPila* recorrerDos = *s2;

        while(recorrerUno!=NULL){
            TNodoPila* nuevoNodo = (TNodoPila*) malloc(sizeof(TNodoPila));
            asignarElemento(&nuevoNodo->info, recorrerUno->info);
            nuevoNodo->sig = NULL;

            if(!esPilaVacia(s2)){
                recorrerDos->sig = nuevoNodo;
            } else {
                *s2 = nuevoNodo;
            }
            recorrerDos = nuevoNodo;
            recorrerUno = recorrerUno->sig;
        }
    }
}
void destruirPila(TPila* s){
    while(!esPilaVacia(s)){
        pop(s);
    }
}

void mostrarPila(TPila* s){
    printf("+---+\n");
    if(esPilaVacia(s)){
        printf("+---+\n");
    } else {
        TNodoPila* recorrer = *s;
        while(recorrer){
            printf("| ");
            mostrarElemento(recorrer->info);
            printf(" |\n+---+\n");
            recorrer = recorrer->sig;
        }
    }
}