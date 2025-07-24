//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the matrix size
#define ROWS 3
#define COLS 3

// Function to display the matrix
void displayMatrix(int matrix[ROWS][COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrix(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]) {
    printf("Adding two matrices...\n");

    // Create a new matrix to store the result
    int resultMatrix[ROWS][COLS];

    // Loop through the matrices and add the values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Display the result
    displayMatrix(resultMatrix);
}

// Function to subtract two matrices
void subtractMatrix(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]) {
    printf("Subtracting two matrices...\n");

    // Create a new matrix to store the result
    int resultMatrix[ROWS][COLS];

    // Loop through the matrices and subtract the values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    // Display the result
    displayMatrix(resultMatrix);
}

// Function to multiply two matrices
void multiplyMatrix(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]) {
    printf("Multiplying two matrices...\n");

    // Create a new matrix to store the result
    int resultMatrix[ROWS][COLS];

    // Loop through the matrices and multiply the values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            resultMatrix[i][j] = sum;
        }
    }

    // Display the result
    displayMatrix(resultMatrix);
}

int main() {
    printf("Welcome to the Matrix operation program!\n\n");

    // Initialize the matrices
    int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Display the initial matrices
    displayMatrix(matrixA);
    displayMatrix(matrixB);

    // Perform matrix operations
    addMatrix(matrixA, matrixB);
    subtractMatrix(matrixA, matrixB);
    multiplyMatrix(matrixA, matrixB);

    printf("Thanks for using the Matrix operation program! Goodbye!\n");

    return 0;
}