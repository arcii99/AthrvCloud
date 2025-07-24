//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

void initialize_matrices(int matrix_a[MATRIX_SIZE][MATRIX_SIZE], int matrix_b[MATRIX_SIZE][MATRIX_SIZE])
{
    int i, j;
    srand(time(0));
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            matrix_a[i][j] = rand() % 10;
            matrix_b[i][j] = rand() % 10;
        }
    }
}

void multiply_matrices(int matrix_a[MATRIX_SIZE][MATRIX_SIZE], int matrix_b[MATRIX_SIZE][MATRIX_SIZE], int result_matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int i, j, k;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            result_matrix[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++)
            {
                result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

int main()
{
    int matrix_a[MATRIX_SIZE][MATRIX_SIZE];
    int matrix_b[MATRIX_SIZE][MATRIX_SIZE];
    int result_matrix[MATRIX_SIZE][MATRIX_SIZE];
    initialize_matrices(matrix_a, matrix_b);
    multiply_matrices(matrix_a, matrix_b, result_matrix);
    printf("Result Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}