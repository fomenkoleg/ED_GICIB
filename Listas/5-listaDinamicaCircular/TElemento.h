//
// Created by Oleg Fomenkov on 16/3/23.
//

#ifndef LISTADINAMICACIRCULAR_TELEMENTO_H
#define LISTADINAMICACIRCULAR_TELEMENTO_H

typedef struct tEjercicio{
    int elem;
}TElemento;

void mostrarElemento(TElemento t);
void asignarElemento(TElemento *destino, TElemento origen);
int igualElemento(TElemento uno, TElemento dos);
void crearElemento(int elem, TElemento* elemento);
//tElemento crearElemento(char* enun, char* cat, int dif, int punt);

#endif //LISTADINAMICACIRCULAR_TELEMENTO_H
