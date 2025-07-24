//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>

// Define the size of the matrix
#define ROWS 3
#define COLS 3


// Function to print matrix on console
void displayMatrix(int matrix[ROWS][COLS])
{
    printf("Matrix:\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS])
{
    int result[ROWS][COLS];

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    displayMatrix(result);
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS])
{
    int result[ROWS][COLS];

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    displayMatrix(result);
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS])
{
    int result[ROWS][COLS];

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < COLS; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    displayMatrix(result);
}

int main()
{
    int matrix1[ROWS][COLS] = { {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9} };

    int matrix2[ROWS][COLS] = { {9, 8, 7},
                                {6, 5, 4},
                                {3, 2, 1} };
                                
    // Perform addition of matrix1 and matrix2                                
    printf("Addition:\n");
    addMatrices(matrix1, matrix2);
                                
    // Perform subtraction of matrix1 and matrix2
    printf("Subtraction:\n");
    subtractMatrices(matrix1, matrix2);

    // Perform multiplication of matrix1 and matrix2
    printf("Multiplication:\n");
    multiplyMatrices(matrix1, matrix2);

    return 0;
}