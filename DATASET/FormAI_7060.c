//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include<stdio.h>

// Function to print matrix
void printMatrix(int mat[][3], int row, int col)
{
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[][3] = { { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 } };
    int mat2[][3] = { { 9, 8, 7 },
                    { 6, 5, 4 },
                    { 3, 2, 1 } };
    int row = 3, col = 3;

    // Display the matrices
    printf("Matrix 1:\n");
    printMatrix(mat1, row, col);
    printf("\n");
    printf("Matrix 2:\n");
    printMatrix(mat2, row, col);
    printf("\n");

    // Matrix addition
    printf("Matrix addition:\n");
    int result1[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printMatrix(result1, row, col);
    printf("\n");

    // Matrix multiplication
    printf("Matrix multiplication:\n");
    int result2[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result2[i][j] = 0;
            for (int k = 0; k < col; k++) {
                result2[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printMatrix(result2, row, col);
    printf("\n");

    // Matrix transpose
    printf("Matrix transpose:\n");
    int result3[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result3[i][j] = mat1[j][i];
        }
    }
    printMatrix(result3, col, row);
    printf("\n");

    return 0;
}