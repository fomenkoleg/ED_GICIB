//
// Created by alfon on 09/03/2021.
//

#include "TConjuntoDinamico.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h" //para funcion time

void crearConjuntoVacio (TConjunto* l){
    *l=NULL;
}

int pertenece (TConjunto* l,TElemento* e){
        TNodoC* aux =*l;
        int encontrado =0;
        while ((!encontrado)&&(aux!=NULL)){
            encontrado = igualElemento(aux->info,*e);
            if(!encontrado){
                aux=aux->sig;
            }
        }
    return encontrado;
}

void poner (TConjunto* l,TElemento* e){ //Inserta un elemento en la cabecera de la Conjunto
    if(!pertenece(l,e)){
        TNodoC* aux = (TNodoC*) malloc(1*sizeof (TNodoC));
        aux->sig = *l;
        asignarElemento(&aux->info,*e);
        *l=aux;
        }
}

void elegir(TConjunto* l,TElemento* e){//Condicion: Conjunto No vacia
    if(!esConjuntoVacio(l)){
        int cantidad = cardinal(l);
        srand(time(NULL));
        int r =rand()%cantidad;
        TNodoC * aux =*l;
        int i=0;
        while (i!=r){
            aux=aux->sig;
            i++;
        }
        asignarElemento(e,aux->info);
   }
    else{
        printf("Conjunto vacio");
    }
}

void mostrarConjunto (TConjunto l){
    printf("(");
    if(!esConjuntoVacio(&l)){
        TNodoC* aux = l;
        while(aux!=NULL){
            mostrarElemento(aux->info);
            if(aux->sig != NULL){
                printf(", ");
            }
            aux = aux->sig;
        }
    }

    printf(")\n");
}


int quitar (TConjunto* l,TElemento* e){ //borra la primera aparicion de e
    if (esConjuntoVacio(l)) {
        return 0;
    } else {
        TNodoC *aux = *l; //creamos un puntero para poder iterar por la lista
        int deleted = 0; //de momento no está borrado -> borrado a 0, false]
        if (aux->sig == NULL) { //si ese elemento es el único
            if (igualElemento(aux->info, *e)) { //si ese único elemento es el que queremos borrar
                *l = NULL; //entonces asignamos la lista como vacía;
                free(aux); //liberamos el elemento que queremos borrar
                aux = NULL; //y asignamos su puntero a NULL como medida de seguridad
                return 1;
            }
            return 0;
        } else {
            //3 casos, primero, último, en el medio
            //empezaremos con primero

            if (igualElemento(aux->info, *e)) {
                *l = (*l)->sig;
                aux = NULL;
                free(aux);
                return 1;
            } else {
                TNodoC *aux2 = aux->sig; //hacemos que aux2 sea el 2º elemento
                while (!esConjuntoVacio(&aux)) { //mientras no sea null
                    if (igualElemento(aux2->info, *e)) { //comparamos el elem con los elementos de la lista
                        aux->sig = aux2->sig;  //hacemos que el anterior apunte al siguiente del actual
                        free(aux2); //liberamos el actual
                        deleted = 1; //encontramos el elemento a borrar
                        return deleted;
                    }
                    aux = aux->sig; //movemos el puntero
                    if (!esConjuntoVacio(&aux2)) { //y, si no apunta a NULL
                        aux2 = aux2->sig; // movemos el siguiente puntero también
                    }
                }
                return 0;
            }
        }
    }

}



void unir (TConjunto* l1, TConjunto* l2, TConjunto* u){
    asignarConjunto(u,l1);
    TNodoC* aux=*l2;
        while (aux!=NULL){
            poner(u, &aux->info);
            aux=aux->sig;
        }
}

void interseccion (TConjunto* l1, TConjunto* l2, TConjunto* i){
    if(esConjuntoVacio(l1) || esConjuntoVacio(l2)){
        crearConjuntoVacio(i);
    } else {
        crearConjuntoVacio(i);
        TNodoC* aux1 = *l1;
        while(aux1!=NULL){
            if(pertenece(i, &aux1->info)){
                poner(l2, &aux1->info);
            }
            aux1 = aux1->sig;
        }
    }
}

void diferencia (TConjunto* l1, TConjunto* l2, TConjunto* d){
    if(esConjuntoVacio(l1)){
        if(esConjuntoVacio(l2)){
            crearConjuntoVacio(d);
        } else {
            asignarConjunto(d, l2);
        }
    } else if (esConjuntoVacio(l2)){
        asignarConjunto(d, l1);
    } else {
        crearConjuntoVacio(d);
        TNodoC* aux1 = *l1;
        while(aux1!=NULL){
            if(!pertenece(l2, &aux1->info)){
                poner(d, &aux1->info);
            }
            aux1 = aux1->sig;
        }
    }
}


int esSubconjunto (TConjunto* l1, TConjunto* l2){//l2 esta dentro de l1?
    if(esConjuntoVacio(l2)){
        return 1;
    } else {
        TNodoC* aux = *l1;
        while(aux!= NULL){
            if(!pertenece(l1, &aux->info)){
                return 0;
            }
            aux=aux->sig;
        }
        return 1;
    }
}

int esConjuntoVacio (TConjunto* l) {
    return *l == NULL;
}

int cardinal ( TConjunto* l){
    int c = 0;
    if(!esConjuntoVacio(l)){
        TNodoC* aux = *l;
        while(aux!=NULL){
            c++;
            aux=aux->sig;
        }
    }
    return c;
}

    
int igualConjunto (TConjunto* l1, TConjunto* l2){
    if(esConjuntoVacio(l1) && esConjuntoVacio(l2)){
        return 1;
    } else if ((esConjuntoVacio(l1) && !esConjuntoVacio(l2) || (!esConjuntoVacio(l1) && esConjuntoVacio(l2)))){
        return 0;
    } else {
        TNodoC* aux1 = *l1;
        TNodoC* aux2 = *l2;
        if(cardinal(l1) == cardinal(l2)){
           while(aux1!=NULL){
               if(igualElemento(aux1->info, aux2->info)){
                   aux1=aux1->sig;
               } else {
                   return 0;
               }
           }
           return 1;
        }
        return 0;
    }
}



void asignarConjunto (TConjunto* dest, TConjunto* orig){
    if(orig != dest){
        destruirConjunto(dest); //pos si acaso destruimos la segunda lista
        if(esConjuntoVacio(orig)){
            crearConjuntoVacio(dest);
        } else {
            TNodoC* auxOrig = *orig;
            TNodoC* nuevoElemento = (TNodoC*) malloc(sizeof(TNodoC)); //creamos un puntero para asignarlo a las possiciones de la segunda lista

            //asignamos el primer elemento
            asignarElemento(&nuevoElemento->info, auxOrig->info);
            nuevoElemento->sig = NULL;
            *dest = nuevoElemento;

            TNodoC* auxDest = *dest; //creamos un puntero para iterar por la segunda lista
            auxOrig = auxOrig->sig; // e incrementamos el primer puntero para el siguiente elemento


            while(auxOrig != NULL){// mientras no llegamos al ultimo
                nuevoElemento = (TNodoC*) malloc(sizeof(TNodoC)); //reservamos nuevo hueco en memoria para no reescribir
                asignarElemento(&nuevoElemento->info, auxOrig->info); //asignamos el info del elemento de primera lista a ese nuevo hueco
                nuevoElemento->sig = NULL; //hacemos que sea el último pq no sabemos si habrá otro en la primera lista

                auxDest->sig = nuevoElemento; //ponemos el nuevo elemento al final de la lista
                auxDest = nuevoElemento; //hacemos que el nuevo último elemento sea nuevoElemento

                auxOrig = auxOrig->sig; //incrementamos el primer puntero

            }
        }
    }

}

void restoConjunto(TConjunto *l){
    if(!esConjuntoVacio(l)){
        TNodoC* aux = *l;
        *l=(*l)->sig;
        free(aux);
        aux=NULL;
    }
}


void destruirConjunto(TConjunto* l){
    while(!esConjuntoVacio(l)){
        restoConjunto(l);
    }
}