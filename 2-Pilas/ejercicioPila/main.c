#include <stdio.h>

#include "Lista/listaEnlazadaDinamica.h"
#include "PilaDinamica.h"

void invertirString();
int enArray(char* letras, char una);

int main() {
    invertirString();
    return 0;
}

void invertirString(){
    char string[100];
    fgets(string, 100, stdin);

    char vocales[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    TLista lista;
    crearListaVacia(&lista);
    TPila pila;
    crearPilaVacia(&pila);

    int pos = 0;

    while(string[pos] != '\0' && string[pos] != '\n'){
        TElemento caracter;
        crearElemento(string[pos], &caracter);
        if(enArray(vocales, string[pos])){
            insertarListaFinal(&lista, &caracter);
            pos++;

            crearElemento(string[pos], &caracter);
            while(!enArray(vocales, string[pos]) && string[pos] !='\0' && string[pos] !='\n'){
                crearElemento(string[pos], &caracter);
                push(&pila, &caracter);
                pos++;
            }
            while(!esPilaVacia(&pila)){
                cima(&pila, &caracter);
                pop(&pila);
                insertarListaFinal(&lista, &caracter);
            }
            //crearElemento(string[pos], &caracter);
            //insertarListaFinal(&lista, &caracter);
        } else {
            insertarListaFinal(&lista, &caracter);
            pos++;
        }

    }

    TLista invertir;
    crearListaVacia(&invertir);
    pos = 0;
    while(!esListaVacia(&lista)){
        TElemento elem;
        if(pos%2 == 0){
            obtenerPrimeroLista(&lista, &elem);
            restoLista(&lista);
        } else{
            obtenerUltimoLista(&lista, &elem);
            borrarUltimoLista(&lista);
        }
        pos++;

        insertarListaFinal(&invertir, &elem);

    }

    mostrarLista(&invertir);
}

int enArray(char* letras, char una){
    for (int i = 0; i < 10; ++i) {
        if(una == letras[i]){
            return 1;
        }
    }
    return 0;
}