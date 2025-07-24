//FormAI DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int mat[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int mat1[][COLS], int mat2[][COLS], int res[][COLS], int rows1, int cols2)
{
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[][COLS], int rows, int cols)
{
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main()
{
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];
    
    printf("Matrix 1:\n");
    printMatrix(matrix1, ROWS, COLS);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, ROWS, COLS);
    
    printf("\nMultiplication of Matrix 1 and Matrix 2:\n");
    multiplyMatrix(matrix1, matrix2, result, ROWS, COLS);
    printMatrix(result, ROWS, COLS);
    
    printf("\nTranspose of Matrix 1:\n");
    transposeMatrix(matrix1, ROWS, COLS);
    printMatrix(matrix1, ROWS, COLS);
    
    return 0;
}