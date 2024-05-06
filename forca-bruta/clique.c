#include <stdio.h>
#include <stdlib.h>

/*

    Considere um conjunto P de n pessoas e uma matriz M de tamanho
    n × n, tal que M[i, j] = M[j, i] = 1, se as pessoas i e j se conhecem e
    M[i, j] = M[j, i] = 0, caso contrário.

    Problema: existe um subconjunto C (Clique), de r pessoas escolhidas
    de P, tal que qualquer par de pessoas de C se conhecem?

*/

int combinacao_simples(int n, int r, int *x, int next, int k, int**matriz, int resultado){
    if(k == r){
        for(int i = 0; i < k - 1; i++){
            for(int j = i + 1; j < k; j++){
                if(matriz[x[i]][x[j]] != 1){
                    return 0;
                }
            }
        }
        resultado = 1;
    }else{
        for(int i = next; i < n; i++){
            x[k] = i;
            combinacao_simples(n, r, x, i+1, k+1, matriz, resultado);
        }
    }

    return resultado;
}


int main(){

    int n;
    scanf("%d", &n);

    int r;
    scanf("%d", &r);

    int *x = (int*)malloc(r*sizeof(int));

    int**matriz = (int**)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        matriz[i] = (int*)malloc(n*sizeof(int));
    }

     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int resultado = combinacao_simples(n, r, x, 0, 0, matriz, resultado);

    if(resultado){
        printf("EXISTE\n");
    }
    else{
        printf("NAO EXISTE\n");
    }

    free(x);

    return 0;
}