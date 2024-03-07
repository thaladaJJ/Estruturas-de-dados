#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main () {

    lista numbers;
    inicializar (&numbers);

    int i = 1;
    while (i < 30) {
        inserirFinal (&numbers, i);
        i++;
    }

    printf ("%d\n", menorNo (&numbers));

    destruir (&numbers);

    return 0;
}