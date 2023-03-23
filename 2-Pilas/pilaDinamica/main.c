#include <stdio.h>
#include "PilaDinamica.h"

void invertirPalabras(char* string);

int main() {
    TPila  s1, s2, s3;

    TElemento e1, e2, e3, e4, e5;
    crearElemento(1, &e1);
    crearElemento(2, &e2);
    crearElemento(3, &e3);
    crearElemento(4, &e4);
    crearElemento(5, &e5);

    crearPilaVacia(&s1);
    crearPilaVacia(&s2);
    crearPilaVacia(&s3);

    push(&s1, &e1);
    push(&s1, &e2);
    push(&s1, &e3);
    //mostrarPila(&s1);

    pop(&s1);
    //mostrarPila(&s1);

    push(&s1, &e5);
    copiarPila(&s1, &s3);
    mostrarPila(&s3);

    cima(&s1, &e1);
    //mostrarElemento(e1);

    destruirPila(&s3);
    mostrarPila(&s3);
    printf("Pila 3: %d\n", longitudPila(&s3));
    printf("Pila 1: %d\n", longitudPila(&s1));

}



