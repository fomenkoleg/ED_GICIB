#include <stdio.h>
#include "TConjuntoDinamico.h"

#define DIM 20


int main(){
    TElemento e1,e2,e3,e4,e5,e6,e7,e8;
    TConjunto conjunto1, conjunto2,conjunto3, conjunto4;
    crearConjuntoVacio(&conjunto1);
    crearConjuntoVacio(&conjunto2);
    char d ='d';
    char e ='e';
    char f='f';
    char a='a';
    char v = 'v';
    char m = 'm';
    char g ='g';
    crearElemento(&d,&e1);
    crearElemento (&e,&e2);
    crearElemento (&f,&e3);
    crearElemento (&a,&e4);
    crearElemento(&v,&e5);
    crearElemento (&m,&e6);
    crearElemento (&g,&e7);
    poner(&conjunto1,&e1);
    poner(&conjunto1,&e3);
    poner(&conjunto2,&e2);
    poner(&conjunto2,&e4);
    poner(&conjunto1,&e7);
    poner(&conjunto2,&e5);
    poner(&conjunto2,&e3);
    printf("\nAhora uno\n");
    mostrarConjunto(conjunto1);
    printf("\nAhora el otro\n");
    mostrarConjunto(conjunto2);
    printf("son iguales? %d\n",igualConjunto(&conjunto2,&conjunto1));
    elegir(&conjunto1,&e8);
    mostrarElemento(e8);
    printf("\nEs subconjunto el conjunto 2 del conjunto 1? %d \n", esSubconjunto(&conjunto1,&conjunto2));
    crearConjuntoVacio(&conjunto3);
    unir(&conjunto1,&conjunto2,&conjunto3);
    mostrarConjunto(conjunto3);
    printf("Esta vacio el conjunto 2? %d \n",esConjuntoVacio(&conjunto2));
    printf("Numero de elementos del conjunto 2? %d \n",cardinal(&conjunto2));
    crearConjuntoVacio(&conjunto4);
    diferencia(&conjunto2,&conjunto1,&conjunto4);
    mostrarConjunto(conjunto4);
    printf("son iguales? %d\n",igualConjunto(&conjunto2,&conjunto1));


}
