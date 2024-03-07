#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar (lista *p) {
    node *n = malloc (sizeof (node));
    n->next = n->prev = p->sentinela = n;
    p->quantidade = 0;
}

void destruir (lista *p) {
    while (!vazia (p))
        removerInicio (p);

    free (p->sentinela);
}

unsigned tamanho (lista *p);

int vazia (lista *p) {
    return p->sentinela->next == p->sentinela;
}

void inserirInicio (lista *p, T data) {
    node *n = malloc (sizeof(node));
    n->data = data;
    n->next = p->sentinela->next;
    n->prev = p->sentinela;
    p->sentinela->next = n;
    n->next->prev = n;
    p->quantidade++;
}

void inserirFinal (lista *p, T data) {
    node *n = malloc (sizeof (node));
    n->data = data;
    n->next = p->sentinela;
    n->prev = p->sentinela->prev;
    p->sentinela->prev = n;
    n->prev->next = n;
    p->quantidade++;
}

void removerInicio (lista *p) {
    node *n = p->sentinela->next;

    if (n != p->sentinela) {
        
        printf ("%d ", n->data);

        n->prev->next = n->next;
        n->next->prev = n->prev;
        free (n);
        p->quantidade--;
    }

}

void removerFim (lista *p) {
    node *n = p->sentinela->prev;
    
    if ( n != p->sentinela ) {

        printf ("%d ", n->data);
        
        n->next->prev = n->prev;
        n->prev->next = n->next;
        free (n);
        p->quantidade--;
    }
}

int menorNo (lista *p) {

    if (vazia(p)) return 0;

    node* aux = p->sentinela->next;
    node* noMinimo = aux;
    int menor = aux->data;

    do {
        if (aux->data < menor) {
            menor = aux->data;
            noMinimo = aux;
        }
        aux = aux->next;
    } while (aux != p->sentinela);

    return noMinimo->data;
}