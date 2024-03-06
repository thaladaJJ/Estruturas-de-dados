#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void inicializar (deque *d, unsigned maximo) {
    d->primeiro = NULL;
    d->ultimo = NULL;
    d->quantidade = 0;
    d->maximo = maximo;
}

void destroi (deque *d) {

    while (d->primeiro != NULL) {
        node *temp = d->primeiro;
        d->primeiro = d->primeiro->next;
        free (temp);
    }

    d->primeiro = NULL;
    d->ultimo = NULL;
    d->quantidade = 0;
}

int vazia(deque *d) {
    return d->primeiro == NULL;
}

unsigned tamanho (deque *d) {
    return d->quantidade;
}

void inserir_inicio (deque *d, int data) {

    if (tamanho (d) >= d->maximo) {
        printf ("cheia\n");
        return;
    }

    node *n = malloc (sizeof(node));
    n->data = data;
    n->prev = NULL;

    if (d->primeiro == NULL) {
        d->primeiro = n;
        d->ultimo = n;
    }

    else {
        n->next = d->primeiro;
        d->primeiro->prev = n;
        d->primeiro = n;
    }

    d->quantidade++;
}

void inserir_fim (deque *d, int data) {

    if (tamanho (d) >= d->maximo) {
       printf ("cheia\n");
        return;
    }

    node *n = (node*) malloc (sizeof(node));
    n->data = data;
    n->next = NULL;

    if (d->ultimo == NULL) {
        d->primeiro = n;
        d->ultimo = n;
    } 
    
    else {
        n->prev = d->ultimo;
        d->ultimo->next = n;
        d->ultimo = n;
    }

    d->quantidade++;
}

void retirar_inicio (deque *d) {

    if (vazia (d)) { 
        printf("vazia\n");
        return;
    }

    printf ("%d\n", d->primeiro->data);

    node *temp = d->primeiro;
    d->primeiro = temp->next;

    if (d->primeiro == NULL) {
        d->ultimo = NULL;
    } 
    
    else
        d->primeiro->prev = NULL;

    d->quantidade--;
}

void retirar_fim (deque *d) {

    if (vazia(d)) {
        printf("vazia\n");
        return;
    }

    printf ("%d\n", d->ultimo->data);

    node *temp = d->ultimo;
    d->ultimo = temp->prev;

    if (d->ultimo == NULL) {
        d->primeiro = NULL;
    } 
    
    else
        d->ultimo->next = NULL;

    d->quantidade--;
}