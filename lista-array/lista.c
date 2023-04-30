#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *constroi(int n, int *v){

    Lista* l = (Lista*)malloc(sizeof(Lista));
    Lista* aux = l;

    int index = 0;
    while(index < n){

        aux->info = v[index];
        index++;

        if(index == n){
            aux->prox = NULL;
            break;
        }

        aux->prox = (Lista*)malloc(sizeof(Lista));
        aux = aux->prox;
        
    }

    return l;
}

void imprime(Lista* l){

    Lista* aux = l;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }

}