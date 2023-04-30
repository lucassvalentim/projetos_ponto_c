#include <stdio.h>
#include "lista.h"

int main(){

    int inteiros[4] = {2, 3 , 5, 1};
    Lista *l1 = constroi(4, inteiros);

    imprime(l1);
    printf("\n");
    return 0;
}