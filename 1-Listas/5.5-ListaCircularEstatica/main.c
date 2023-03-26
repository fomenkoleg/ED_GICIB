#include <stdio.h>
#include "TListaCircularEstatica.h"

int main() {
    TLista l;
    printf("Crear lista l\n");
    createEmptyList(&l);
    printf("Mostrar lista l (vacia)\n");
    showList(&l);
    TElemento e1;
    printf("Insertar elemento 2 en l\n");
    createElement(&e1, 2);
    insertInList(&e1, &l);
    printf("Mostrar lista l (1 elemento)\n");
    showList(&l);
    TElemento e2;
    printf("Insertar elemento 5 en l\n");
    createElement(&e2, 5);
    insertInList(&e2, &l);
    printf("Mostrar lista l (2 elementos)\n");
    showList(&l);
    printf("Eliminar elemento 5 de l\n");
    deleteElemFromList(&e2, &l);
    printf("Mostrar lista l (1 elemento)\n");
    showList(&l);
    printf("Insertar elemento 2 de l\n");
    insertInList(&e1, &l);
    printf("Mostrar lista l (2 elementos)\n");
    showList(&l);
    printf("Insertar elemento 5 en l\n");
    insertInList(&e2, &l);
    printf("Mostrar lista l (3 elementos)\n");
    showList(&l);
    TLista l2;
    printf("Crear lista l2\n");
    createEmptyList(&l2);
    printf("Mostrar lista l2 (vacia)\n");
    showList(&l2);

    printf("Copiamos l en l2\n");
    assignList(&l, &l2);
    printf("Mostrar lista l2 (3 elementos)\n");
    showList(&l2);
    TElemento e3;
    createElement(&e3, 4);
    printf("Insertar final elemento 4 en l\n");
    insertFinalList(&e3, &l);
    printf("Mostrar lista l (4 elementos)\n");
    showList(&l);
    printf("Primero lista l\n");
    TElemento aux;
    firstInList(&l, &aux);
    showElement(&aux);
    printf("\nUltimo lista l\n");
    lastInList(&l, &aux);
    showElement(&aux);
    printf("\nLa longitud de l es %d\n", lengthOfList(&l));
    printf("l es igual a l2? %d\n", isEqualList(&l, &l2));
    printf("l contiene 4? %d\n", containsList(&e3, &l));
    printf("Concatena l2 a l\n");
    concatenateLists(&l, &l2);
    showList(&l);
    printf("Destruimos las listas\n");
    destroyList(&l);
    destroyList(&l2);
    printf("Mostrar lista l\n");
    showList(&l);
    return 0;
}
