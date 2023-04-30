#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

void cria_lista_vazia(Lista *l){
    *l = (Apontador)malloc(sizeof(Celula));
}
int vazia(Lista l){
    return (l->prox == NULL);
}

void insere(Lista l, polinomio pol){
    
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
        printf("%dx^%d ", aux->p.coeficiente, aux->p.expoente);
        aux = aux->prox;
    }
}

Apontador soma_polinomios(Lista l1, Lista l2){
    //lista que será usada como resultado da soma de polinomios
    Lista l3;
    polinomio aux;
    cria_lista_vazia(&l3);

    //Soma dos polinomios
    while(l1->prox != NULL){

        while(l2->prox != NULL){

            if(l1->prox->p.expoente == l2->prox->p.expoente){
                aux.coeficiente = l1->prox->p.coeficiente + l2->prox->p.coeficiente;
                aux.expoente = l1->prox->p.expoente;

                insere(l3, aux);
                l2 = l2->prox;// ando com o ponteiro na lista2, ja que não é possivel executar a linha 69
                break;// Saio do loop para andar com o ponteiro na lista1 (linha 72)
            }

            if(l1->prox->p.expoente < l2->prox->p.expoente){
                insere(l3, l2->prox->p);
                /*
                    ao inserir, é necessário andar com o ponteiro somente na lista 2
                    então o loop deve continuar se for preciso, por isso não há o break nesse escopo.
                */
            }

            if(l1->prox->p.expoente > l2->prox->p.expoente){
                insere(l3, l1->prox->p);
                /*
                    ao inserir, é necessário andar com o ponteiro somente na lista1
                    por isso há o break nesse escopo, para que a linha 70 não seja executada
                */
                break;
            }

            l2 = l2->prox;
        }

        l1 = l1->prox;
    }

    //Caso sobre elementos em alguma lista, os comandos abaixo insere no final da lista3
    while(l1->prox != NULL){
        insere(l3, l1->prox->p);
        l1 = l1->prox;
    } 
    while(l2->prox != NULL){
        insere(l3, l2->prox->p);
        l2 = l2->prox;
    } 

    return l3;
}