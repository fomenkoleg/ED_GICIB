//
// Created by Oleg Fomenkov on 19/3/23.
//

#include "listaNombreLargo.h"
#include <stdio.h>
#include <stdlib.h>

int esListaVacia(TLista* l){
    return (l->head)==NULL;
}
void crearListaVacia(TLista* l){
    l->head = NULL;
    l->tail = NULL;
}
void mostrarLista(TLista* l){

    printf("[");
    if(!esListaVacia(l)){
        TNodo* aux = l->head;
        mostrarElemento(aux->info);
        if(aux->sig != l->head){
            printf(", ");
        }
        aux=aux->sig;

        while(aux!=l->head){
            mostrarElemento(aux->info);
            if(aux->sig != l->head){
                printf(", ");
            }
            aux = aux->sig;
        }
    }
    printf("]");

}


void restoLista(TLista *l){
    if(!esListaVacia(l)){
        TNodo* aux = l->head;

        if(aux->sig==l->head){//si solo hay un elemento
            l->head = NULL;
            l->tail = NULL;
            free(aux);
            aux=NULL;

        } else { //si hay más de un elemento

            aux = (l)->tail; //pillamos el último elemento
            aux->sig = (l->head)->sig; //hacemos que apunte al segundo elemento

            TNodo* paraBorrar = l->head; //preparamos el primer elemento para borrar
            l->head = (l->head)->sig; //hacemos que la lista apunte al segundo elemento
            (l->head)->ant = aux; //el anterior del segundo elemento ahora apunta al último elemento
            free(paraBorrar);
            paraBorrar = NULL;
        }
    }
}

void insertarListaCabecera(TLista* l, TElemento* elem){
    TNodo *aux = (TNodo*) malloc(sizeof(TNodo));
    asignarElemento(&aux->info, *elem);
    aux->sig = l->head;
    if(aux->sig == NULL){
        aux->sig = aux;
        aux->ant = aux;
        l->tail = aux;
    } else {
        if(!esListaVacia(l)){
            TNodo* recorrer = (l->tail);
            (l->head)->ant = aux;
            recorrer->sig = aux;
            aux->ant=recorrer;
        }
    }
    l->head = aux;
}


void insertarListaFinal(TLista* l, TElemento* elem){
    if(esListaVacia(l)){
        insertarListaCabecera(l , elem);
    } else {
        TNodo* nElem = (TNodo*) malloc(sizeof(TNodo));
        asignarElemento(&nElem->info, *elem);
        nElem->sig = l->head;
        nElem->ant = (l->tail);
        (l->tail)->sig = nElem;
        (l->tail) = nElem;
    }
}



int eliminarElementoLista(TLista* l, TElemento* elem) {
    if (esListaVacia(l)) {
        return 0;
    } else {
        TNodo *aux = l->head;
        int deleted = 0;
        if (aux->sig == l->head) {
            if (igualElemento(aux->info, *elem)) { //si ese único elemento es el que queremos borrar
                l->head = NULL; //entonces asignamos la lista como vacía;
                l->tail = NULL;
                free(aux); //liberamos el elemento que queremos borrar
                aux = NULL; //y asignamos su puntero a NULL como medida de seguridad
                return 1;
            }
            return 0;
        } else {
            //3 casos, primero, último, en el medio
            //empezaremos con primero

            if (igualElemento(aux->info, *elem)) {
                restoLista(l);
                aux = NULL;
                return 1;
            } else {
                aux=aux->sig;
                TNodo *aux2 = aux->sig; //hacemos que aux2 sea el 2º elemento

                while (aux!=l->head) { //mientras no llegue al final
                    if (igualElemento(aux2->info, *elem)) { //comparamos el elem con los elementos de la lista
                        aux2->sig->ant = aux;
                        aux->sig = aux2->sig;  //hacemos que el anterior apunte al siguiente del actual
                        if(aux2->sig == l->head){
                            l->tail = aux;
                        }
                        free(aux2); //liberamos el actual
                        aux2=NULL;
                        deleted = 1; //encontramos el elemento a borrar
                        return deleted;
                    }
                    aux = aux->sig; //movemos el puntero
                    if (aux2!=l->head) { //y, si no apunta al primero
                        aux2 = aux2->sig; // movemos el siguiente puntero también
                    }
                }
                return deleted;
            }
        }
    }
}

void obtenerPrimeroLista(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){
        asignarElemento(elem, (l->head)->info);
    }
}

int obtenerNumeroElementos(TLista l){
    if(esListaVacia(&l)){ //si es vacia, 0
        return 0;
    } else if(l.head == l.tail){ //si solo hay 1 elemento, 1
        return 1;
    } else { //si hay mas q 1
        TNodo* aux = l.head->sig;
        int len = 1;
        while(aux != l.head){ //iteramos por la lista hasta llegar a NULL
            aux=aux->sig; //aumentamos el puntero
            len++; //incrementamos la longitud
        }
        return len;
    }
}

void obtenerUltimoLista(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){ //si no es vacia
        asignarElemento(elem, (l->tail)->info); //y asignamos el ultimo
    }
}

void destruirLista(TLista *l){
    while(!esListaVacia(l)){
        restoLista(l);
    }
}


void asignarLista(TLista* orig, TLista* dest){
    if(orig != dest){
        destruirLista(dest); //por si acaso destruimos la segunda lista
        if(esListaVacia(orig)){
            crearListaVacia(dest);
        } else {
            TNodo* auxOrig = orig->head;
            TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //creamos un puntero para asignarlo a las posiciones de la segunda lista

            //asignamos el primer elemento
            asignarElemento(&nuevoElemento->info, auxOrig->info);
            nuevoElemento->sig = nuevoElemento;
            nuevoElemento->ant = nuevoElemento;
            dest->head = nuevoElemento;
            dest->tail = nuevoElemento;

            TNodo* auxDest = dest->tail; //creamos un puntero para iterar por la segunda lista
            auxOrig = auxOrig->sig; // e incrementamos el primer puntero para el siguiente elemento

            while(auxOrig != orig->head){// mientras no llegamos al ultimo
                nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //reservamos nuevo hueco en memoria para no reescribir
                asignarElemento(&nuevoElemento->info, auxOrig->info); //asignamos el info del elemento de primera lista a ese nuevo hueco
                nuevoElemento->sig = dest->head; //hacemos que sea el último pq no sabemos si habrá otro en la primera lista
                nuevoElemento->ant = auxDest;
                (dest->head)->ant = nuevoElemento;
                (dest->tail) = nuevoElemento;
                auxDest->sig = nuevoElemento; //ponemos el nuevo elemento al final de la lista
                auxDest = nuevoElemento; //hacemos que el nuevo último elemento sea nuevoElemento

                auxOrig = auxOrig->sig; //incrementamos el primer puntero

            }
        }
    }

}





void concatenarLista(TLista* uno, TLista* dos){
    if(!esListaVacia(uno)){
        if(!esListaVacia(dos)){
            TLista* nuevaLista = (TLista*) malloc(sizeof(TLista));

            crearListaVacia(nuevaLista);
            asignarLista(dos, nuevaLista); //asignamos la segunda lista a una nueva creada

            (uno->tail)->sig = nuevaLista->head; //asignamos que el último elemento de la primera lista apunte como siguiente al primer elemento de la nueva lista creada
            (uno->head)->ant = nuevaLista->tail;
            (nuevaLista->head)->ant = (uno->tail);
            (nuevaLista->tail)->sig = uno->head;
            uno->tail = nuevaLista->tail;
        }
    } else {
        asignarLista(dos, uno);
    }

}



int contieneLista(TLista* l, TElemento elem){
    if(esListaVacia(l)){
        return 0;
    } else {
        TNodo* aux = l->head;
        while(aux->sig!=l->head){ //iterando hasta el último elemento
            if(igualElemento(aux->info, elem)){ //si conincide
                return 1; //devolvemos 1 -> sí, contiene
            }
            aux = aux->sig;
        }
        return igualElemento(aux->info, elem);
    }
}
