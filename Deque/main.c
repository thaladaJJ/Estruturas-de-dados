#include <stdio.h>             
#include <stdlib.h>
#include <string.h>
#include "deque.h"

int main () {

    unsigned num_comandos, max_deque;
    scanf ("%u %u", &num_comandos, &max_deque);

    deque *minhaDeque = malloc (sizeof (deque));    
    inicializar (minhaDeque, max_deque);

    char comando [50]; int number;

    unsigned i = 0;
    while (i < num_comandos) {

        scanf ("%s", comando);

        if (!strcmp(comando, "insereI")) {
            scanf ("%d", &number);
            inserir_inicio (minhaDeque, number);
        }

        else if (!strcmp (comando, "insereF")) {
            scanf ("%d", &number);
            inserir_fim (minhaDeque, number);
        }

        else if (!strcmp (comando, "removeI"))
            retirar_inicio (minhaDeque);
        
        else if (!strcmp (comando, "removeF"))
            retirar_fim (minhaDeque);

        i++;
    }

    destroi (minhaDeque);

    return 0;
}