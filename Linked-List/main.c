#include <stdio.h>                      
#include <stdlib.h>               
#include "fila.h"

void inverterFilaRecursivamente (fila *f) {
    if (!vazia (f)) {
        int elemento = f->primeiro->data;
        retirar (f);
        inverterFilaRecursivamente (f);
        inserir (f, elemento);
    }
}

int main () {

    fila *minhaFila = malloc(sizeof(fila));
    inicializar (minhaFila);

    int num_elementos;
    scanf ("%d", &num_elementos);

    int elemento;

    for (int i = 0; i < num_elementos; i++) {
        scanf ("%d", &elemento);
        inserir (minhaFila, elemento);
    }

    inverterFilaRecursivamente(minhaFila);

    printf ("%d", minhaFila->primeiro->data);
    retirar (minhaFila);

    while (!vazia (minhaFila) ) {
        printf (" %d", minhaFila->primeiro->data);
        retirar (minhaFila);
    }
    printf ("\n");

    destroi (minhaFila);

    return 0;
}