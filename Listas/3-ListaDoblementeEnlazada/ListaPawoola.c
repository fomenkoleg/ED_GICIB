
#include "ListaDoblementeEnlazada.h"
/*
void insertarListaCabecera(TLista* l, TElemento *elem){
    TNodo *aux=(TNodo *) malloc (sizeof(TNodo)); //creamos nuevo elemento
    asignarElemento(&aux->info,*elem); //le asignamos el valor
    aux->sig = *l; //apunta al primer elemento
    aux->ant = NULL; // su anterior es null
    if(!esListaVacia(l)){
        (*l)->ant=aux; //si la lista tenía algún elemento, su anterior ahora apunta al nuevo elemento
    }
    (*l)=aux; //lista ahora apunta al nuevo
}

void insertarListaFinal(TLista*l, TElemento * elem){
    if(esListaVacia(l)){
        insertarListaCabecera(l, elem); //si es vacía, hacer al principio
    }
    else{
        //TLista act = *l;
        TNodo* act = *l; //simplemente porque tiene más sentido iterar por Nodos que por listas

        while(act->sig != NULL){ //llegamos al último elemento
            act = act->sig;
        }

        TNodo * aux = (TNodo*)malloc(1*sizeof(TNodo)); //creamos el nodo vacío
        asignarElemento(&aux->info, *elem); //le asignamos elemento
        act->sig = aux; //el último ahora apunta al nuevo
        aux->ant = act;
        aux->sig = NULL;
    }
}



int eliminarElementoLista(TLista* l, TElemento *elem){
    TNodo* act = *l; //creamos el elemento para iterar
    int encontrado = 0;
    while( !encontrado && act != NULL){ //mientras no se encuentra y no se ha llegado al último elemento
        encontrado = igualElemento(act->info, *elem); //a ver si son iguales
        if(encontrado){
            if(act == *l){ // por si es el primero de la lista
                *l = (*l)->sig; //si es el primero, que *l apunte al siguiente
                if(!esListaVacia(l)){ // por si hay más elementos
                    (*l)->ant = NULL; //y si tiene más elementos, pues que el siguiente apunte con su ant a NULL
                }
            }
            else { //si no es el primero
                (act->ant)->sig = act->sig; //que el siguiente de
                if((act->sig != NULL)){ // No es el último de la lista
                    (act->sig)->ant=act->ant;
                }
            }
            free(act);
        }
        else {
            act = act->sig;
        }
    }
    return encontrado;
}

//perfect

void obtenerPrimeroLista(TLista *l,TElemento *elem){
    if(!esListaVacia(l)){
        asignarElemento(&(*l)->info,*elem);
    }
}

void restoLista(TLista* l){
    if(!esListaVacia(l)){
        if((*l)->sig==NULL){ //si solo hay un elemento
            //destruirLista(l); no puedes porque entras en un bucle; desde destruirLista llamas a restoLista
            free(*l);
            crearListaVacia(l);
        } else {
            *l=(*l)->sig;
            (*l)->ant=NULL;
        }

        //otra forma:

         * *l=(*l)->sig; //hacer que apunte al siguiente del primero (puede ser elemento o NULL)
         * if(!esListaVacia(l)){
         *    (*l)->ant=NULL; //si no queda vacía, que el primer elemento ahora apunte con ant a NULL
         * }
         *
         * //igualmente esto lo puedes utilizar en el borrarElementoLista si el elemento por borrar es el primero

    }
}

int obtenerNumeroElementos(TLista l){
    if(esListaVacia(&l)){
        return 0;
    }else{
        if(l->sig==NULL){
            return 1;
        }else{
            TNodo * aux=l; //creamos un puntero para iterar
            int cont=0;
            while(aux!=NULL){
                ++cont;
                aux=aux->sig;
            }
            return cont;
        }
    }
}
//perfect

void obtenerUltimoLista(TLista* l, TElemento* elem){
    if(!esListaVacia(l)){
        if((*l)->ant==NULL){
            asignarElemento(&(*l)->info,*elem);
        }else{
            TNodo * aux =*l;
            while (aux->sig!=NULL){
                aux=aux->sig;
            }
            asignarElemento(elem, aux->info);
        }
    }
}

void destruirLista(TLista *l){
    //if(!esListaVacia(l)){
    while(!esListaVacia(l)){
        restoLista(l);
    }
}

void asignarLista(TLista* orig, TLista* dest){
    if(!esListaVacia(orig)){ //si la primera no es vacía
        if(esListaVacia(dest)){ //si la segunda esta vacía
            //este if yo lo cambiaría a un destruirLista(dest) y crearListaVacia(dest), porque si le pasas una lista que no esté vacía, debería funcionar igual y asignarla

            TNodo *aux=*orig; //creamos un puntero para iterar por la primera lista

            while (aux!=NULL){ //iteramos por la lista
                insertarListaFinal(dest,&aux->info); //esta operación es O(n), aunque sea correcto, son muchas operaciones
                aux=aux->sig;

            }

            /*
             TNodo *aux2=*dest; //creamos puntero para ir iterando y añadiendo elementos en dest
             while (aux!=NULL){ //mientras no hayamos llegado al último elemento de la primera lista

                while(aux2->sig != NULL){ //mientras no hayamos llegado al último elemento de la segunda
                aux2 = aux2->sig;
                }
                //este while es innecesario porque en aux2 siempre tendremos el último elemento de la segunda lista
                //porque podemos, al final de este while, poner un
                //aux2 = aux3
                //lo que nos "moverá" a la última posición

                TNodo * aux3 = (TNodo*)malloc(1*sizeof(TNodo)); //creamos un hueco en memoria
                asignarElemento(&aux->info, &aux->info);
                //act->sig = aux3, creo q era un typo
                //aux2->sig = aux3; es mi version, pero tmb está mal



                aux3->ant = aux2;
                aux3->sig = NULL; //perfect

                //y ahora
                aux2 = aux3
                //para tener en aux siempre el último elemento
             }
             */





            /*
             PROPUESTA

             lo pongo aqui para que no se entremezcle con tu código

             1) asignamos el primer elemento
             2) iteramos por los demás

             asimismo, evitamos que nos de error cuando, cuando la lista dest está vacía, hagamos dest->sig. (NULL no tiene sig)

             el código será:


             insertarListaCabecera(dest, &aux->info); //insertamos el primer elemento
             TNodo *aux2=*dest; //creamos puntero para ir iterando y añadiendo elementos en dest
             aux = aux->sig; //incrementamos y vamos al segundo (si hay) de la primera lista

             while (aux!=NULL){ //mientras no hayamos llegado al último elemento de la primera lista

                TNodo * aux3 = (TNodo*)malloc(1*sizeof(TNodo)); //creamos un hueco en memoria
                asignarElemento(&aux->info, &aux->info);
                aux2->sig = aux3; es mi version, pero tmb está mal
                aux3->ant = aux2;
                aux3->sig = NULL; //perfect

                aux2 = aux3
                //para tener en aux siempre el último elemento
             }



        }
    }
}

int contieneLista(TLista* l, TElemento elem){
    if(!esListaVacia(l)){
        TNodo *aux=*l;
        while (aux!=NULL){
            if(igualElemento(aux->info,elem)){
                return 1;
            }
            aux=aux->sig;
        }
        return 0;
    }

    //perfecto
}

int esIgualLista(TLista* uno, TLista* dos) {
    if(esListaVacia(uno)&& esListaVacia(dos)){
        return 1; //perfecto
    }else if((!esListaVacia(uno)&& esListaVacia(dos))|| (esListaVacia(uno)&& !esListaVacia(dos))){
        return 0; //perfecto
    }else{
        TNodo *auxdos=*dos; //si no estan vacias, creamos dos punteros para iterar
        TNodo *auxuno=*uno;

        while(auxdos!=NULL && auxuno!=NULL){ //mientras no hayamos llegado al último en alguno de los dos

            //if(igualElemento(auxuno->info,auxdos->info)){
            if(!igualElemento(auxuno->info,auxdos->info)){
                //si NO son iguales, devolvemos zer0
                return 0;
            }
            auxdos=auxdos->sig;
            auxuno=auxuno->sig; // si son iguales, seguimos
        }
        return 1;
        // si hemos llegado al final, son iguales y devolvemos 1

        //perfecto, con un errorcito
    }
}

void concatenarLista(TLista* uno, TLista* dos){
    //aquí pondría q si no está vacía la 2
    //luego, si lo está, entonces no hacemos nada


    //si está vacía la 1, hacemos asignar lista de 2 a 1
    if(!esListaVacia(uno)){
        TNodo *aux=*uno;
        while (aux->sig!=NULL){
            aux=aux->sig;
        }
        TNodo *auxd=*dos;
        while (auxd!=NULL){
            insertarListaFinal(&aux,&auxd->info);
            //me gusta la idea de utilizar &aux para asignar al final a un nodo, me parece muy original
            //no digo que está mal, debería funcionar, pero por si acaso para examen y tal te pongo otra forma

            //pero que sepas que lo que hiciste a mi por lo menos no me parece mal, es una cosa
            //muy original que no lo había pensado pero que tiene mucho sentido.
            auxd=auxd->sig;
        }
    }


    /*
     PROPUESTA
     if(esListaVacia(uno){
        asignarLista(dos, uno)
     } else if(!esListaVacia(dos)){
        TNodo *aux=*uno; //creamos puntero para iterar, perfecto
        while (aux->sig!=NULL){
            aux=aux->sig; //llegamos al último elemento
        }

        TNodo *auxd=*dos; //creamos un puntero para la segunda lista
        while (auxd!=NULL){
            TNodo* nuevoElemento = (TNodo*) malloc(sizeof(TNodo));
            asignarElemento(&nuevoElemento->info, auxd->info); //asignamos de aux a nuevoElemento
            nuevoElemento->sig = NULL; //siguiente es NULL
            nuevoElemento->ant = aux; //anterior es el último de la primera
            aux->sig = nuevoElemento; //último de la primera apunte a nuevoElemento como siguiente
            aux = nuevoElemento; //puntero aux ahora apunta a nuevoElemento porque es el nuevo último de la primera lista

            auxd = auxd->sig; // iteramos por la segunda lista
        }
    }


}

void concatenarLista2(TLista* uno, TLista* dos){ //no he visto este antes de corregir el anterior, a ver sjsj
    if(!esListaVacia(uno)){
        //TLista *tres;
        TLista *tres = (*TLista) malloc(sizeof(TLista)); //para reservar un hueco de memoria
        crearListaVacia(tres); //creamos una nueva lista en la memoria
        TNodo *aux=*uno; //para iterar por la primera
        TNodo *l=*tres; //parar is asignando a la nueva

        while (aux->sig!=NULL){ //iteramos por la primera y vamos asignando sus elementos
            asignarElemento(&l->info,aux->info); //copiamos el elemento

            l=l->sig;
            l=l->ant->sig; //estas dos ultimas no las pillo
            aux=aux->sig;

        }
        TNodo *auxd=*dos;
        while (auxd!=NULL){
            asignarElemento(&l->info,auxd->info);
            l=l->sig;
            l=l->ant->sig;
            auxd=auxd->sig;
        }
        l->sig=NULL;
    } //este no lo entiendo muy bien, luego me lo explicas ejjej
}
*/