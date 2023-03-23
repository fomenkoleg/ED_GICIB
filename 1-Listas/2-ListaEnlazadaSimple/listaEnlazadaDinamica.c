//
// Created by Oleg Fomenkov on 28/2/23.
//

#include "listaEnlazadaDinamica.h"
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
        TNodo* aux = *l;
        *l = (*l)->sig;
        free(aux);
        aux = NULL;
    }
}
void insertarListaCabecera(TLista* l, TElemento* elem){
    TNodo *aux = (TNodo*) malloc(sizeof(TNodo));
    asignarElemento(&aux->info, *elem);
    aux->sig = *l;
    *l = aux;
}
void insertarListaFinal(TLista* l, TElemento* elem){
    if(esListaVacia(l)){
        insertarListaCabecera(l , elem); //si es vacio, simplemente insertar
    } else {
        TNodo* aux = *l; //creamos un puntero temporal que vamos a mover
        while(aux->sig != NULL){ //movemos el puntero hasta encontrar el último elemento
            aux = aux->sig;
        }

        TNodo* nElem = (TNodo*) malloc(sizeof(TNodo)); //creamos el nuevo elemento
        asignarElemento(&nElem->info, *elem); //asignamos el valor que queremos a ese elemento

        nElem->sig = NULL; //hacemos que sea el último elemento
        aux->sig = nElem; //hacemos que el antiguo último apunte al nuevo elemento

    }
}
int eliminarElementoLista(TLista* l, TElemento* elem) {
    if (esListaVacia(l)) {
        return 0;
    } else {
        TNodo *aux = *l; //creamos un puntero para poder iterar por la lista
        int deleted = 0; //de momento no está borrado -> borrado a 0, false]
        if (aux->sig == NULL) { //si ese elemento es el único
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
                TNodo *aux2 = aux->sig; //hacemos que aux2 sea el 2º elemento
                while (!esListaVacia(&aux)) { //mientras no sea null
                    if (igualElemento(aux2->info, *elem)) { //comparamos el elem con los elementos de la lista
                        aux->sig = aux2->sig;  //hacemos que el anterior apunte al siguiente del actual
                        free(aux2); //liberamos el actual
                        deleted = 1; //encontramos el elemento a borrar
                        return deleted;
                    }
                    aux = aux->sig; //movemos el puntero
                    if (!esListaVacia(&aux2)) { //y, si no apunta a NULL
                        aux2 = aux2->sig; // movemos el siguiente puntero también
                    }
                }
                return 0;
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
        TNodo* aux = *l;
        while(aux->sig != NULL){ //iteramos hasta llegar al ultimo
            aux = aux->sig;
        }
        asignarElemento(elem, aux->info); //y asignamos el ultimo
    }
}

void asignarLista(TLista* orig, TLista* dest){

    if(orig != dest){
        destruirLista(dest); //pos si acaso destruimos la segunda lista
        if(esListaVacia(orig)){
            crearListaVacia(dest);
        } else {
            TNodo* auxOrig = *orig;
            TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //creamos un puntero para asignarlo a las possiciones de la segunda lista

            //asignamos el primer elemento
            asignarElemento(&nuevoElemento->info, auxOrig->info);
            nuevoElemento->sig = NULL;
            *dest = nuevoElemento;

            TNodo* auxDest = *dest; //creamos un puntero para iterar por la segunda lista
            auxOrig = auxOrig->sig; // e incrementamos el primer puntero para el siguiente elemento


            while(auxOrig != NULL){// mientras no llegamos al ultimo
                nuevoElemento = (TNodo*) malloc(sizeof(TNodo)); //reservamos nuevo hueco en memoria para no reescribir
                asignarElemento(&nuevoElemento->info, auxOrig->info); //asignamos el info del elemento de primera lista a ese nuevo hueco
                nuevoElemento->sig = NULL; //hacemos que sea el último pq no sabemos si habrá otro en la primera lista

                auxDest->sig = nuevoElemento; //ponemos el nuevo elemento al final de la lista
                auxDest = nuevoElemento; //hacemos que el nuevo último elemento sea nuevoElemento

                auxOrig = auxOrig->sig; //incrementamos el primer puntero

            }
        }
    }

}

void destruirLista(TLista *l){
    while(!esListaVacia(l)){
        restoLista(l);
    }
}


void concatenarLista(TLista* uno, TLista* dos){
    if(!esListaVacia(uno)){
        if(!esListaVacia(dos)){
            TLista* nuevaLista = (TLista*) malloc(sizeof(TLista));
            //en mi código de 1º tengo TLista nuevaLista sin el puntero, no se si funcionará de momento pero eso espero
            crearListaVacia(nuevaLista);
            asignarLista(dos, nuevaLista); //asignamos la segunda lista a una nueva creada

            TNodo* aux = *uno;
            while(aux->sig != NULL){ //iteramos hasta el último elemento
                aux = aux->sig;
            }

            aux->sig = *nuevaLista; //asignamos que el último elemento de la primera lista apunte como siguiente al primer elemento de la nueva lista creada

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

