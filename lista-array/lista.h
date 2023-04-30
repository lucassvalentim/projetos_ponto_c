struct lista {
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *constroi(int n, int *v);
void imprime(Lista* l);