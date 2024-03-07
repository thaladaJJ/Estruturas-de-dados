#ifndef LISTA_H
#define LISTA_H

typedef int T;

struct Node {
    T data;
    struct Node *next, *prev;
};

typedef struct Node node;

typedef struct {
    node *sentinela;
    unsigned quantidade;
} lista;

void inicializar (lista *p);

void destruir (lista *p);

unsigned tamanho (lista *p);

int vazia (lista *p);

void inserirInicio (lista *p, T data);

void inserirFinal (lista *p, T data);

void removerFim (lista *p);

void removerInicio (lista *p);

int menorNo (lista *p);

#endif