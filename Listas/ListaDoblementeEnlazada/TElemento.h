//
// Created by Oleg Fomenkov on 21/2/23.
//

#ifndef LISTADINAMICA_TELEMENTO_H
#define LISTADINAMICA_TELEMENTO_H

typedef struct tEjercicio{
    char enunciado[50];
    char categoria[20];
    int dificultad;
    int puntuacion;
}TElemento;

void mostrarElemento(TElemento t);
void asignarElemento(TElemento *destino, TElemento origen);
int igualElemento(TElemento uno, TElemento dos);
void crearElemento(char* enun, char* cat, int dif, int punt, TElemento *e);
//tElemento crearElemento(char* enun, char* cat, int dif, int punt);

#endif //LISTADINAMICA_TELEMENTO_H
