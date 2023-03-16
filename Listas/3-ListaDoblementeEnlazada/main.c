#include <stdio.h>
#include "ListaDoblementeEnlazada.h"

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

    //mostrar vacía
    mostrarLista(&l1);
    printf("\n");


    //insertarPrincipio
    //vacía

    insertarListaCabecera(&l1, &e1);
    mostrarLista(&l1);
    printf("\n");

    //con elementos
    insertarListaCabecera(&l1, &e2);
    mostrarLista(&l1);
    printf("\n");

    //insertarfinal
    //vacia

    insertarListaFinal(&l2, &e1);
    mostrarLista(&l2);
    printf("\n");

    //con elementos
    insertarListaFinal(&l2, &e2);
    mostrarLista(&l2);
    printf("\n");

    //insertamos más elementos
    insertarListaFinal(&l2, &e3);
    insertarListaFinal(&l2, &e4);
    insertarListaFinal(&l2, &e5);
    insertarListaFinal(&l2, &e6);
    insertarListaFinal(&l2, &e7);
    insertarListaFinal(&l2, &e8);
    mostrarLista(&l2);
    printf("\n");

    //borramos
    //primero
    eliminarElementoLista(&l2, &e1);
    mostrarLista(&l2);
    printf("\n");

    //último
    eliminarElementoLista(&l2, &e8);
    mostrarLista(&l2);
    printf("\n");

    //intermedio
    eliminarElementoLista(&l2, &e4);
    mostrarLista(&l2);
    printf("\n");


    //destruir
    //con elementos
    destruirLista(&l1);
    mostrarLista(&l1);
    printf("\n");

    //asignar listas
    //llena a vacia
    asignarLista(&l2, &l1);
    mostrarLista(&l1);
    printf("\n");

    //llena a llena
    insertarListaFinal(&l3, &e4);
    insertarListaFinal(&l3, &e5);
    insertarListaFinal(&l3, &e6);

    asignarLista(&l3, &l1);
    mostrarLista(&l1);
    printf("\n");

    //llena a vacía
    destruirLista(&l1);
    asignarLista(&l3, &l1);
    mostrarLista(&l1);
    printf("\n");

    //concatenar
    //vacia + llena
    destruirLista(&l1);
    concatenarLista(&l1, &l3);
    mostrarLista(&l1);
    printf("\n");

    //llena + llena
    concatenarLista(&l1, &l1);
    mostrarLista(&l1);
    printf("\n");

    //llena+vacia
    destruirLista(&l1);
    concatenarLista(&l2, &l1);
    mostrarLista(&l2);
    printf("\n");

    return 0;
}
