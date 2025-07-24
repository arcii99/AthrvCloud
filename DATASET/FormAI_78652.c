//FormAI DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3

// function to print a matrix
void printMatrix(int matrix[MAX_ROWS][MAX_COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to add two matrices
void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function to subtract two matrices
void subtractMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// function to find the transpose of a matrix
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[MAX_ROWS][MAX_COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[MAX_ROWS][MAX_COLS];

    // add matrices and print the result
    addMatrices(matrix1, matrix2, result);
    printf("Addition:\n");
    printMatrix(result);

    // subtract matrices and print the result
    subtractMatrices(matrix1, matrix2, result);
    printf("Subtraction:\n");
    printMatrix(result);

    // find the transpose of matrix 1 and print the result
    transposeMatrix(matrix1, result);
    printf("Transpose of Matrix 1:\n");
    printMatrix(result);

    return 0;
}