//
// Created by Oleg Fomenkov on 8/3/22.
//

#include "TStaticStack.h"

void createEmptyStack(TStack* s){
    s->index = -1;
}
int isEmptyStack(TStack* s){
    return(s->index == -1);
}
void push(TStack* s, TElemento* elem){
    if(s->index < DIM-1){
        s->index++;
        assignElement(elem, &(s->store[s->index]));
    } else {
        printf("Stack Overflow\n");
    }
}

void pop(TStack* s){
    if(!isEmptyStack(s)){
        s->index--;
    } else {
        printf("Stack empty\n");
    }
}

void top(TStack* s, TElemento *elem){
    assignElement(&(s->store[s->index]), elem);
}

int lengthOfStack(TStack* s){
    return (s->index+1);
}

void copyStack(TStack* s1, TStack* s2){
    createEmptyStack(s2);
    if(!isEmptyStack(s1)){
        TStack* aux = (TStack*) malloc(sizeof(TStack));
        createEmptyStack(aux);
        for (int i = 0; i < lengthOfStack(s1); ++i) {
            push(aux, &(s1->store[s1->index-i]));
        }
        for (int i = 0; i < lengthOfStack(s1); ++i) {
            push(s2, &(aux->store[aux->index-i]));
        }
        free(aux);
    }
}

void destroyStack(TStack* s){
    createEmptyStack(s);
}

void showStack(TStack* s){
    printf("[");
    if(!isEmptyStack(s)){
        for (int i = 0; i < lengthOfStack(s); ++i){
            showElement(&(s->store[s->index-i]));
            if(s->index-i > 0){
                printf(", ");
            }
        }
    }
    printf("]\n");
}