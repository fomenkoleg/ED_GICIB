//
// Created by Oleg Fomenkov on 8/3/22.
//

#ifndef STATICSTACK_TSTATICSTACK_H
#define STATICSTACK_TSTATICSTACK_H

#include <stdio.h>
#include "TElemento.h"
#include <stdlib.h>
#define DIM 5

typedef struct{
    TElemento store[DIM];
    int index;
}TStack;

void createEmptyStack(TStack* s);
int isEmptyStack(TStack* s);
void push(TStack* s, TElemento* elem);
void pop(TStack* s);
void top(TStack* s, TElemento *elem);
int lengthOfStack(TStack* s);
void copyStack(TStack* s1, TStack* s2);
void destroyStack(TStack* s);
void showStack(TStack* s);

#endif //STATICSTACK_TSTATICSTACK_H
