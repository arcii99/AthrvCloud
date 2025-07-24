//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to print a matrix
void printMatrix(int matrix[][COLS], int rows) {
    printf("\nMatrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int mat1[][COLS], int mat2[][COLS], int result[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int mat1[][COLS], int mat2[][COLS], int result[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;

            for (int k = 0; k < COLS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];

    // Print matrices
    printMatrix(mat1, ROWS);
    printMatrix(mat2, ROWS);

    // Add matrices
    addMatrix(mat1, mat2, result, ROWS);
    printf("\nAddition:\n");
    printMatrix(result, ROWS);

    // Multiply matrices
    multiplyMatrix(mat1, mat2, result, ROWS);
    printf("\nMultiplication:\n");
    printMatrix(result, ROWS);

    return 0;
}