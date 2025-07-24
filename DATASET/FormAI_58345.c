//FormAI DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COLUMN 3

/* Functions for matrix operations */
void fill_matrix(int matrix[][COLUMN], int rows, int columns);
void print_matrix(int matrix[][COLUMN], int rows, int columns);
void sum_matrix(int matrix1[][COLUMN], int matrix2[][COLUMN], int result[][COLUMN]);

int main()
{
    int matrixA[ROW][COLUMN], matrixB[ROW][COLUMN], result[ROW][COLUMN];

    srand(time(NULL));  // Initialize random number generator

    printf("Filling matrix A:\n");
    fill_matrix(matrixA, ROW, COLUMN);

    printf("\nFilling matrix B:\n");
    fill_matrix(matrixB, ROW, COLUMN);

    printf("\nMatrix A:\n");
    print_matrix(matrixA, ROW, COLUMN);

    printf("\nMatrix B:\n");
    print_matrix(matrixB, ROW, COLUMN);

    printf("\nSum of matrix A and B:\n");
    sum_matrix(matrixA, matrixB, result);
    print_matrix(result, ROW, COLUMN);

    return 0;
}

/* Function to fill matrix with random numbers */
void fill_matrix(int matrix[][COLUMN], int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 10; // Fill with random numbers between 0-9
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to print matrix */
void print_matrix(int matrix[][COLUMN], int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to add two matrices */
void sum_matrix(int matrix1[][COLUMN], int matrix2[][COLUMN], int result[][COLUMN])
{
    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}