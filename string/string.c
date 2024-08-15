#include "string.h"

string* criarString(){
    string* s = (string*)malloc(sizeof(string));
    
    if(s != NULL){
        s->capacidade = MAX;
        s->inicio = s->fim = 0;
        s->str = NULL;
    }else{
        printf("A struct string não pode ser alocada\n");
        exit(1);
    }

    return s;
}

void inicializarString(string* s){
    if(s == NULL){
        printf("string não pode ser inicializada\n");
        exit(1);
    }

    if(s->str == NULL){
        s->str = (char*)malloc((s->capacidade + 1) * sizeof(char));
        s->str[s->fim] = '\0';
    }
}

void realocarString(string* s){
    if(s == NULL){
        printf("não foi possível realocar na string\n");
        exit(1);
    }

    if(s->str == NULL){
        printf("str não precisa de realoque\n");
        exit(1);
    }

    long long novaCapacidade = (s->capacidade * MAX) * sizeof(char);
    s->str = realloc(s->str, novaCapacidade + 1);
    s->capacidade = s->capacidade * MAX;
}

void inserirChar(string* s, char c){
    if(s == NULL){
        printf("não foi possível inserir na string\n");
        exit(1);
    }

    if(s->str == NULL){
        inicializarString(s);
    }else if(s->fim + 1 > s->capacidade){
        realocarString(s);
    }

    s->str[s->fim++] = c;
}

string* lerString(){
    string *s = criarString();

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF){
        inserirChar(s, ch);
    }
    s->str[s->fim] = '\0';

    return s;
}