//FormAI DATASET v1.0 Category: Matrix operations ; Style: bold
// A bold example program for performing various operations on matrices in C

#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void printMatrix(int mat[][COLS]);
void addMatrices(int mat1[][COLS], int mat2[][COLS], int result[][COLS]);
void multiplyMatrices(int mat1[][COLS], int mat2[][COLS], int result[][COLS]);
void transposeMatrix(int mat[][COLS], int result[][ROWS]);

int main() {

    // Define the matrices
    int matrixA[ROWS][COLS] = { {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9} };

    int matrixB[ROWS][COLS] = { {9, 8, 7},
                                {6, 5, 4},
                                {3, 2, 1} };

    int resultMatrix[ROWS][COLS];

    // Perform matrix addition and print the result
    addMatrices(matrixA, matrixB, resultMatrix);
    printf("\nMatrix Addition Result:\n");
    printMatrix(resultMatrix);

    // Perform matrix multiplication and print the result
    multiplyMatrices(matrixA, matrixB, resultMatrix);
    printf("\nMatrix Multiplication Result:\n");
    printMatrix(resultMatrix);

    // Perform matrix transpose and print the result
    int transposeResult[COLS][ROWS];
    transposeMatrix(matrixA, transposeResult);
    printf("\nMatrix Transpose Result:\n");
    printMatrix(transposeResult);

    return 0;
}

// Function to print a matrix
void printMatrix(int mat[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
    int i, j, k;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for(k = 0; k < ROWS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int mat[][COLS], int result[][ROWS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            result[j][i] = mat[i][j];
        }
    }
}