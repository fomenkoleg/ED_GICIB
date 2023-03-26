//
// Created by Oleg Fomenkov on 19/2/22.
//

#include "TListaCircularEstatica.h"

void createEmptyList(TLista *l){
    l->occupied = 0;
    l->start = 0;
    l->end = -1;
}

int isEmptyList(TLista *l){
    return (l->occupied == 0);
}

int lengthOfList(TLista *l){
    return l->occupied;
}

void firstInList(TLista *l, TElemento* elem){
    if(!isEmptyList(l)){
        assignElement(&l->store[(l->start-1)%DIM], elem);
    }
}

void lastInList(TLista* l, TElemento* elem){
    if(!isEmptyList(l)){
        assignElement(&(l->store[(l->end)]), elem);
    }
}

void subtractList(TLista* l){
    if(l->end != l->start){ //if the list isn't full
        l->start = (l->start - 1) % DIM; //delete element at (start-1)
        l->occupied--;
    } else if (l->occupied){
        l->end = (l->end - 1) % DIM;
    } else {
        printf("Sorry, list is empty.\n");
    }
}

void insertInList(TElemento* elem, TLista* l){
    if(l->occupied != DIM){ // if the list isn't full
        if(l->end ==-1){ // if the list is empty, assign its final element to 0
            l->end=0;
        }
        assignElement(elem,&(l->store[l->start])); //assign element to the starting position
        l->start = (l->start+1) % DIM; //increment start; if start is over DIM, do MOD DIM
        l->occupied++;
    } else {
        printf("Sorry, list is full.\n");
    }
}

void insertFinalList(TElemento *elem, TLista* l){
    if (l->occupied != DIM) {
        if (l->end == -1) { //if list is empty
            l->end = 0;
            l->start = 1;

        } else if (l->occupied != DIM) { //if it is not empty and not full
            if (l->end == 0) {
                l->end = DIM - 1;
            } else {
                l->end--;
            }
            assignElement(elem, &(l->store[l->end]));
            l->occupied++;

        } else {
            printf("Sorry, list is full.\n");
        }
    }
}

void showList(TLista* l) {
    int aux = l->start;
    printf("[");
    int count = 0;
    while (l->end != aux && l->end != -1) {
        if (aux == 0) {
            aux = DIM - 1;
        } else {
            aux = (aux - 1) % DIM;
        }
        showElement(&l->store[aux]);
        count++;
        if(count < l->occupied){
            printf(", ");
        }
    }
    printf("]\n");
}

void destroyList(TLista* l){
    if(!isEmptyList(l)){
        l->start = 0;
        l->end = -1;
        l->occupied = 0;
    }
}

void assignList(TLista* orig, TLista* dest){
    int aux_orig = orig->end;
    if(!isEqualList(orig, dest)){
        destroyList(dest);
        if (!isEmptyList(orig)){
            if (dest->end == -1){
                dest->end = 0;
            }
            while (aux_orig != orig->start) {
                insertInList(&orig->store[aux_orig], dest);
                aux_orig = (aux_orig + 1) % DIM;
            }
            dest->occupied =  orig->occupied;
        }
    }
}

int containsList(TElemento* elem, TLista* l){
    int aux = l->start;
    int encontrado = 0;
    if(!isEmptyList(l)){
        while (l->start != l->end && !encontrado){
            encontrado = isEqualElement(&l->store[aux], elem);
            if(aux == 0)
                aux = DIM - 1;
            else
                aux--;
        }
    }
    return encontrado;
}

int isEqualList(TLista *l1, TLista *l2){
    if(isEmptyList(l1) && isEmptyList(l2)){
        return 1;
    } else if (isEmptyList(l1) ^ isEmptyList(l2)){
        return 0;
    } else {
        int diff = 0;
        if(l1->occupied == l2->occupied){
            diff = 1;
            int aux1 = l1->end;
            int aux2 = l2->end;
            while (aux1 != l1->start && diff != 0) {
                diff = isEqualElement(&(l1->store[aux1]), &(l2->store[aux2]));
                aux1 = (aux1 + 1) % DIM;
                aux2 = (aux2 + 1) % DIM;
            }
        }
        return diff;
    }
}

int deleteElemFromList(TElemento *elem, TLista* l){
    int deleted = 0;
    int aux = l->end;
    while (aux != l->start && deleted == 0){
        if(isEqualElement(&(l->store[aux]), elem)){
            deleted = 1;
            l->start = (l->start-1) % DIM;
            l->occupied--;
        }
        aux = (aux + 1) % DIM;
    }
    return deleted;
}

void concatenateLists(TLista* l1, TLista* l2){
    int aux = l2->start;
    if(lengthOfList(l1) + lengthOfList(l2) <= DIM){
        if(!isEmptyList(l2)){
            while (aux != l2->end){
                if(aux == 0)
                    aux = DIM - 1;
                else
                    aux--;
                if(l1->end == 0)
                    l1->end = DIM - 1;
                else
                    l1->end--;
                assignElement(&l2->store[aux], &l1->store[l1->end]);
            }
        }
        l1->occupied = l1->occupied + lengthOfList(l2);
    }
}