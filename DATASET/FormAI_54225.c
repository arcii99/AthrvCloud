//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

// Define number of rows and columns
#define ROWS 3
#define COLS 3

// Function to print Matrix
void printMatrix(int matrix[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply Matrix
void multiplyMatrix(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j, k;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            // set initial result value to 0
            result[i][j] = 0;
            for(k = 0; k < COLS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to perform the transpose of a matrix
void transposeMatrix(int mat[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int resultMatrix[ROWS][COLS];

    // Print Initial Matrices
    printf("Matrix 1: \n");
    printMatrix(matrix1);

    printf("Matrix 2: \n");
    printMatrix(matrix2);

    // Matrix Multiplication
    multiplyMatrix(matrix1, matrix2, resultMatrix);
    printf("Multiplication Result: \n");
    printMatrix(resultMatrix);

    // Matrix Transpose
    int transposeMatrix1[ROWS][COLS];
    transposeMatrix(matrix1, transposeMatrix1);
    printf("Matrix 1 Transpose: \n");
    printMatrix(transposeMatrix1);

    int transposeMatrix2[ROWS][COLS];
    transposeMatrix(matrix2, transposeMatrix2);
    printf("Matrix 2 Transpose: \n");
    printMatrix(transposeMatrix2);

    return 0;
}