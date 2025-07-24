//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void printMatrix(int matrix[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            printf("%d ", matrix[i][j]);
        
        printf("\n");
    }

    printf("\n");
}

void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

void subtractMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            result[i][j] = 0;

            for(int k = 0; k < ROWS; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

int main()
{
    int matrix1[ROWS][COLS] = {
        {7, 5, 2, 8},
        {3, 9, 4, 1},
        {6, 0, 1, 2},
        {5, 7, 3, 4}
    };

    int matrix2[ROWS][COLS] = {
        {1, 3, 6, 9},
        {2, 9, 4, 1},
        {0, 5, 8, 2},
        {8, 4, 2, 1}
    };

    int result1[ROWS][COLS];
    int result2[ROWS][COLS];
    int result3[ROWS][COLS];

    printf("\t\tMatrix 1:\n");
    printMatrix(matrix1);

    printf("\t\tMatrix 2:\n");
    printMatrix(matrix2);

    printf("\t\tAdding Matrix 1 and Matrix 2:\n");
    addMatrix(matrix1, matrix2, result1);
    printMatrix(result1);

    printf("\t\tSubtracting Matrix 1 and Matrix 2:\n");
    subtractMatrix(matrix1, matrix2, result2);
    printMatrix(result2);

    printf("\t\tMultiplying Matrix 1 and Matrix 2:\n");
    multiplyMatrix(matrix1, matrix2, result3);
    printMatrix(result3);

    return 0;
}