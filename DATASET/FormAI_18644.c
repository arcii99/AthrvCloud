//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

int main() {

    int i,j;
    int matrixA[3][3] = { {1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9} };

    int matrixB[3][3] = { {10, 11, 12},
                          {13, 14, 15},
                          {16, 17, 18} };

    int sumMatrix[3][3];

    printf("Matrix A:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("Sum of Matrix A and Matrix B:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", sumMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}