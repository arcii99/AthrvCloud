//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>

// Define the matrix size
#define ROWS 3
#define COLS 3

// Define the matrix operations
void printMatrix(int matrix[ROWS][COLS]);
void sumMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]);
void subtractMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]);
void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]);

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("Matrix 2:\n");
    printMatrix(matrix2);

    printf("Matrix 1 + Matrix 2:\n");
    sumMatrix(matrix1, matrix2);

    printf("Matrix 1 - Matrix 2:\n");
    subtractMatrix(matrix1, matrix2);

    printf("Matrix 1 x Matrix 2:\n");
    multiplyMatrix(matrix1, matrix2);

    return 0;
}

// Print the given matrix
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

// Sum of given two matrices
void sumMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int sumMatrix[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", sumMatrix[i][j]);
        }

        printf("\n");
    }
}

// Subtract of given two matrices
void subtractMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int subtractMatrix[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            subtractMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", subtractMatrix[i][j]);
        }

        printf("\n");
    }
}

// Multiply of given two matrices
void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int multiplyMatrix[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            multiplyMatrix[i][j] = 0;

            for (int k = 0; k < ROWS; k++) {
                multiplyMatrix[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }

            printf("%d ", multiplyMatrix[i][j]);
        }

        printf("\n");
    }
}