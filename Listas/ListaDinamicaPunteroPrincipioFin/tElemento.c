//
// Created by Oleg Fomenkov on 21/2/23.
//
#include "tElemento.h"
#include <stdio.h>
#include <string.h>

void mostrarElemento(tElemento t)
{
    printf("Enunciado:/n%s\nCategoria: %s\nDificultad: %d\nPuntuacion: %d\n", t.enunciado, t.categoria, t.dificultad, t.puntuacion);

}
void asignarElemento(tElemento *destino, tElemento origen)
{
    strcpy(destino->enunciado, origen.enunciado);
    strcpy(destino->categoria, origen.categoria);
    destino->puntuacion=origen.puntuacion;
    destino->dificultad=origen.dificultad;
}
int igualElemento(tElemento uno, tElemento dos)
{
    return strcmp(uno.categoria, dos.categoria)==0&&strcmp(uno.enunciado, dos.enunciado)==0&&(uno.dificultad==dos.dificultad)&&(uno.puntuacion==dos.puntuacion);
}

void crearElemento(char* enun, char* cat, int dif, int punt, tElemento *e)
{
    strcpy(e->enunciado, enun);
    strcpy((*e).categoria, cat);
    e->dificultad = dif;
    (*e).puntuacion = punt;
}
