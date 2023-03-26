//
// Created by Oleg Fomenkov on 19/2/22.
//

#include "TElemento.h"

void createElement(TElemento* elem, int num){
    *elem = num;
}

void showElement(TElemento* elem){
    printf("%d", *elem);
}

void assignElement(TElemento* orig,TElemento* dest){
    *dest = *orig;
}

int isEqualElement(TElemento* elem1, TElemento* elem2){
    return (*elem1 == *elem2);
}