#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void cria_lista_vazia(Lista *l){

    *l = (Apontador)malloc(sizeof(Celula));
    
}

int vazia(Lista l){

    return (l->prox == NULL);

}

void insere(Lista l, Item pol){
    
    while(l->prox != NULL){
        l = l->prox;
    }

    l->prox = (Apontador)malloc(sizeof(Celula));
    l->prox->p = pol;
    l->prox->prox = NULL;

}

void imprime(Lista l){

    Apontador aux = l->prox;
    while(aux != NULL){
        printf("%d ", aux->p.x);
        aux = aux->prox;
    }

}

Apontador intersecao(Lista l1, Lista l2){

    Apontador l3;
    cria_lista_vazia(&l3);

    Apontador aux;
    while(l1->prox != NULL){
        aux = l2;
        while (aux->prox != NULL){
            if(l1->prox->p.x == aux->prox->p.x){
                insere(l3, aux->prox->p);
            }
            aux = aux->prox;
        }
        l1 = l1->prox;
    }
    return l3;

}

void uniao(Lista l1, Lista l2){

    while(l2->prox != NULL){
        insere(l1, l2->prox->p);
        l2 = l2->prox;
    }

}

