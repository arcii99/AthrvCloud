//FormAI DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

/* Matrix Multiplication Function */
void matrix_multiplication(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS])
{
    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            resultMatrix[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

/* Matrix Addition Function */
void matrix_addition(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

/* Matrix Subtraction Function */
void matrix_subtraction(int firstMatrix[ROWS][COLS], int secondMatrix[ROWS][COLS], int resultMatrix[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            resultMatrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
}

int main()
{
    int firstMatrix[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int secondMatrix[ROWS][COLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int resultMatrix[ROWS][COLS];

    printf("First Matrix:\n");
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", firstMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", secondMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix Multiplication:\n");
    matrix_multiplication(firstMatrix, secondMatrix, resultMatrix);
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Addition:\n");
    matrix_addition(firstMatrix, secondMatrix, resultMatrix);
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Subtraction:\n");
    matrix_subtraction(firstMatrix, secondMatrix, resultMatrix);
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}