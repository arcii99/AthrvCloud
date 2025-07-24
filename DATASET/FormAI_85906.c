//FormAI DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void add(int matrix1[][COLS], int matrix2[][COLS], int addResult[][COLS]);
void multiply(int matrix1[][COLS], int matrix2[][COLS], int multResult[][COLS]);
void printMatrix(int matrix[][COLS]);

int main()
{
    int matrix1[ROWS][COLS] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    int matrix2[ROWS][COLS] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    int addResult[ROWS][COLS] = {0};
    int multResult[ROWS][COLS] = {0};

    add(matrix1, matrix2, addResult);
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);
    printf("Matrix Addition Result:\n");
    printMatrix(addResult);

    multiply(matrix1, matrix2, multResult);
    printf("Matrix Multiplication Result:\n");
    printMatrix(multResult);

    return 0;
}

void add(int matrix1[][COLS], int matrix2[][COLS], int addResult[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            addResult[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiply(int matrix1[][COLS], int matrix2[][COLS], int multResult[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            for (int k = 0; k < COLS; k++)
            {
                multResult[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}