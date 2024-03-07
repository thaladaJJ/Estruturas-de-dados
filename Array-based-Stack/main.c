#include <stdio.h>                                 
#include <stdlib.h>  
#include <string.h>
#include "pilha.h"

#define MAX 100000

int cadeiaDefinida (const char *cadeia) {

    pilha p = inicializar (strlen(cadeia));

        for (int j = 0; cadeia[j] != '\0'; j++) {

            if (cadeia [j] == '(' || cadeia [j] == '[' || cadeia [j] == '{')
                inserir (p, cadeia[j]);

            else if (cadeia [j] == ')' || cadeia [j] == ']' || cadeia [j] == '}') {
                
                if (vazio (p)) {
                    destruir (p);
                    return 0;
                }

                T abertura = remover (p);
                if ((cadeia[j] == ')' && abertura != '(') ||
                    (cadeia[j] == ']' && abertura != '[') ||
                    (cadeia[j] == '}' && abertura != '{')) 
                {
                    destruir(p);
                    return 0;
                }
            }
        }

    int definida = vazio (p);

    destruir (p);

    return definida;
}

int main () {

    int num_instancias;
    scanf ("%d", &num_instancias);

    int i = 0;

    while (i < num_instancias) {

        char cadeia [MAX];
        scanf ("%s", cadeia);

        cadeiaDefinida (cadeia) ? printf ("S\n") : printf ("N/n");

        i++;
    }

    return 0;
}