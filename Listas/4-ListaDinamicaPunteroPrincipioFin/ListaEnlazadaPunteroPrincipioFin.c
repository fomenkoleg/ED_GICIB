//
// Created by Oleg Fomenkov on 7/3/23.
//

#include "ListaEnlazadaPunteroPrincipioFin.h"
#include <stdio.h>
#include <stdlib.h>

//
// Created by Oleg Fomenkov on 28/2/23.
//

#include "ListaEnlazadaPunteroPrincipioFin.h"
#include <stdio.h>
#include <stdlib.h>

int esListaVacia(TLista* l){
    return l->head == NULL;
}
void crearListaVacia(TLista* l){
    l->head = NULL;
    l->tail = NULL;
}
void mostrarLista(TLista* l){
    printf("[");
    if(!esListaVacia(l)){
        TNodo* aux = l->head;
        while(aux){
            mostrarElemento(aux->info);
            if(aux->sig != NULL){
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
        l->head = (l->head)->sig;
        free(aux);
        aux = NULL;

        if(esListaVacia(l)){
            l->tail = NULL;
        } else {
            if(l->head->sig == NULL){
                l->tail = l->head;
            }
        }
    }
}
void insertarListaCabecera(TLista* l, TElemento* elem){
    TNodo *aux = (TNodo*) malloc(sizeof(TNodo));
    asignarElemento(&aux->info, *elem);
    aux->sig = l->head;
    l->head = aux;

    if(l->head->sig == NULL){
        l->tail = l->head;
    }
}

void insertarListaFinal(TLista* l, TElemento* elem){
    if(esListaVacia(l)){
        insertarListaCabecera(l , elem); //si es vacio, simplemente insertar
    } else {
        TNodo* nElem = (TNodo*) malloc(sizeof(TNodo)); //creamos el nuevo elemento
        asignarElemento(&nElem->info, *elem); //asignamos el valor que queremos a ese elemento
        nElem->sig = NULL; //hacemos que sea el último elemento

        TNodo* aux = l->head;
        while(aux->sig){
            aux = aux->sig;
        }
        aux->sig = nElem;
        (l->tail)->sig = nElem; //hacemos que el antiguo último apunte al nuevo elemento
        l->tail = nElem;
    }
}

int eliminarElementoLista(TLista* l, TElemento* elem) {
    if (esListaVacia(l)) {
        return 0;
    } else {

        TNodo *aux = l->head; //creamos un puntero para poder iterar por la lista
        int deleted = 0; //de momento no está borrado -> borrado a 0, false]

        if (aux->sig == NULL) { //si ese elemento es el único
            if (igualElemento(aux->info, *elem)) { //si ese único elemento es el que queremos borrar
                l->head = NULL; //entonces asignamos la lista como vacía;
                l->tail = NULL;
                free(aux); //liberamos el elemento que queremos borrar
                aux = NULL; //y asignamos su puntero a NULL como medida de seguridad
                return 1;
            }
            return 0;
        } else {
            if (igualElemento(aux->info, *elem)) {
                restoLista(l);
                aux = NULL;
                return 1;
            } else {
                TNodo *aux2 = aux->sig; //hacemos que aux2 sea el 2º elemento
                while (aux->sig!=NULL) { //mientras no sea null el
                    if (igualElemento(aux2->info, *elem)) { //comparamos el elem con los elementos de la lista
                        aux->sig = aux2->sig;  //hacemos que el anterior apunte al siguiente del actual
                        free(aux2); //liberamos el actual
                        deleted = 1; //encontramos el elemento a borrar
                        return deleted;
                    }
                    aux=aux->sig; //movemos el puntero
                    if (aux2!=NULL) { //y, si no apunta a NULL
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

void obtenerUltimoLista(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){ //si no es vacia
        asignarElemento(elem, (l->tail)->info); //y asignamos el ultimo
    }
}


int obtenerNumeroElementos(TLista l){
    if(esListaVacia(&l)){ //si es vacia, 0
        return 0;
    } else if((&l)->head->sig == NULL){ //si solo hay 1 elemento, 1
        return 1;
    } else { //si hay mas q 1
        TNodo* aux = l.head;
        int len = 0;
        while(aux != NULL){ //iteramos por la lista hasta llegar a NULL
            aux=aux->sig; //aumentamos el puntero
            len++; //incrementamos la longitud
        }
        return len;
    }
}

void destruirLista(TLista *l){
    while(!esListaVacia(l)){
        restoLista(l);
    }
}

void asignarLista(TLista* orig, TLista* dest){

    if(orig != dest){
        destruirLista(dest); //pos si acaso destruimos la segunda lista
        if(esListaVacia(orig)){
            crearListaVacia(dest);
        } else {
            TNodo* auxOrig = orig->head;
            TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //creamos un puntero para asignarlo a las possiciones de la segunda lista

            //asignamos el primer elemento
            asignarElemento(&nuevoElemento->info, auxOrig->info);
            nuevoElemento->sig = NULL;
            dest->head = nuevoElemento;

            TNodo* auxDest = dest->head; //creamos un puntero para iterar por la segunda lista
            auxOrig = auxOrig->sig; // e incrementamos el primer puntero para el siguiente elemento


            while(auxOrig != NULL){// mientras no llegamos al ultimo
                nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //reservamos nuevo hueco en memoria para no reescribir
                asignarElemento(&nuevoElemento->info, auxOrig->info); //asignamos el info del elemento de primera lista a ese nuevo hueco
                nuevoElemento->sig = NULL; //hacemos que sea el último pq no sabemos si habrá otro en la primera lista

                auxDest->sig = nuevoElemento; //ponemos el nuevo elemento al final de la lista
                auxDest = nuevoElemento; //hacemos que el nuevo último elemento sea nuevoElemento

                auxOrig = auxOrig->sig; //incrementamos el primer puntero

            }
            dest->tail = auxDest;
        }
    }

}

void concatenarLista(TLista* uno, TLista* dos){
    if(!esListaVacia(uno)){
        if(!esListaVacia(dos)){
            TLista* nuevaLista = (TLista*) malloc(sizeof(TLista));
            crearListaVacia(nuevaLista);
            asignarLista(dos, nuevaLista); //asignamos la segunda lista a una nueva creada

            TNodo* aux = uno->head;
            while(aux->sig != NULL){ //iteramos hasta el último elemento
                aux = aux->sig;
            }

            aux->sig = nuevaLista->head; //asignamos que el último elemento de la primera lista apunte como siguiente al primer elemento de la nueva lista creada
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
        while(aux->sig!=NULL){ //iterando hasta el último elemento
            if(igualElemento(aux->info, elem)){ //si conincide
                return 1; //devolvemos 1 -> sí, contiene
            }
        }
        return 0;  //si no pos no jsjsj
    }
}
/*

void borrarNPirmeros(int n, TLista *l){
    if(!esListaVacia(l)){
        if(obtenerNumeroElementos(*l)>=n){
            while(n){
                restoLista(l);
                n--;
            }
        }
    }
}

void unique(TLista* l){
    if(!esListaVacia(l)){
        TLista* newList = (TLista*) malloc(sizeof(TLista));
        TNodo* auxNew = *newList;
        TNodo* aux = *l;
        while(aux){
            if(!contieneLista(newList, aux->info)){
                TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
                asignarElemento(&nuevoElemento->info, aux->info);
                nuevoElemento->sig = NULL;
                auxNew->sig = nuevoElemento;
                auxNew = nuevoElemento;
            }
            aux = aux->sig;
        }
        l = newList;
    }
}
void borrarUltimo(TLista* lista){
    if(!esListaVacia(lista)){
        TNodo* aux = *lista;

        if(aux->sig == NULL){
            destruirLista(lista);
        } else {
            while(aux->sig->sig != NULL){
                aux = aux->sig;
            }
            free(aux->sig);
            aux->sig = NULL;
        }
    }
}

void invertir(TLista* l1){
    if(!esListaVacia(l1)){
        TLista* newList = (TLista*) malloc(sizeof(TLista));
        TNodo* aux = *l1;
        while(aux){
            insertarListaFinal(newList, &aux->info);
            aux = aux ->sig;
        }
        *l1 = *newList;
    }
}
void borrarCada(TLista *l, int n){
    if(!esListaVacia(l)){
        if(n == 1){
            destruirLista(l);
        } else {

            if((*l)->sig == NULL){

            }
            TNodo*act = *l;
            TNodo*ant = NULL;
            int cont  = 1;
            while(act!=NULL){
                if(cont%n == 0){
                    ant->sig = act->sig;
                }

                ant = act;
                act = act->sig;
            }
        }
    }
}

*/