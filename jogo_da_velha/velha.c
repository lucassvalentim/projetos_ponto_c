#include "velha.h"
#include <stdio.h>
#include <stdlib.h>

Jogo* criar_velha(){
    Jogo* velha = (Jogo*)malloc(sizeof(Jogo));

    char letra = '0';
    for(int i = 0; i < 9; i++){
        velha->figuras[i] = letra;
        letra++;
    }

    return velha;
}

void escolher_vez(Jogo* velha){

    // escolhe a posição na tela
        printf("\n-----------------------------------------\n");
        printf("\n(Vez do jogador %c) digite a posição:  ", velha->jogador_vez);
        scanf(" %d", &velha->posicao);
        printf("\n-----------------------------------------\n\n");

        //verifica se a posição escolhida já está ocupada
        while(velha->figuras[velha->posicao] == 'X' || velha->figuras[velha->posicao] == 'O'){
            printf("\n-------------------------------------------------------\n");    
            printf("Esta posição já está ocupada, favor escolher outra: ");
            scanf(" %d", &velha->posicao);
            printf("\n");
        }

        //verifica se a posição escolhida ultrapassa os valores extremos
        while(velha->posicao > 8 || velha->posicao < 0){
            printf("\n-------------------------------------------------------\n");    
            printf("Posição inválida, favor escolher outra: ");
            scanf(" %d", &velha->posicao);
            printf("\n");
        }
        
        //adiciona na posição escolhida o jogador da vez
        velha->figuras[velha->posicao] = velha->jogador_vez;

}

void muda_vez(Jogo* velha){

    if(velha->jogador_vez == 'X') velha->jogador_vez = 'O';
    else if(velha->jogador_vez == 'O') velha->jogador_vez = 'X';

}

void desenho_da_velha(Jogo* velha){
    //printa na tela o Jogo*
    printf("\t%c | %c | %c\t\n", velha->figuras[0], velha->figuras[1], velha->figuras[2]);
    printf("       ___|___|___\n");
    printf("\t%c | %c | %c\t\n", velha->figuras[3], velha->figuras[4], velha->figuras[5]);
    printf("       ___|___|___\n");
    printf("\t%c | %c | %c\t\n", velha->figuras[6], velha->figuras[7], velha->figuras[8]);
    printf("       ___|___|___\n");
}

void quem_comeca(Jogo* velha){
    printf("Quem começa (X ou O): ");
    scanf("%c", &velha->jogador_vez);
    
    while(velha->jogador_vez != 'X' && velha->jogador_vez != 'O'){
        printf("[VALOR INVÁLIDO]: digite X ou O (maiúsculo): ");
        scanf(" %c", &velha->jogador_vez);
    }
}


char verificar_ganhador(Jogo* velha){
    //ganhador
    if(velha->figuras[0] == velha->jogador_vez && velha->figuras[1] == velha->jogador_vez && velha->figuras[2] == velha->jogador_vez)return velha->jogador_vez;
    if(velha->figuras[3] == velha->jogador_vez && velha->figuras[4] == velha->jogador_vez && velha->figuras[5] == velha->jogador_vez)return velha->jogador_vez;
    if(velha->figuras[6] == velha->jogador_vez && velha->figuras[7] == velha->jogador_vez && velha->figuras[8] == velha->jogador_vez)return velha->jogador_vez;

    if(velha->figuras[0] == velha->jogador_vez && velha->figuras[3] == velha->jogador_vez && velha->figuras[6] == velha->jogador_vez)return velha->jogador_vez;
    if(velha->figuras[1] == velha->jogador_vez && velha->figuras[4] == velha->jogador_vez && velha->figuras[7] == velha->jogador_vez)return velha->jogador_vez;
    if(velha->figuras[2] == velha->jogador_vez && velha->figuras[5] == velha->jogador_vez && velha->figuras[8] == velha->jogador_vez)return velha->jogador_vez;

    if(velha->figuras[0] == velha->jogador_vez && velha->figuras[4] == velha->jogador_vez && velha->figuras[8] == velha->jogador_vez)return velha->jogador_vez;
    if(velha->figuras[2] == velha->jogador_vez && velha->figuras[4] == velha->jogador_vez && velha->figuras[6] == velha->jogador_vez)return velha->jogador_vez;

    //se ainda tem Jogo*
    char verificar[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(velha->figuras[i] == verificar[j]){
                return 'j';
            }
        }
    }
    //retorna empate caso não tenha passado em nenhum teste anterior
    return 'e';
}

int mostra_ganhador(Jogo* velha){

    //verifica qual jogador ganhou ou se deu velha
    if(verificar_ganhador(velha) == 'X'){
        printf("\n-----------------------------------------\n");
        printf("           JOGADOR X VENCEU");
        printf("\n-----------------------------------------\n");
        return 1;
    }
    if(verificar_ganhador(velha) == 'O'){
        printf("\n-----------------------------------------\n");
        printf("           JOGADOR O VENCEU");
        printf("\n-----------------------------------------\n");
        return 1;
    }
    if(verificar_ganhador(velha) == 'e'){
        printf("\n-----------------------------------------\n");
        printf("            DEU VELHA");
        printf("\n-----------------------------------------\n");
        return 1;
    }

    return 0;
}