#include <stdio.h>
#include "TStaticQueue.h"
int main() {
    TElemento a1, a2, a3;

    printf("Create elements 3, 6, 7.\n\n");
    createElement(&a1, 3);
    createElement(&a2, 6);
    createElement(&a3, 7);

    printf("Create queue q1.\n");
    TQueue q1;
    createEmptyQueue(&q1);
    showQueue(&q1);

    printf("\nFill the queue with elements:\n");
    enqueue(&q1, &a1);
    showQueue(&q1);
    enqueue(&q1, &a2);
    showQueue(&q1);
    enqueue(&q1, &a3);
    showQueue(&q1);

    printf("\nTry adding a new element:\n");
    enqueue(&q1, &a1);
    showQueue(&q1);

    printf("\nTry deleting elements one by one:\n");
    dequeue(&q1);
    showQueue(&q1);
    dequeue(&q1);
    showQueue(&q1);
    dequeue(&q1);
    showQueue(&q1);

    printf("\nTry deleting more elements:\n");
    dequeue(&q1);
    showQueue(&q1);

    printf("\nIs the queue q1 empty? %d\n", isEmptyQueue(&q1));

    printf("\nOnce again, fill the queue with elements:\n");
    enqueue(&q1, &a1);
    showQueue(&q1);
    enqueue(&q1, &a2);
    showQueue(&q1);
    printf("Is the queue q1 empty? %d\n", isEmptyQueue(&q1));

    printf("\nCreate new queue q2: \n");
    TQueue q2;
    createEmptyQueue(&q2);
    showQueue(&q2);

    printf("\nTry copying q1 into q2. q2 now becomes: \n");
    assignQueue(&q1, &q2);
    showQueue(&q2);

    printf("\nTry dequeueing q2: \n");
    dequeue(&q2);
    showQueue(&q2);

    printf("Try enqueueing q2: \n");
    enqueue(&q2, &a1);
    showQueue(&q2);

    printf("\nTry deleting q1: \n");
    destroyQueue(&q1);
    showQueue(&q1);

    printf("\nTrye copying q1 to q2: \n");
    assignQueue(&q1, &q2);

    printf("\nThe lenght of q1 is: %d\nThe length of q2 is: %d", lengthOfQueue(&q1), lengthOfQueue(&q2));
    return 0;
}
