#ifndef DEQUE_H
#define DEQUE_H

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

typedef Node node;

typedef struct {
    node *primeiro, *ultimo;
    unsigned quantidade;
    unsigned maximo;
} deque;

void inicializar (deque *d, unsigned maximo);

void destroi (deque *d);

int vazia (deque *d);

unsigned tamanho (deque *d);

void inserir_inicio (deque *d, int data);

void inserir_fim (deque *d, int data);

void retirar_inicio (deque *d);

void retirar_fim (deque *d);

#endif