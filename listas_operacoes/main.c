#include <stdio.h>
#include "lista.h"

int main(){

    Lista lista1;
    Lista lista2;
    cria_lista_vazia(&lista1);
    cria_lista_vazia(&lista2);

    int x;
    Item it1;
    for(int i = 0; i < 5; i++){
        scanf("%d", &x);
        it1.x = x;
        insere(lista1, it1);
    }


    int y;
    Item it2;
    for(int i = 0; i < 5; i++){
        scanf("%d", &y);
        it2.x = y;
        insere(lista2, it2);
    }
    
    printf("\nLista 1: ");
    imprime(lista1);
    printf("\n");

    printf("Lista 2: ");
    imprime(lista2);
    printf("\n\n");

    Apontador lista_intersecao = intersecao(lista1, lista2);
    printf("Lista 1 inter Lista 2: ");
    imprime(lista_intersecao);
    printf("\n");

    return 0;
}