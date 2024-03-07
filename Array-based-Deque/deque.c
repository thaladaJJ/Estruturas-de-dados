#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void inicializar (deque *d, unsigned maximo) {
    d->elementos = (int *)malloc(maximo * sizeof(int));
    d->inicio = d->fim = -1;
    d->quantidade = 0;
    d->maximo = maximo;
}

void destroi(deque *d) {
    free (d->elementos);
    free (d);
}

int vazia(deque *d) {
    return d->quantidade == 0;
}

unsigned tamanho(deque *d) {
    return d->quantidade;
}

void inserir_inicio(deque *d, int data) {
    if (d->quantidade == d->maximo) {
        printf ("cheia\n");
        return;
    }

    if (vazia(d)) {
        d->inicio = d->fim = 0;
    } else {
        d->inicio = (d->inicio - 1 + d->maximo) % d->maximo;
    }

    d->elementos [d->inicio] = data;
    d->quantidade++;
}

void inserir_fim (deque *d, int data) {
    if (d->quantidade == d->maximo) {
        printf ("cheia\n");
        return;
    }

    if (vazia(d)) {
        d->inicio = d->fim = 0;
    } else {
        d->fim = (d->fim + 1) % d->maximo;
    }

    d->elementos[d->fim] = data;
    d->quantidade++;
}

void retirar_inicio (deque *d) {
    if (vazia(d)) {
        printf ("vazia\n");
        return;
    }

    printf ("%d\n", d->elementos [d->inicio]);

    if (tamanho(d) == 1) {
        d->inicio = d->fim = -1;
    } else {
        d->inicio = (d->inicio + 1) % d->maximo;
    }

    d->quantidade--;
}

void retirar_fim (deque *d) {
    if (vazia(d)) {
        printf ("vazia\n");
        return;
    }

    printf ("%d\n", d->elementos [d->fim]);

    if (tamanho(d) == 1) {
        d->inicio = d->fim = -1;
    } else {
        d->fim = (d->fim - 1 + d->maximo) % d->maximo;
    }

    d->quantidade--;
}
