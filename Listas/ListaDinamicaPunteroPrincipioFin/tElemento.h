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
}tElemento;

void mostrarElemento(tElemento t);
void asignarElemento(tElemento *destino, tElemento origen);
int igualElemento(tElemento uno, tElemento dos);
void crearElemento(char* enun, char* cat, int dif, int punt, tElemento *e);
//tElemento crearElemento(char* enun, char* cat, int dif, int punt);

#endif //LISTADINAMICA_TELEMENTO_H
