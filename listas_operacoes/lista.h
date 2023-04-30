typedef struct{
    int x;
}Item;

typedef struct Celula * Apontador;

typedef struct Celula{
    Item p;
    Apontador prox;
}Celula;

typedef Apontador Lista;

void cria_lista_vazia(Lista *l);
int vazia(Lista l);
void insere(Lista l, Item pol);
void imprime(Lista l);
Apontador intersecao(Lista l1, Lista l2);