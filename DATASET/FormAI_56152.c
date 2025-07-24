//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

int main()
{
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int i, j, k;
    int sum_matrix[3][3], product_matrix[3][3];

    // Adding two matrices
    printf("The sum of the matrices is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", sum_matrix[i][j]);
        }
        printf("\n");
    }

    // Multiplying two matrices
    printf("The product of the matrices is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            product_matrix[i][j] = 0;
            for (k = 0; k < 3; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", product_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}