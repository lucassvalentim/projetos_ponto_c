typedef struct
{
    char figuras[9];
    int posicao;
    char jogador_vez;
}Jogo;


Jogo* criar_velha();
void escolher_vez(Jogo* velha);
void muda_vez(Jogo* velha);
void desenho_da_velha(Jogo* velha);
char verificar_ganhador(Jogo* velha);
int mostra_ganhador(Jogo* velha);
void quem_comeca(Jogo* velha);