#include <stdio.h>
#include <string.h>
#include "TElemento.h"

void mostrarElemento (TElemento t){
    printf("%c",t);
    }

void asignarElemento(TElemento* copia, TElemento original){
    *copia=original;
}

int igualElemento(TElemento uno, TElemento dos){
    return  ((uno)==(dos));
}

void crearElemento(char* c, TElemento* e){
   *e=*c;
}

