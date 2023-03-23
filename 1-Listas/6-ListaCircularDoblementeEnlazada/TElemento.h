//
// Created by Oleg Fomenkov on 19/3/23.
//

#ifndef LISTACIRCULARDOBLEMENTEENLAZADA_TELEMENTO_H
#define LISTACIRCULARDOBLEMENTEENLAZADA_TELEMENTO_H
typedef struct tEjercicio{
    int elem;
}TElemento;

void mostrarElemento(TElemento t);
void asignarElemento(TElemento *destino, TElemento origen);
int igualElemento(TElemento uno, TElemento dos);
void crearElemento(int elem, TElemento* elemento);
//tElemento crearElemento(char* enun, char* cat, int dif, int punt);

#endif //LISTACIRCULARDOBLEMENTEENLAZADA_TELEMENTO_H
