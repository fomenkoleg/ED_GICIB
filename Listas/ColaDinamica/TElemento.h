//
// Created by Oleg Fomenkov on 21/3/23.
//

#ifndef COLADINAMICA_TELEMENTO_H
#define COLADINAMICA_TELEMENTO_H


typedef struct tEjercicio{
    int elem;
}TElemento;

void mostrarElemento(TElemento t);
void asignarElemento(TElemento *destino, TElemento origen);
int igualElemento(TElemento uno, TElemento dos);
void crearElemento(int elem, TElemento* elemento);

#endif //COLADINAMICA_TELEMENTO_H
