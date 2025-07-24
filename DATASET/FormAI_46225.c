//FormAI DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void initializeMatrix(int matrix[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    int i, j, k;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            resultMatrix[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[ROWS][COLS], matrixB[ROWS][COLS], resultMatrix[ROWS][COLS];

    printf("Matrix A:\n");
    initializeMatrix(matrixA);
    printMatrix(matrixA);

    printf("\nMatrix B:\n");
    initializeMatrix(matrixB);
    printMatrix(matrixB);

    printf("\nMatrix A + B:\n");
    addMatrices(matrixA, matrixB, resultMatrix);
    printMatrix(resultMatrix);

    printf("\nMatrix A * B:\n");
    multiplyMatrices(matrixA, matrixB, resultMatrix);
    printMatrix(resultMatrix);

    return 0;
}