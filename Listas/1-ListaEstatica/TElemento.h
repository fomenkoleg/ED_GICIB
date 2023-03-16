//
// Created by Oleg Fomenkov on 19/2/22.
//

#include <stdio.h>
#ifndef LISTAESTATICA_TELEMENTO_H
#define LISTAESTATICA_TELEMENTO_H

typedef int TElemento;

void createElement(TElemento* elem, int num);
void showElement(TElemento* elem);
void assignElement(TElemento* orig,TElemento* dest);
int isEqualElement(TElemento* elem1, TElemento* elem2);

#endif //LISTAESTATICA_TELEMENTO_H
