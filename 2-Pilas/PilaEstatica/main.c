#include <stdio.h>
#include "TStaticStack.h"

int main() {
    printf("Create new stack\n");
    TStack* s1 = (TStack*) malloc(sizeof(TStack));
    createEmptyStack(s1);
    showStack(s1);
    printf("\n");

    printf("Try filling the stack up with elements:\n");
    TElemento elem1;
    createElement(&elem1, 0);
    for (int i = 0; i < DIM; ++i) {
        push(s1, &elem1);
    }
    showStack(s1);
    printf("\n");

    printf("Try adding another element:\n");
    TElemento elem2;
    createElement(&elem2, 1);
    push(s1, &elem2);
    printf("\n");

    printf("Try to empty the stack:\n");
    destroyStack(s1);
    showStack(s1);
    printf("\n");

    printf("Try to pop from the stack:\n");
    pop(s1);
    printf("\n");

    printf("Fill the stack with some elements:\n");
    TElemento elem3;
    createElement(&elem3, 2);
    push(s1, &elem3);
    showStack(s1);
    createElement(&elem3, 7);
    push(s1, &elem3);
    showStack(s1);
    createElement(&elem3, 1);
    push(s1, &elem3);
    showStack(s1);
    printf("\n");

    printf("Show the top element of the stack: ");
    top(s1, &elem3);
    showElement(&elem3);
    printf("\n");

    printf("The length of stack 1 is: %d\n", lengthOfStack(s1));
    printf("\n");

    printf("Create new stack 2: \n");
    TStack* s2 = (TStack*) malloc(sizeof(TStack));
    createEmptyStack(s2);
    showStack(s2);
    printf("\n");

    printf("Copy stack 1 to stack 2: \n");
    copyStack(s1, s2);
    showStack(s2);
    printf("\n");

    printf("Destroy stack 1: \n");
    destroyStack(s1);
    printf("Length of s1 is: %d", lengthOfStack(s1));

    free(s1);
    free(s2);
    return 0;
}
