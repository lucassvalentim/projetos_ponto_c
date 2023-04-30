typedef struct{
    int coeficiente;
    int expoente;
}polinomio;

typedef struct Celula * Apontador;

typedef struct Celula{
    polinomio p;
    Apontador prox;
}Celula;

typedef Apontador Lista;

void cria_lista_vazia(Lista *l);
int vazia(Lista l);
void insere(Lista l, polinomio pol);
void imprime(Lista l);
Apontador soma_polinomios(Lista l1, Lista l2);