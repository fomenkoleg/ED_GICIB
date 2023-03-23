//
// Created by Oleg Fomenkov on 21/2/23.
//

#ifndef PILADINAMICA_TELEMENTO_H
#define PILADINAMICA_TELEMENTO_H

typedef struct tEjercicio{
   int elem;
}TElemento;

void mostrarElemento(TElemento t);
void asignarElemento(TElemento *destino, TElemento origen);
int igualElemento(TElemento uno, TElemento dos);
void crearElemento(int elem, TElemento* elemento);
//tElemento crearElemento(char* enun, char* cat, int dif, int punt);

#endif //PILADINAMICA_TELEMENTO_H
