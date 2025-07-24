//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int i, j, k;

    printf("Matrix A:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Matrix Multiplication
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix C (Multiplication of A and B):\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Matrix Addition
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatrix C (Addition of A and B):\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}