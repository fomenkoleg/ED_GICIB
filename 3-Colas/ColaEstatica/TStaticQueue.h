//
// Created by Oleg Fomenkov on 19/3/22.
//

#ifndef STATICQUEUE_TSTATICQUEUE_H
#define STATICQUEUE_TSTATICQUEUE_H
#include "TElemento.h"

#define DIM 3

typedef struct {
    int store[DIM];
    int occupied, first, last;
}TQueue;

void createEmptyQueue(TQueue* q);
int isEmptyQueue(TQueue* q);
void enqueue(TQueue* q, TElemento* elem);
void dequeue(TQueue* q);
void firstInQueue(TQueue* q, TElemento* elem);
int lengthOfQueue(TQueue* q);
void assignQueue(TQueue* orig, TQueue* dest);
void destroyQueue(TQueue* q);
void showQueue(TQueue* q);

#endif //STATICQUEUE_TSTATICQUEUE_H
