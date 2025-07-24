//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>

int main() {
    int matrix_1[3][3], matrix_2[3][3], result[3][3];

    // initialize the matrices with random values
    printf("Initializing matrix_1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix_1[i][j] = rand() % 10;
            printf("%d ", matrix_1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Initializing matrix_2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix_2[i][j] = rand() % 10;
            printf("%d ", matrix_2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Performing matrix addition:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Performing matrix multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;  // initialize the result matrix element to zero
            for (int k = 0; k < 3; k++) {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}