//FormAI DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>

// Function to print a matrix
void printMatrix(int m[][3], int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int m1[][3], int m2[][3], int rows, int cols)
{
    int result[rows][cols];
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            result[i][j] = m1[i][j] + m2[i][j];
    }
    printf("\nResult after addition:\n");
    printMatrix(result, rows, cols);
}

// Function to multiply two matrices
void multiplyMatrix(int m1[][3], int m2[][3], int rows1, int cols1, int rows2, int cols2)
{
    if(cols1 != rows2)
    {
        printf("Matrices cannot be multiplied!\n");
        return;
    }
    int result[rows1][cols2];
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++)
                result[i][j] += m1[i][k] * m2[k][j];
        }
    }
    printf("\nResult after multiplication:\n");
    printMatrix(result, rows1, cols2);
}

int main()
{
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int rows = 3, cols = 3;

    printf("Matrix 1:\n");
    printMatrix(matrix1, rows, cols);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows, cols);

    addMatrix(matrix1, matrix2, rows, cols);

    multiplyMatrix(matrix1, matrix2, rows, cols, rows, cols);

    return 0;
}