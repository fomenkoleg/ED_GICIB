//
// Created by Oleg Fomenkov on 19/2/22.
//

#include "TListaEstatica.h"

void createEmptyList(TLista *l){
    l->index = -1;
}

int isEmptyList(TLista *l){
    return (l->index == -1);
}

int lengthOfList(TLista *l){
    return l->index+1;
}

void firstInList(TLista *l, TElemento* elem){
    if(!isEmptyList(l)){
        assignElement(&l->store[l->index], elem);
    }
}

void subtractList(TLista* l){
    if(!isEmptyList(l)){
        l->index--;
    }
}

void lastInList(TLista* l, TElemento* elem){ //assigns to elem what is in the first position
    if(!isEmptyList(l)){
        assignElement(&l->store[0], elem);
    }
}

void destroyList(TLista* l){
    l->index = -1;
}

void showList(TLista* l){
    if (isEmptyList(l)){
        printf("[]\n");
    } else {
        printf("[");
        for (int i = l->index; i > -1; --i) {
            showElement(&l->store[i]);
            if(i>0){printf(", ");}
        }
        printf("]\n");
    }
}

void insertInList(TElemento* elem, TLista* l){
    if(lengthOfList(l)<DIM){
        l->index++;
        assignElement(elem, &l->store[l->index]);
    } else {
        printf("ERROR: La lista está llena\n");
    }
}

void assignList(TLista* orig, TLista* dest){
    if(orig != dest){
        dest->index = orig->index;
        for (int i = 0; i < lengthOfList(orig); ++i) {
            assignElement(&orig->store[i], &dest->store[i]);
        }
    }
}

void insertFinalList(TElemento *elem, TLista* l){
    if(lengthOfList(l)<DIM){
        for (int i = l->index; i > -1; --i) {
            assignElement(&l->store[i], &l->store[i+1]);
        }
        assignElement(elem, &l->store[0]);
        l->index++;
    } else {
        printf("ERROR: La lista está llena\n");
    }
}

int containsList(TElemento* elem, TLista* l){
    int found = 0;
    int i = l->index;
    while (!found && i>-1){
        found = isEqualElement(&l->store[i], elem);
        i--;
    }
    return found;
}

int isEqualList(TLista *l1, TLista *l2){
    if(lengthOfList(l1) == lengthOfList(l2)){
        int i = 0;
        while (i<l1->index && isEqualElement(&l1->store[i], &l2->store[i])){
            i++;
        }
        return isEqualElement(&l1->store[i], &l2->store[i]);
    } else {
        return 0;
    }
}

int deleteElemFromList(TElemento *elem, TLista* l){
    int found = 0;
    int i = l->index;
    while (!found && (i>-1)){
        found = isEqualElement(&l->store[i], elem);
        i--;
    }

    if(found){
        for (int j = i; j < l->index; ++j) {
            assignElement(&l->store[j+1], &l->store[j]);
        }
        l->index--;
    }
    return found;
}

void concatenateLists(TLista* l1, TLista* l2){
    if(lengthOfList(l1) + lengthOfList(l2) <= DIM){
        int offset = lengthOfList(l2);
        for (int i = l1->index; i > -1; --i){
            assignElement(&l1->store[i], &l1->store[i+offset]);
        }
        if (l1 != l2){
            for (int i = l2->index; i > -1; --i) {
                assignElement(&l2->store[i], &l1->store[i]);
            }
        }
        l1->index += offset;
    } else {
        printf("ERROR: No hay sitio para concatenar la lista\n");
    }
}