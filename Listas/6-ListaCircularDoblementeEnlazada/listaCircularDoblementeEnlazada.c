//
// Created by Oleg Fomenkov on 19/3/23.
//

#include "listaCircularDoblementeEnlazada.h"
#include <stdio.h>
#include <stdlib.h>

int esListaVacia(TLista* l){
    return *l==NULL;
}
void crearListaVacia(TLista* l){
    *l = NULL;
}
void mostrarLista(TLista* l){

    printf("[");
    if(!esListaVacia(l)){
        TNodo* aux = *l;
        mostrarElemento(aux->info);
        if(aux->sig != *l){
            printf(", ");
        }
        aux=aux->sig;

        while(aux!=*l){
            mostrarElemento(aux->info);
            if(aux->sig != *l){
                printf(", ");
            }
            aux = aux->sig;
        }
    }
    printf("]");

}

void restoLista(TLista *l){
    if(!esListaVacia(l)){
        TNodo* aux = *l;

        if(aux->sig==*l){//si solo hay un elemento
            *l = NULL;
            free(aux);
            aux=NULL;

        } else { //si hay más de un elemento

            aux = (*l)->ant; //pillamos el último elemento
            aux->sig = (*l)->sig; //hacemos que apunte al segundo elemento

            TNodo* paraBorrar = *l; //preparamos el primer elemento para borrar
            *l = (*l)->sig; //hacemos que la lista apunte al segundo elemento
            (*l)->ant = aux; //el anterior del segundo elemento ahora apunta al último elemento
            free(paraBorrar);
            paraBorrar = NULL;
        }
    }
}

void insertarListaCabecera(TLista* l, TElemento* elem){
    TNodo *aux = (TNodo*) malloc(sizeof(TNodo));
    asignarElemento(&aux->info, *elem);
    aux->sig = *l;
    if(aux->sig == NULL){
        aux->sig = aux;
        aux->ant = aux;
    } else {
        if(!esListaVacia(l)){
            TNodo* recorrer = (*l)->ant;
            (*l)->ant = aux;
            recorrer->sig = aux;
            aux->ant=recorrer;
        }
    }
    *l = aux;
}


void insertarListaFinal(TLista* l, TElemento* elem){
    if(esListaVacia(l)){
        insertarListaCabecera(l , elem);
    } else {
        TNodo* nElem = (TNodo*) malloc(sizeof(TNodo));
        asignarElemento(&nElem->info, *elem);
        nElem->sig = *l;
        nElem->ant = (*l)->ant;
        (*l)->ant->sig = nElem;
        (*l)->ant = nElem;
    }
}


int eliminarElementoLista(TLista* l, TElemento* elem) {
    if (esListaVacia(l)) {
        return 0;
    } else {
        TNodo *aux = *l;
        int deleted = 0;
        if (aux->sig == *l) {
            if (igualElemento(aux->info, *elem)) { //si ese único elemento es el que queremos borrar
                *l = NULL; //entonces asignamos la lista como vacía;
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

                while (aux!=*l) { //mientras no llegue al final
                    if (igualElemento(aux2->info, *elem)) { //comparamos el elem con los elementos de la lista
                        aux2->sig->ant = aux;
                        aux->sig = aux2->sig;  //hacemos que el anterior apunte al siguiente del actual
                        free(aux2); //liberamos el actual
                        aux2=NULL;
                        deleted = 1; //encontramos el elemento a borrar
                        return deleted;
                    }
                    aux = aux->sig; //movemos el puntero
                    if (aux2!=*l) { //y, si no apunta al primero
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
        asignarElemento(elem, (*l)->info);
    }
}

int obtenerNumeroElementos(TLista l){
    if(esListaVacia(&l)){ //si es vacia, 0
        return 0;
    } else if(l->sig == NULL){ //si solo hay 1 elemento, 1
        return 1;
    } else { //si hay mas q 1
        TNodo* aux = l;
        int len = 0;
        while(aux != NULL){ //iteramos por la lista hasta llegar a NULL
            aux=aux->sig; //aumentamos el puntero
            len++; //incrementamos la longitud
        }
        return len;
    }
}

void obtenerUltimoLista(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){ //si no es vacia
        asignarElemento(elem, (*l)->ant->info); //y asignamos el ultimo
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
            TNodo* auxOrig = *orig;
            TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //creamos un puntero para asignarlo a las posiciones de la segunda lista

            //asignamos el primer elemento
            asignarElemento(&nuevoElemento->info, auxOrig->info);
            nuevoElemento->sig = nuevoElemento;
            nuevoElemento->ant = nuevoElemento;
            *dest = nuevoElemento;

            TNodo* auxDest = *dest; //creamos un puntero para iterar por la segunda lista
            auxOrig = auxOrig->sig; // e incrementamos el primer puntero para el siguiente elemento


            while(auxOrig != *orig){// mientras no llegamos al ultimo
                nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //reservamos nuevo hueco en memoria para no reescribir
                asignarElemento(&nuevoElemento->info, auxOrig->info); //asignamos el info del elemento de primera lista a ese nuevo hueco
                nuevoElemento->sig = *dest; //hacemos que sea el último pq no sabemos si habrá otro en la primera lista
                nuevoElemento->ant = auxDest;
                (*dest)->ant = nuevoElemento;

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
            //en mi código de 1º tengo TLista nuevaLista sin el puntero, no se si funcionará de momento pero eso espero
            crearListaVacia(nuevaLista);
            asignarLista(dos, nuevaLista); //asignamos la segunda lista a una nueva creada

            (*uno)->ant->sig = *nuevaLista; //asignamos que el último elemento de la primera lista apunte como siguiente al primer elemento de la nueva lista creada

            (*nuevaLista)->ant->sig=*uno;
        }
    } else {
        asignarLista(dos, uno);
    }

}



int contieneLista(TLista* l, TElemento elem){
    if(esListaVacia(l)){
        return 0;
    } else {
        TNodo* aux = *l;
        while(aux->sig!=NULL){ //iterando hasta el último elemento
            if(igualElemento(aux->info, elem)){ //si conincide
                return 1; //devolvemos 1 -> sí, contiene
            }
        }
        return 0;  //si no pos no jsjsj
    }
}