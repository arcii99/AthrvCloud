//FormAI DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to initialize matrix with random values
void initializeMatrix(int matrix[][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10; // Values from 0 to 9
        }
    }
}

// Function to print matrix
void printMatrix(int matrix[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int matrix[][COLS], int matrix2[][COLS], int result[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int matrix[][COLS], int matrix2[][COLS], int result[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix[i][j] - matrix2[i][j];
        }
    }
}

// Main function
int main() {
    printf("Welcome to the matrix operations program!\n");

    // Initialize matrices
    int matrixA[ROWS][COLS];
    int matrixB[ROWS][COLS];
    int result[ROWS][COLS];

    printf("Initializing first matrix...\n");
    initializeMatrix(matrixA);

    printf("Initializing second matrix...\n");
    initializeMatrix(matrixB);

    printf("Matrix A:\n");
    printMatrix(matrixA);

    printf("Matrix B:\n");
    printMatrix(matrixB);

    // Add matrices and print result
    printf("Adding Matrix A and Matrix B...\n");
    addMatrix(matrixA, matrixB, result);
    printMatrix(result);

    // Subtract matrices and print result
    printf("Subtracting Matrix A and Matrix B...\n");
    subtractMatrix(matrixA, matrixB, result);
    printMatrix(result);

    printf("Thank you for using the matrix operations program.\n");

    return 0;
}