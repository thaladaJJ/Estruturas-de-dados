#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializar (fila *f) {
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->quantidade = 0;
}

void destroi (fila *f) {
    while (!vazia (f))
        retirar (f);
}

int vazia (fila *f) {
    return f->primeiro == NULL;
}

unsigned tamanho (fila *f) {
    return f->quantidade;
}

void inserir (fila *f, int data) {
    node *n = (node*) malloc (sizeof(node));
    n->data = data;
    n->next = NULL;

    if (f->ultimo)
        f->ultimo->next = n;
    else
        f->primeiro = n;
    
    f->ultimo = n;
    f->quantidade++;
}

void retirar (fila *f) {
    
    if (!vazia (f)) {
        node *n = f->primeiro;
        f->primeiro = n->next;
        free (n);
        
        if (f->primeiro == NULL)
            f->ultimo = NULL;

        f->quantidade--;
    }
}