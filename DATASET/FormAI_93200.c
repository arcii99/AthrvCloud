//FormAI DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addMatrix(int *matrixA, int *matrixB, int *result, int size) {
    int i, j, index;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            index = size * i + j;
            *(result + index) = *(matrixA + index) + *(matrixB + index);
        }
    }
}

int main() {
    const int SIZE = 1000;
    int i, j, index;

    int *matrixA = (int*) malloc(SIZE * SIZE * sizeof(int));
    int *matrixB = (int*) malloc(SIZE * SIZE * sizeof(int));
    int *result = (int*) malloc(SIZE * SIZE * sizeof(int));

    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            index = SIZE * i + j;
            *(matrixA + index) = rand() % 101;
            *(matrixB + index) = rand() % 101;
        }
    }

    clock_t start = clock();
    addMatrix(matrixA, matrixB, result, SIZE);
    clock_t end = clock();
    double time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Addition of two %dx%d matrices in C took %lf seconds\n", SIZE, SIZE, time_spent);

    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}