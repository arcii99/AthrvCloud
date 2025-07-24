//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

int main() {
    int **matrix = (int **) malloc(MATRIX_SIZE * sizeof(int *));
    srand(time(NULL));
    
    printf("Initializing matrix with random values...\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix[i] = (int *) malloc(MATRIX_SIZE * sizeof(int));
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    printf("Multiplying matrix by itself...\n");
    clock_t start = clock();
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int sum = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            matrix[i][j] = sum;
        }
    }
    clock_t end = clock();
    
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    printf("Destroying matrix...\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}