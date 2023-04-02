#include <stdio.h>
#include "ListaEnlazadaPunteroPrincipioFin.h"

int main() {

    TLista l1, l2, l3, l4;
    crearListaVacia(&l1);
    crearListaVacia(&l2);
    crearListaVacia(&l3);
    crearListaVacia(&l4);

    TElemento e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
    crearElemento(1, &e1);
    crearElemento(2, &e2);
    crearElemento(3, &e3);
    crearElemento(4, &e4);
    crearElemento(5, &e5);
    crearElemento(6, &e6);
    crearElemento(7, &e7);
    crearElemento(8, &e8);
    crearElemento(9, &e9);
    crearElemento(10, &e10);

    //insertamos más elementos
    insertarListaFinal(&l2, &e3);
    insertarListaFinal(&l2, &e4);
    insertarListaFinal(&l2, &e3);
    insertarListaFinal(&l2, &e4);
    insertarListaFinal(&l2, &e3);
    insertarListaFinal(&l2, &e3);
    mostrarLista(&l2);
    printf("\n");

    borrarSecuencia(&l2, &e3, &e4);
    mostrarLista(&l2);

    return 0;
}


