//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void transposeMatrix(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrixA[ROWS][COLS] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    int matrixB[ROWS][COLS] = {{9, 8, 7},
                               {6, 5, 4},
                               {3, 2, 1}};

    int result[ROWS][COLS];

    printf("Matrix A:\n");
    printMatrix(matrixA);

    printf("\nMatrix B:\n");
    printMatrix(matrixB);

    printf("\nAdding Matrix A and Matrix B:\n");
    addMatrix(matrixA, matrixB, result);
    printMatrix(result);

    int transpose[COLS][ROWS];
    printf("\nTransposing Matrix A:\n");
    transposeMatrix(matrixA, transpose);
    printMatrix(transpose);

    return 0;
}