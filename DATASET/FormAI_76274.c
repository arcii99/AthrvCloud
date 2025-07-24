//FormAI DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>

// Function to print a matrix
void printMatrix(int mat[][3], int row, int col)
{
    printf("\nMatrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int mat1[][3], int mat2[][3], int res[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            res[i][j] = mat1[i][j] + mat2[i][j];
}

// Function to subtract two matrices
void subMatrix(int mat1[][3], int mat2[][3], int res[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            res[i][j] = mat1[i][j] - mat2[i][j];
}

// Function to multiply two matrices
void mulMatrix(int mat1[][3], int mat2[][3], int res[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    // Matrix 1
    int mat1[][3] = { {1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9} };

    // Matrix 2
    int mat2[][3] = { {9, 8, 7},
                      {6, 5, 4},
                      {3, 2, 1} };

    // Resultant matrix for addition
    int res_add[3][3];

    // Resultant matrix for subtraction
    int res_sub[3][3];

    // Resultant matrix for multiplication
    int res_mul[3][3];

    // Add matrices
    addMatrix(mat1, mat2, res_add);

    // Subtract matrices
    subMatrix(mat1, mat2, res_sub);

    // Multiply matrices
    mulMatrix(mat1, mat2, res_mul);

    // Print matrices
    printMatrix(mat1, 3, 3);
    printMatrix(mat2, 3, 3);
    printMatrix(res_add, 3, 3);
    printMatrix(res_sub, 3, 3);
    printMatrix(res_mul, 3, 3);

    return 0;
}