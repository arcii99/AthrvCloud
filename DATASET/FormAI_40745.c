//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void multiplyByScalar(int matrix[ROWS][COLS], int scalar) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            matrix[row][col] *= scalar;
        }
    }
}

void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            matrix1[row][col] += matrix2[row][col];
        }
    }
}

void transposeMatrix(int matrix[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = row + 1; col < COLS; ++col) {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
}

int main() {
    int matrixA[ROWS][COLS];
    int matrixB[ROWS][COLS];
    int scalar = 3;

    // Fill the matrices with random values
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            matrixA[row][col] = rand() % 10;
            matrixB[row][col] = rand() % 10;
        }
    }

    // Print the original matrices
    printf("Matrix A:\n");
    printMatrix(matrixA);
    printf("Matrix B:\n");
    printMatrix(matrixB);

    // Multiply matrix A by scalar
    multiplyByScalar(matrixA, scalar);
    printf("Matrix A multiplied by scalar:\n");
    printMatrix(matrixA);

    // Add matrix A and matrix B
    addMatrices(matrixA, matrixB);
    printf("Matrix A + matrix B:\n");
    printMatrix(matrixA);

    // Transpose matrix B
    transposeMatrix(matrixB);
    printf("Transpose of matrix B:\n");
    printMatrix(matrixB);

    return 0;
}