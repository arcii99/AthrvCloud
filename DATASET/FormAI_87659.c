//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

// function to print a matrix
void printMatrix(int mat[][3], int row, int col)
{
    printf("Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
void matrixMultiply(int mat1[][3], int mat2[][3], int res[][3])
{
    // rows of first matrix
    int row1 = 3;

    // columns of second matrix
    int col2 = 3;

    // columns of first matrix and rows of second matrix should be same
    int row2 = 3, col1 = 3; 

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    // initialize two 3x3 matrices
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // initialize result matrix
    int res[3][3];

    // print initial matrices
    printf("Initial ");
    printMatrix(mat1, 3, 3);
    printMatrix(mat2, 3, 3);

    // multiply matrices
    matrixMultiply(mat1, mat2, res);

    // print result matrix
    printf("Result ");
    printMatrix(res, 3, 3);

    return 0;
}