#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha inicializar (int max) {

    pilha p = malloc (sizeof (_pilha));

    if (!p) return 0;

    p->topo = 0;
    p->maximo = max;
    p->vetor = malloc (max * sizeof (T));
    return p;
}

void destruir (pilha p) {

    if (!p)
        return;
    
    free (p->vetor);
    free (p);
}

int vazio (pilha p) {
    return p->topo == 0;
}

int inserir (pilha p, T elemento) {

    if (p->topo < p->maximo) {
        p->vetor [p->topo] = elemento;
        p->topo++;
        return 1;
    }

    return 0;
}

T remover (pilha p) {
    if (vazio(p))
        return 0;

    p->topo--;
    return p->vetor [p->topo];
}

T topo (pilha p) {
    if (vazio(p))
        return 0;
    
    return p->vetor [p->topo - 1];
}