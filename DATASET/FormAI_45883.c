//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to populate the matrix with random values
void populateMatrix(int matrix[][COLS]) {
    srand(time(0));  // Set the seed
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;  // Generate a random number between 0 and 9
        }
    }
}

// Function to display the matrix
void displayMatrix(int matrix[][COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA[ROWS][COLS], matrixB[ROWS][COLS], sumMatrix[ROWS][COLS];

    // Populate the matrices with random values
    populateMatrix(matrixA);
    populateMatrix(matrixB);

    // Display the matrices
    displayMatrix(matrixA);
    displayMatrix(matrixB);

    // Add the matrices element-wise
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Display the resulting matrix
    displayMatrix(sumMatrix);

    return 0;
}