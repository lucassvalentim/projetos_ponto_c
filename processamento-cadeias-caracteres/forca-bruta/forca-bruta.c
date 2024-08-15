#include "forca-bruta.h"
#include <stdlib.h>
#include <stdio.h>

int forca_bruta(char t[], char p[], int n, int m){
    for(int i = 0; i < n - m + 1; i++){
        int k = i, j = 0;
        while(t[k] == p[j] && j < m){
            k++; j++;
        }
        if(j >= m)
            printf("CASOU na posicao: %d\n", i);
    }

    return 1;
}

