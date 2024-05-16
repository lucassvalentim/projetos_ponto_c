#include <stdio.h>
#include <stdlib.h>

/*

    Considere um conjunto P de n pessoas e uma matriz M de tamanho
    n × n, tal que M[i, j] = M[j, i] = 1, se as pessoas i e j se conhecem e
    M[i, j] = M[j, i] = 0, caso contrário.

    Problema: existe um subconjunto C (Clique), de r pessoas escolhidas
    de P, tal que qualquer par de pessoas de C se conhecem?

*/

int combinacao_simples(int n, int r, int *x, int next, int k, int**M){
    if(k == r){
        for(int i = 0; i < r; i++){
            for(int j = i+1; j < r; j++){
                if(M[x[i]][x[j]] != 1 || M[x[j]][x[i]] != 1){
                    return 0;
                }
            }    
        }
        /*
            Caso a combinação gerada forma um clique eu retorno 1;
            Dessa forma, o for acima verifica se existe algum par de pessoas que não são amigas,
            caso isso seja verdade ele retorna zero;
        */

        return 1;
    }else{
        for(int i = next; i < n; i++){
            x[k] = i;
            if(combinacao_simples(n, r, x, i+1, k+1, M)){
                /*
                    Caso eu encontre um caso que seja clique, eu não preciso gerar outras combinações,
                    portanto utilizo um if;
                */
                return 1;
            }
        }

        return 0;
    }
}


int main(){

    int n;
    scanf("%d", &n);

    int r;
    scanf("%d", &r);

    int *x = (int*)malloc(r*sizeof(int));

    //cria a matriz
    int**matriz = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        matriz[i] = (int*)malloc(n*sizeof(int));
    }
    
    //ler a matriz da entrada
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    //imprime a matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //verifica se possui clique
    if(combinacao_simples(n, r, x, 0, 0, matriz)){
        printf("Possui clique formado pelas pessoas: \n");
        
        for (int i = 0; i < r; i++)
            printf("%d ", x[i] + 1);
        printf("\n");
    }
    else{
        printf("NAO TEM CLIQUE\n");
    }
    
    free(x);

    //Desaloca matriz
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }

    free(matriz);
    return 0;
}