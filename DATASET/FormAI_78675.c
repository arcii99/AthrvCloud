//FormAI DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printMatrix(int matrix[SIZE][SIZE]) {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(int matrix[SIZE][SIZE]) {
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void multiplyMatrix(int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for(int k = 0; k < SIZE; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE], result[SIZE][SIZE];

    fillMatrix(matrixA);
    printMatrix(matrixA);
    
    fillMatrix(matrixB);
    printMatrix(matrixB);
    
    multiplyMatrix(matrixA, matrixB, result);
    printMatrix(result);

    return 0;
}