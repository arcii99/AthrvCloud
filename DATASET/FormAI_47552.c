//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>

/**
 * This program demonstrates several matrix operations in C language.
 * The program includes functions to add, subtract, and multiply two matrices,
 * find transpose of a matrix, and determine if a matrix is symmetric or not.
 */

#define ROWS 3
#define COLS 3

/**
 * Function to add two matrices and return the result
 */
void add_matrices(int a[][COLS], int b[][COLS], int result[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

/**
 * Function subtract two matrices and return the result
 */
void subtract_matrices(int a[][COLS], int b[][COLS], int result[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

/**
 * Function to multiply two matrices and return the result
 */
void multiply_matrices(int a[][COLS], int b[][COLS], int result[][COLS])
{
    int i, j, k;
    int sum;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            sum = 0;
            for (k = 0; k < COLS; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

/**
 * Function to calculate transpose of a matrix and return the result
 */
void transpose_matrix(int a[][COLS], int result[][ROWS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            result[j][i] = a[i][j];
        }
    }
}

/**
 * Function to check if a matrix is symmetric or not
 */
int is_symmetric(int a[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = i+1; j < COLS; j++)
        {
            if (a[i][j] != a[j][i])
                return 0;
        }
    }
    return 1;
}

/**
 * The main function of the program
 */
int main()
{
    // Define two matrices
    int matrix1[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[ROWS][COLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

    // Define result matrices
    int result_add[ROWS][COLS];
    int result_subtract[ROWS][COLS];
    int result_multiply[ROWS][COLS];
    int result_transpose[COLS][ROWS];

    // Call functions to perform matrix operations
    add_matrices(matrix1, matrix2, result_add);
    subtract_matrices(matrix1, matrix2, result_subtract);
    multiply_matrices(matrix1, matrix2, result_multiply);
    transpose_matrix(matrix1, result_transpose);

    // Display the results
    printf("Matrix1:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix2:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Result of addition:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", result_add[i][j]);
        }
        printf("\n");
    }

    printf("Result of subtraction:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", result_subtract[i][j]);
        }
        printf("\n");
    }

    printf("Result of multiplication:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", result_multiply[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of matrix1:\n");
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            printf("%d ", result_transpose[i][j]);
        }
        printf("\n");
    }

    if (is_symmetric(matrix1))
        printf("Matrix1 is symmetric.\n");
    else
        printf("Matrix1 is not symmetric.\n");

    if (is_symmetric(matrix2))
        printf("Matrix2 is symmetric.\n");
    else
        printf("Matrix2 is not symmetric.\n");

    return 0;
}