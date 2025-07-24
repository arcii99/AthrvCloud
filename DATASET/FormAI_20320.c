//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to print a matrix
void printMatrix(int matrix[][COLS]) {
    printf("Matrix:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for(int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[ROWS][COLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int result[ROWS][COLS];
    
    // Print the matrix1
    printMatrix(matrix1);
    
    // Print the matrix2
    printMatrix(matrix2);
    
    // Add the two matrices
    addMatrices(matrix1, matrix2, result);
    printf("\nAfter Addition:\n");
    printMatrix(result);
    
    // Subtract the two matrices
    subtractMatrices(matrix1, matrix2, result);
    printf("\nAfter Subtraction:\n");
    printMatrix(result);
    
    // Multiply the two matrices
    multiplyMatrices(matrix1, matrix2, result);
    printf("\nAfter Multiplication:\n");
    printMatrix(result);
    
    return 0;
}