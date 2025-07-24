//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define matrix size
#define ROWS 2
#define COLS 2

// Function to print a matrix
void printMatrix(int matrix[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int A[ROWS][COLS], int B[ROWS][COLS], int res[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < COLS; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    // Define two matrices
    int A[ROWS][COLS] = {{1, 2}, {3, 4}};
    int B[ROWS][COLS] = {{2, 0}, {1, 2}};

    // Multiply the matrices
    int C[ROWS][COLS];
    multiplyMatrices(A, B, C);

    // Print the matrices
    printf("Matrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    printf("\nMatrix C (A*B):\n");
    printMatrix(C);

    return 0;
}