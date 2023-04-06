#include <stdio.h>
#include <stdlib.h>
#include "velha.h"

int main(){

    Jogo* velha = criar_velha();

    // desenho na tela
    printf("\n\n------ JOGO DA VELHA --------------------\n\n");
    desenho_da_velha(velha);
    printf("\n-----------------------------------------\n\n");
    
    // Se quem vai começar é o X ou O
    quem_comeca(velha);

    while (1)
    {   
        //escolhe a posição que o jogador da vez quer realizar
        escolher_vez(velha);

        //desenha a velha na tela
        desenho_da_velha(velha); 

        //mostra se alguem ganhou ou se empatou
        int winner = mostra_ganhador(velha);
        if(winner) break; // caso termine em empate ou vitoria ou derrota o jogo termina

        // muda de X para O ou vice versa
        muda_vez(velha);
    }

    return 0;
}