//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Result of matrix addition: \n");
    printMatrix(result);
}

void scalarProduct(int scalar, int matrix[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = scalar * matrix[i][j];
        }
    }
    printf("Result of scalar product: \n");
    printMatrix(result);
}

void matrixProduct(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int sum = 0;
            for(int k=0; k<COLS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    printf("Result of matrix product: \n");
    printMatrix(result);
}

int main() {
    int matrix1[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix2[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    printf("Matrix 1: \n");
    printMatrix(matrix1);
    printf("\n");
    printf("Matrix 2: \n");
    printMatrix(matrix2);
    printf("\n");
    addMatrix(matrix1, matrix2);
    printf("\n");
    scalarProduct(3, matrix1);
    printf("\n");
    matrixProduct(matrix1, matrix2);
    return 0;
}