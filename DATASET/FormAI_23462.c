//FormAI DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* This program demonstrates the use of matrix operations in C, 
   to perform various operations such as addition, subtraction, 
   multiplication, transposition, and determinant calculation. */

int main()
{
    int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrixC[3][3];

    printf("Matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    // Matrix addition
    printf("\nMatrix Addition:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    // Matrix subtraction
    printf("\nMatrix Subtraction:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    // Matrix multiplication
    printf("\nMatrix Multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            matrixC[i][j] = sum;
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    // Matrix transposition
    printf("\nMatrix Transposition of A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrixA[j][i]);
        }
        printf("\n");
    }

    // Matrix determinant calculation
    printf("\nDeterminant of B:\n");
    int det = 0;
    det = matrixB[0][0]*(matrixB[1][1]*matrixB[2][2]-matrixB[1][2]*matrixB[2][1])
          -matrixB[0][1]*(matrixB[1][0]*matrixB[2][2]-matrixB[1][2]*matrixB[2][0])
          +matrixB[0][2]*(matrixB[1][0]*matrixB[2][1]-matrixB[1][1]*matrixB[2][0]);
    printf("%d\n", det);

    return 0;
}