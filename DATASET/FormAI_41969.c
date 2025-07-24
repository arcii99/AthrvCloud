//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main(void) {
    int i, j, k; // loop variables
    int matrixA[SIZE][SIZE];
    int matrixB[SIZE][SIZE];
    int matrixC[SIZE][SIZE]; // result matrix
    clock_t begin, end;
    double time_spent;

    srand(time(NULL)); // seed for random number generation

    // initialize matrices A and B with random numbers
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }
    }

    // calculate matrix multiplication and time it
    begin = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrixC[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    end = clock();

    // print time taken
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}