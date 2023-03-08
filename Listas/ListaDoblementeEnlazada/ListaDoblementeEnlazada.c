//
// Created by Oleg Fomenkov on 7/3/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "ListaDoblementeEnlazada.h"

int esListaVacia(TLista* l){
    return *l == NULL;
}
void crearListaVacia(TLista* l){
    *l = NULL;
}
void mostrarLista(TLista* l){
    printf("[");
    if(!esListaVacia(l)){
        TNodo* aux = *l;
        while(aux){
            mostrarElemento(aux->info);
            if(aux->sig){
                printf(", ");
            }
            aux = aux->sig;
        }
    }
}

void restoLista(TLista* l){
    if(!esListaVacia(l)){
        TNodo* aux = *l; //el primer elemento es aux
        *l = aux->sig; //*l ahora apunta al siguiente
        if(!esListaVacia(l)){ //si quedan elementos
            (*l)->ant = NULL; //el primer elemento ahora apunta a NULL
        }
        free(aux);
        aux = NULL;
    }
}
void insertarListaCabecera(TLista* l, TElemento* elem){
    TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
    asignarElemento(&nuevoElemento->info, *elem);
    nuevoElemento->sig = (*l);
    nuevoElemento->ant = NULL;
    if(!esListaVacia(l)){//si no está vacía, que el anterior del primer elemento apunte al nuevo elemento
        (*l)->ant = nuevoElemento;
    }
    (*l) = nuevoElemento;

}
void insertarListaFinal(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){
        TNodo* aux = *l;
        while(aux->sig){
            aux = aux->sig; //go till the end babyyy
        }

        //now at final element
        TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
        asignarElemento(&nuevoElemento->info, *elem);
        nuevoElemento->sig = NULL;
        nuevoElemento->ant = aux;
        aux->sig = nuevoElemento;
    }
}

int eliminarElementoLista(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){
        TNodo* aux = *l; //para recorrer la lista
        TNodo* ant = aux;
        int encontrado;
        while(aux){
            if(igualElemento(*elem, aux->info)){
                encontrado = 1;
                if(aux == *l){ //si es el primer elemento
                    restoLista(l);
                    return encontrado;
                } else { //en otro caso
                    ant->sig = aux->sig;
                    if(aux->sig){
                        aux->sig->ant = ant;
                    }

                    free(aux);
                    return encontrado;
                }
            }
            ant = aux;
            aux = aux->sig;

        }
    }
    return 0;
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
    } else { //si hay mas de 1
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
    if(!esListaVacia(l)){
        TNodo* aux = *l;
        while(aux->sig){
            aux = aux->sig;
        }
        asignarElemento(elem, aux->info);
    }
}

void destruirLista(TLista *l){
    if(!esListaVacia(l)){
        while(!esListaVacia(l)){
            restoLista(l);
        }
    }
}

void asignarLista(TLista* orig, TLista* dest){
    destruirLista(dest);
    if(esListaVacia(orig)){
        crearListaVacia(dest);
    } else {
        TNodo* aux = *orig;

        //para primer elemento
        TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
        asignarElemento(&nuevoElemento->info, aux->info);
        *dest = nuevoElemento;
        nuevoElemento->sig = NULL;
        nuevoElemento->ant = NULL;

        TNodo* auxDest = *dest;
        aux = aux->sig;

        while(aux){
            nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
            asignarElemento(&nuevoElemento->info, aux->info);
            nuevoElemento->sig = NULL;
            nuevoElemento->ant = auxDest;
            auxDest->sig = nuevoElemento;
            auxDest = nuevoElemento;
            aux = aux->sig;
        }
    }

}
int contieneLista(TLista* l, TElemento elem){
    if(!esListaVacia(l)){
        TNodo* aux = *l;
        while(aux){
            if(igualElemento(elem, aux->info)){
                return 1;
            }
        }
    }
    return 0;
}
int esIgualLista(TLista* uno, TLista* dos){
    if(esListaVacia(uno) && esListaVacia(dos)){
        return 1;
    } else {
        if((!esListaVacia(uno) && esListaVacia(dos)) || esListaVacia(uno) && !esListaVacia(dos)){
            return 0;
        } else {
            TNodo* auxUno = *uno;
            TNodo* auxDos = *dos;
            if(obtenerNumeroElementos(*uno) == obtenerNumeroElementos(*dos)){
                while(igualElemento(auxUno->info, auxDos->info) && auxUno->sig){
                    auxUno = auxUno->sig;
                    auxDos = auxDos->sig;
                }
                return igualElemento(auxUno->info, auxDos->info);
            }
            return 0;
        }
    }

}
void concatenarLista(TLista* uno, TLista* dos){
    if(!esListaVacia(dos)){

        TNodo* auxUno = *uno;
        while(auxUno->sig){
            auxUno = auxUno->sig;
        }

        TNodo* aux = *dos;
        while(aux){
            TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
            asignarElemento(&nuevoElemento->info, aux->info);
            nuevoElemento->sig = NULL;
            nuevoElemento->ant = auxUno;
            auxUno->sig = nuevoElemento;
            auxUno = nuevoElemento;
            aux = aux->sig;
        }
    }
}


void borrarNPirmeros(int n, TLista *l){
    if(!esListaVacia(l)){
        while(n && !esListaVacia(l)){
            n--;
            restoLista(l);
        }
    }
}