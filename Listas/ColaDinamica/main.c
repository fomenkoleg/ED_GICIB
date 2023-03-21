#include <stdio.h>
#include "ColaDinamica.h"

int main() {

        TCola l1, l2, l3, l4;
        crearColaVacia(&l1);
        crearColaVacia(&l2);
        crearColaVacia(&l3);
        crearColaVacia(&l4);

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
        mostrarCola(&l1);
        printf("\n");
        
        //Encolar
        //vacia
        encolar(&l2, &e1);
        mostrarCola(&l2);
        printf("\n");

        //con elementos
        encolar(&l2, &e2);
        mostrarCola(&l2);
        printf("\n");

        //insertamos más elementos
        encolar(&l2, &e3);
        encolar(&l2, &e4);
        encolar(&l2, &e5);
        encolar(&l2, &e6);
        encolar(&l2, &e7);
        encolar(&l2, &e8);
        mostrarCola(&l2);
        printf("\n");


        //borramos
        //primero
        eliminarElementoCola(&l2, &e1);
        mostrarCola(&l2);
        printf("\n");


        //último
        eliminarElementoCola(&l2, &e8);
        mostrarCola(&l2);
        printf("\n");

        //intermedio
        eliminarElementoCola(&l2, &e4);
        mostrarCola(&l2);
        printf("\n");


        //destruir
        //con elementos
        destruirCola(&l1);
        mostrarCola(&l1);
        printf("\n");

        //asignar Colas
        //llena a vacia
        asignarCola(&l2, &l1);
        mostrarCola(&l1);
        printf("\n");


        //llena a llena
        encolar(&l3, &e4);
        encolar(&l3, &e5);
        encolar(&l3, &e6);

        asignarCola(&l3, &l1);
        mostrarCola(&l1);
        printf("\n");

        //llena a vacía
        destruirCola(&l1);
        asignarCola(&l3, &l1);
        mostrarCola(&l1);
        printf("\n");

        //concatenar
        //vacia + llena
        destruirCola(&l1);
        concatenarCola(&l1, &l3);
        mostrarCola(&l1);
        printf("\n");

        //llena + llena
        concatenarCola(&l1, &l1);
        mostrarCola(&l1);
        printf("\n");

        //llena+vacia
        destruirCola(&l1);
        concatenarCola(&l2, &l1);
        mostrarCola(&l2);
        printf("\n");
        
    return 0;
}
