//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[][COLS]);
void matrixAddition(int matrix1[][COLS], int matrix2[][COLS], int resultMatrix[][COLS]);
void matrixMultiplication(int matrix1[][COLS], int matrix2[][COLS], int resultMatrix[][COLS]);
void transpose(int matrix[][COLS], int resultMatrix[][ROWS]);

int main()
{
    // Define matrices
    int matrix1[ROWS][COLS] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    int matrix2[ROWS][COLS] = {{11, 12, 13},
                               {14, 15, 16},
                               {17, 18, 19}};

    int resultMatrix[ROWS][COLS];

    printf("Matrix1:\n");
    printMatrix(matrix1);

    printf("\nMatrix2:\n");
    printMatrix(matrix2);

    printf("\nMatrix1 + Matrix2:\n");
    matrixAddition(matrix1, matrix2, resultMatrix);
    printMatrix(resultMatrix);

    printf("\nMatrix1 * Matrix2:\n");
    matrixMultiplication(matrix1, matrix2, resultMatrix);
    printMatrix(resultMatrix);

    printf("\nTranspose of Matrix1:\n");
    transpose(matrix1, resultMatrix);
    printMatrix(resultMatrix);

    return 0;
}

// Function to print matrix
void printMatrix(int matrix[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void matrixAddition(int matrix1[][COLS], int matrix2[][COLS], int resultMatrix[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void matrixMultiplication(int matrix1[][COLS], int matrix2[][COLS], int resultMatrix[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose(int matrix[][COLS], int resultMatrix[][ROWS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[j][i] = matrix[i][j];
        }
    }
}