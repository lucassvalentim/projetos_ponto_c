#include <stdio.h>
#include "polinomio.h"

int main(){

    Lista lista1;//polinomio1
    Lista lista2;//polinomio2
    cria_lista_vazia(&lista1);
    cria_lista_vazia(&lista2);

    //vetor de polinomios, contem os dois polinomios que serão somados
    polinomio x[7];

    //polinomio1
    x[0].coeficiente = 3;
    x[0].expoente = 9;

    x[1].coeficiente = 2;
    x[1].expoente = 5;

    x[2].coeficiente = 2;
    x[2].expoente = 3;

    //polinomio2
    x[3].coeficiente = 4;
    x[3].expoente = 9;

    x[4].coeficiente = 1;
    x[4].expoente = 5;

    x[5].coeficiente = -1;
    x[5].expoente = 4;

    //insere o polinomio1 na lista1
    for(int i = 0; i < 3; i ++){
        insere(lista1, x[i]);

    }

    //insere o polinomio2 na lista2
    for(int i = 3; i < 6; i ++){
        insere(lista2, x[i]);

    }

    //imprime o polinomio1
    imprime(lista1);
    printf("\n");

    //imprime o polinomio2
    imprime(lista2);
    printf("\n");

    //soma dos dois polinomios que resulta em um terceiro
    Lista lista3 = soma_polinomios(lista1, lista2);
    imprime(lista3);
    printf("\n");

    return 0;
}