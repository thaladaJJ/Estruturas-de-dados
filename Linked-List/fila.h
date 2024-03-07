#ifndef FILA_H
#define FILA_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node node;

typedef struct {
    node *primeiro, *ultimo;
    unsigned quantidade;
} fila;

void inicializar (fila *f);

void destroi (fila *f);

int vazia (fila *f);

unsigned tamanho (fila *f);

void inserir (fila *f, int data);

void retirar (fila *f);

#endif