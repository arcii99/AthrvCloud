//FormAI DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>

/* This is a program that performs various operations on matrices */

int main() {

    printf("Welcome to the Matrix Operations Program!\n");

    // create matrix variables
    int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int result[3][3];

    // print out matrices
    printf("\nMatrix A:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    // addition
    printf("\nAdding Matrix A and Matrix B:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // subtraction
    printf("\nSubtracting Matrix B from Matrix A:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // multiplication
    printf("\nMultiplying Matrix A and Matrix B:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            result[i][j] = 0;
            for(int k=0; k<3; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // transpose of matrix A
    printf("\nTranspose of Matrix A:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrixA[j][i]);
        }
        printf("\n");
    }

    // determinant of matrix A
    int det = matrixA[0][0]*(matrixA[1][1]*matrixA[2][2]-matrixA[2][1]*matrixA[1][2]) - matrixA[0][1]*(matrixA[1][0]*matrixA[2][2]-matrixA[2][0]*matrixA[1][2]) + matrixA[0][2]*(matrixA[1][0]*matrixA[2][1]-matrixA[2][0]*matrixA[1][1]);
    printf("\nDeterminant of Matrix A: %d\n", det);

    printf("\nThanks for using the Matrix Operations Program!\n");

    return 0;
}