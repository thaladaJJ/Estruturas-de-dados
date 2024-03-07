#ifndef PILHA_H
#define PILHA_H

typedef char T;

typedef struct {
    T *vetor;
    unsigned topo;
    int maximo;
} _pilha;

typedef _pilha* pilha;

pilha inicializar (int max);
void destruir (pilha p);
int inserir (pilha p, T elemento);
int vazio (pilha p);
T remover (pilha p);
T topo (pilha P);

#endif