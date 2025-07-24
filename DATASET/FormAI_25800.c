//FormAI DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 3
#define COLUMN 3

void printMatrix(int matrix[][COLUMN], int row, int column)
{
    printf("Matrix:\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition(int matrix1[][COLUMN], int matrix2[][COLUMN], int row, int column)
{
    int result[row][column];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printMatrix(result, row, column);
}

void matrixSubtraction(int matrix1[][COLUMN], int matrix2[][COLUMN], int row, int column)
{
    int result[row][column];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    printMatrix(result, row, column);
}

bool areMatricesEqual(int matrix1[][COLUMN], int matrix2[][COLUMN], int row, int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(matrix1[i][j] != matrix2[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void matrixMultiplication(int matrix1[][COLUMN], int matrix2[][COLUMN], int row1, int column1, int row2, int column2)
{
    if(column1 != row2)
    {
        printf("Multiplication of these two matrices is not possible.");
        return;
    }

    int result[row1][column2];

    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<column2; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<column1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printMatrix(result, row1, column2);
}

int main()
{
    int matrix1[ROW][COLUMN] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROW][COLUMN] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int matrix3[ROW][COLUMN] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix4[ROW][COLUMN] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int matrix5[ROW][COLUMN] = {{1, 2}, {3, 4}, {5, 6}};
    int matrix6[ROW][COLUMN] = {{1, 2, 3}, {4, 5, 6}};

    printf("Matrix Operations\n");

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, ROW, COLUMN);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, ROW, COLUMN);

    printf("\nAdding Matrix 1 and Matrix 2:\n");
    matrixAddition(matrix1, matrix2, ROW, COLUMN);

    printf("\nSubtracting Matrix 1 from Matrix 2:\n");
    matrixSubtraction(matrix2, matrix1, ROW, COLUMN);

    printf("\nChecking if Matrix 1 and Matrix 3 are equal:\n");
    if(areMatricesEqual(matrix1, matrix3, ROW, COLUMN))
    {
        printf("Matrix 1 and Matrix 3 are equal.\n");
    }
    else
    {
        printf("Matrix 1 and Matrix 3 are not equal.\n");
    }

    printf("\nChecking if Matrix 1 and Matrix 2 are equal:\n");
    if(areMatricesEqual(matrix1, matrix2, ROW, COLUMN))
    {
        printf("Matrix 1 and Matrix 2 are equal.\n");
    }
    else
    {
        printf("Matrix 1 and Matrix 2 are not equal.\n");
    }

    printf("\nMultiplying Matrix 5 and Matrix 6:\n");
    matrixMultiplication(matrix5, matrix6, 3, 2, 2, 3);

    return 0;
}