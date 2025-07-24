//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define NROWS 3
#define NCOLS 3

void add_matrices(int matrix1[][NCOLS], int matrix2[][NCOLS], int result[][NCOLS]);
void subtract_matrices(int matrix1[][NCOLS], int matrix2[][NCOLS], int result[][NCOLS]);
void multiply_matrices(int matrix1[][NCOLS], int matrix2[][NCOLS], int result[][NCOLS]);

int main()
{
    int matrix1[NROWS][NCOLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[NROWS][NCOLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int result[NROWS][NCOLS];

    printf("Matrix 1:\n");
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Addition:\n");
    add_matrices(matrix1, matrix2, result);
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Subtraction:\n");
    subtract_matrices(matrix1, matrix2, result);
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Multiplication:\n");
    multiply_matrices(matrix1, matrix2, result);
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void add_matrices(int matrix1[][NCOLS], int matrix2[][NCOLS], int result[][NCOLS])
{
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrices(int matrix1[][NCOLS], int matrix2[][NCOLS], int result[][NCOLS])
{
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply_matrices(int matrix1[][NCOLS], int matrix2[][NCOLS], int result[][NCOLS])
{
    for(int i=0; i<NROWS; i++)
    {
        for(int j=0; j<NCOLS; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<NCOLS; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}