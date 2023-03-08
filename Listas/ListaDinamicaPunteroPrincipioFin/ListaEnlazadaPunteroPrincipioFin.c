//
// Created by Oleg Fomenkov on 7/3/23.
//

#include "ListaEnlazadaPunteroPrincipioFin.h"
#include <stdio.h>
#include <stdlib.h>

//(*l).head es lo mismo que l->head

int esListaVacia(TLista* l){
    return (*l).head == NULL && (*l).tail == NULL;
}
void crearListaVacia(TLista* l){
    (*l).head=NULL;
    (*l).tail = NULL;
}
void mostrarLista(TLista* l){
    printf("[");
    if(!esListaVacia(l)){
        TNodo* aux = (*l).head;
        while(aux != NULL) {
            mostrarElemento(aux->info);
            if(aux!=(*l).tail){
                printf(", ");
            }
            aux = aux->sig;
        }
    }
    printf("]");
}

void restoLista(TLista* l){
    if(!esListaVacia(l)){
        TNodo* aux = (*l).head;
        if(!l->head->sig){ // si solo es un elemento, que tail sea NULL
            l->tail = NULL;
        }
        (*l).head = (*l).head->sig; //asigna el puntero head al siguiente del head anterior
        free(aux); //libera el anterior primer elemento
    }
}
void insertarListaCabecera(TLista* l, tElemento* elem){
    //creamos nuevo elemento
    TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
    asignarElemento(&nuevoElemento->info, *elem);
    if(esListaVacia(l)){ //si está vacía, añadimos al tail un puntero a ese nuevo elemento
        l->tail = nuevoElemento;
    }
    nuevoElemento->sig = l->head;//hacemos que apunte al mismo que el head anterior
    l->head = nuevoElemento;
}
void insertarListaFinal(TLista* l, tElemento* elem){
    if(esListaVacia(l)){
        insertarListaCabecera(l, elem);
    } else {
        TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
        asignarElemento(&nuevoElemento->info, *elem);

        nuevoElemento->sig = NULL;//hacemos que apunte al mismo que el head anterior
        l->tail->sig = nuevoElemento;
        l->tail = nuevoElemento;
    }

}

int eliminarElementoLista(TLista* l, tElemento* elem){
    if(!esListaVacia(l)){
        TNodo* aux = l->head; //para recorrer la lista
        TNodo* ant = NULL;
        int encontrado = 0;
        while(!encontrado && aux){
            if(igualElemento(*elem, aux->info)){
                encontrado = 1;
                if(aux == l->head){
                    restoLista(l);
                    return encontrado;
                } else {
                    if(aux==l->tail){
                        l->tail = ant;
                    }
                    ant->sig = aux->sig;
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
void obtenerPrimeroLista(TLista* l, tElemento* elem){
    if(!esListaVacia(l)){
        asignarElemento(elem, l->head->info);
    }
}
int obtenerNumeroElementos(TLista l){
    if(!esListaVacia(&l)){
        TNodo* aux = l.head;
        int cont = 0;
        while(aux){
            cont++;
            aux=aux->sig;
        }
        return cont;
    }
    return 0;
}


void obtenerUltimoLista(TLista* l, tElemento* elem){
    if(!esListaVacia(l)){
        asignarElemento(elem, l->tail->info);
    }
}

void destruirLista(TLista *l){
    if(!esListaVacia(l)){
        while(!esListaVacia(l)){
            restoLista(l);
        }
    }
}

int contieneLista(TLista* l, tElemento elem){
    if(!esListaVacia(l)){
        TNodo* aux = l->head;
        while(aux){
            if(igualElemento(elem, aux->info)){
                return 1;
            }
            aux = aux->sig;
        }
    }
    return 0;
}

void asignarLista(TLista* orig, TLista* dest){
    destruirLista(dest);
    if(esListaVacia(orig)){
        crearListaVacia(dest);
    } else {
        destruirLista(dest);

        TNodo* aux = orig->head;

        //para primer elemento
        TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
        asignarElemento(&nuevoElemento->info, aux->info);
        dest->head = nuevoElemento;
        dest->tail = nuevoElemento;
        nuevoElemento->sig = NULL;

        TNodo* auxDest = dest->head;
        aux = aux->sig;
        while(aux){
            nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
            asignarElemento(&nuevoElemento->info, aux->info);
            nuevoElemento->sig = NULL;
            auxDest->sig = nuevoElemento;
            dest->tail = nuevoElemento;
            auxDest = nuevoElemento;
            aux = aux->sig;
        }
    }
}
int esIgualLista(TLista* uno, TLista* dos){
    if(esListaVacia(uno) && esListaVacia(dos)){
        return 1;
    } else {
        if((!esListaVacia(uno) && esListaVacia(dos)) || esListaVacia(uno) && !esListaVacia(dos)){
            return 0;
        } else {
            TNodo* auxUno = uno->head;
            TNodo* auxDos = dos->head;
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
        TNodo* aux = dos->head;
        while(aux->sig){
            insertarListaFinal(uno, &aux->info);
            aux = aux->sig;
        }
        insertarListaFinal(uno, &aux->info);
        uno->tail = aux;
    }
}


void borrarNPirmeros(int n, TLista *l){
    if(!esListaVacia(l)){
        while(n){
            n--;
            restoLista(l);
        }
    }
}

/*

void unique(TLista* l);
void borrarUltimo(TLista* lista);
void invertir(TLista* l1);
void borrarCada(TLista *l, int n);
int listaContieneLista(TLista *original, TLista* sublista);
int listaContieneListaEnOrden(TLista *original, TLista* sublista);
*/