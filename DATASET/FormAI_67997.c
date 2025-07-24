//FormAI DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix_size;
    printf("What is the size of your matrix?\n");
    scanf("%d", &matrix_size);

    int matrix1[matrix_size][matrix_size], matrix2[matrix_size][matrix_size], result[matrix_size][matrix_size];

    printf("\nPlease enter the first matrix:\n");
    for(int i=0; i<matrix_size; i++) {
        for(int j=0; j<matrix_size; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nPlease enter the second matrix:\n");
    for(int i=0; i<matrix_size; i++) {
        for(int j=0; j<matrix_size; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMultiplying the matrices...\n");

    for(int i=0; i<matrix_size; i++) {
        for(int j=0; j<matrix_size; j++) {
            int sum = 0;
            for(int k=0; k<matrix_size; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf("\nThe result of multiplying the matrices is:\n");
    for(int i=0; i<matrix_size; i++) {
        for(int j=0; j<matrix_size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}