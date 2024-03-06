#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000

void swap (int array[], int i, int j);
void printArray (int array[], int n);

void quickSort (int array[], int inicio, int fim);
int partition (int array[], int inicio, int fim);

int main () {

    int n; static int vetor [MAX];
    scanf ("%d", &n);

    srand (time (NULL));

    for (int i = 0; i < n; i++)
        vetor [i] = rand () % 10001;

    double tempo = 0.0;
    clock_t inicio = clock ();
        
    quickSort (vetor, 0, n - 1);

    clock_t fim = clock ();
    tempo += (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf ("Execution time: %fs\n", tempo);
    // printArray (vetor, n);
    
    system ("pause");

    return 0;
}

void swap (int array[], int i, int j) {
    int aux = array [i];
    array [i] = array [j];
    array [j] = aux;
}

void printArray (int array[], int n) {
    for (int i = 0; i < n; i++)
        printf ("%d ", array[i]);
    printf ("\n");
}

void quickSort (int array[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int pivot = partition (array, inicio, fim);

    quickSort (array, inicio, pivot - 1);
    quickSort (array, pivot + 1, fim);
}

int partition (int array[], int inicio, int fim) {
    int k = inicio;

    for (int i = inicio; i < fim; i++) {
        if (array [i] <= array [fim])
            swap (array, k++, i);
    }

    swap (array, k, fim);

    return k;
}