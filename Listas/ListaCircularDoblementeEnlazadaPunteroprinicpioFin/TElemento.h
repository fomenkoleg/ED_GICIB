//
// Created by Oleg Fomenkov on 19/3/23.
//

#ifndef LISTACIRCULARDOBLEMENTEENLAZADAPUNTEROPRINICPIOFIN_TELEMENTO_H
#define LISTACIRCULARDOBLEMENTEENLAZADAPUNTEROPRINICPIOFIN_TELEMENTO_H
typedef struct tEjercicio{
    int elem;
}TElemento;

void mostrarElemento(TElemento t);
void asignarElemento(TElemento *destino, TElemento origen);
int igualElemento(TElemento uno, TElemento dos);
void crearElemento(int elem, TElemento* elemento);

#endif //LISTACIRCULARDOBLEMENTEENLAZADAPUNTEROPRINICPIOFIN_TELEMENTO_H
