#include <stdlib.h>
#include <stdio.h>
#include "forca-bruta/forca-bruta.h"
#include <string.h>

#define MAX 100

int main(){
    char t[MAX];
    char p[MAX];

    scanf("%s", t);
    scanf("%s", p);

    forca_bruta(t, p, strlen(t), strlen(p));
    return 0;
}