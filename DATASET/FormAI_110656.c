//FormAI DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the matrix size for this example
#define ROWS 3
#define COLS 3

// Function to print a matrix
void printMatrix(int (*matrix)[COLS], char *name) {
    printf("%s = \n", name);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    // Declare and initialize two matrices
    int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Print the original matrices
    printMatrix(matrixA, "matrixA");
    printMatrix(matrixB, "matrixB");

    // Declare a third matrix for the results of the operations
    int matrixC[ROWS][COLS];

    // Perform matrix addition
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print the results of the addition
    printMatrix(matrixC, "matrixA + matrixB");

    // Perform matrix subtraction
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    // Print the results of the subtraction
    printMatrix(matrixC, "matrixA - matrixB");

    // Perform matrix multiplication
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int result = 0;
            for (int k = 0; k < ROWS; k++) {
                result += matrixA[i][k] * matrixB[k][j];
            }
            matrixC[i][j] = result;
        }
    }

    // Print the results of the multiplication
    printMatrix(matrixC, "matrixA * matrixB");

    return 0;
}