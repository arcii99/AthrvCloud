//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>

// Function to print the matrix
void printMatrix(int matrix[][3], int rows, int cols) {
    printf("\n");

    for (int r = 0; r < rows; ++r) {
        printf("| ");
        for (int c = 0; c < cols; ++c) {
            printf("%d ", matrix[r][c]);
        }
        printf("|\n");
    }

    printf("\n");
}

// Function to add two matrices
void addMatrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            result[r][c] = matrix1[r][c] + matrix2[r][c];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    int sum = 0;

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            for (int i = 0; i < 3; ++i) {
                sum += matrix1[r][i] * matrix2[i][c];
            }
            result[r][c] = sum;
            sum = 0;
        }
    }
}

int main() {
    printf("\n");

    // Creating the first matrix
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Creating the second matrix
    int matrix2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // Creating the result matrix
    int result[3][3];

    // Printing the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);

    printf("Matrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // Adding the matrices and printing the result
    addMatrices(matrix1, matrix2, result);
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(result, 3, 3);

    // Multiplying the matrices and printing the result
    multiplyMatrices(matrix1, matrix2, result);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(result, 3, 3);

    printf("\n");

    return 0;
}