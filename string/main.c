#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(){

    printf("Digite uma string: ");
    string* s1 = lerString();

    printf("Você digitou: ");
    printf("%s\n", s1->str);

    return 0;
}