//
// Created by Oleg Fomenkov on 19/3/22.
//
#include <stdio.h>
#include "TStaticQueue.h"


void createEmptyQueue(TQueue* q){
    q->occupied = 0;
    q->first = 0;
    q->last = -1;
}
int isEmptyQueue(TQueue* q){
    return (q->occupied == 0);
}

void enqueue(TQueue* q, TElemento* elem){
    if(q->occupied == DIM){
        printf("The queue is full.\n");
    } else {
        q->last = (q->last + 1) % DIM;
        assignElement(elem, &(q->store[q->last]));
        q->occupied++;
    }
}
void dequeue(TQueue* q){
    if(!isEmptyQueue(q)){
        q->first = (q->first + 1) % DIM;
        q->occupied--;

    } else {
        printf("The queue is empty.\n");
    }
}
void firstInQueue(TQueue* q, TElemento* elem){
    if(!isEmptyQueue(q)){
        assignElement(&(q->store[q->first]), elem);
    } else {
        printf("The queue is empty.\n");
    }
}

int lengthOfQueue(TQueue* q){
    return (q->occupied);
}

void assignQueue(TQueue* orig, TQueue* dest){
    if(!isEmptyQueue(orig)){
        destroyQueue(dest);
        dest->first = orig->first;
        for (int i = orig->first; i <= orig->last; i = (i + 1) % DIM) {
            assignElement(&(orig->store[i]), &(dest->store[i]));
            dest->occupied++;
            dest->last = (dest->last + 1) % DIM;
        }
    } else {
        printf("The first queue is empty; nothing to copy.\n");
    }
}
void destroyQueue(TQueue* q){
    createEmptyQueue(q);
}

void showQueue(TQueue* q){
    printf("[");
    if(!isEmptyQueue(q)){
        int  counter = 0;
        int pos = q->first;
        while(counter < q->occupied){
            showElement(&(q->store[pos]));
            counter++;
            pos = (pos + 1) % DIM;
            if(counter < q->occupied){printf(", ");}
        }
    }
    printf("]\n");
}