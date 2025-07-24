//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>

#define ROWS 3
#define COLS 4

// Function to print the matrix
void printMatrix(int matrix[][COLS], int rows) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply the matrix by a scalar
void scalarMultiplication(int matrix[][COLS], int rows, int scalar) {
    printf("\nScalar Multiplication of Matrix by %d:\n", scalar);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] *= scalar;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int a[][COLS], int b[][COLS], int rows) {
    int result[ROWS][COLS];
    printf("\nMatrix Addition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] + b[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int scalar = 2;
    int matrix2[ROWS][COLS] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3}
    };

    printf("Matrix operations using C program:\n");

    // Print the matrix
    printMatrix(matrix, ROWS);

    // Scalar multiplication
    scalarMultiplication(matrix, ROWS, scalar);

    // Matrix addition
    addMatrix(matrix, matrix2, ROWS);

    return 0;
}