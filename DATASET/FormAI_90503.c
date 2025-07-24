//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#define ROWS 3
#define COLS 3

// Function to print matrix
void printMatrix(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < ROWS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
}

int main()
{
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int result[ROWS][COLS];

    // Printing the matrices
    printf("Matrix 1: \n");
    printMatrix(matrix1);
    printf("Matrix 2: \n");
    printMatrix(matrix2);

    // Adding two matrices
    addMatrix(matrix1, matrix2, result);
    printf("Matrix 1 + Matrix 2: \n");
    printMatrix(result);

    // Subtracting two matrices
    subtractMatrix(matrix1, matrix2, result);
    printf("Matrix 1 - Matrix 2: \n");
    printMatrix(result);

    // Multiplying two matrices
    multiplyMatrix(matrix1, matrix2, result);
    printf("Matrix 1 * Matrix 2: \n");
    printMatrix(result);

    return 0;
}