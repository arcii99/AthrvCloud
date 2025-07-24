//FormAI DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>

int main() {
    int n, m; // number of rows and columns of matrix
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &n);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &m);

    int matrix[n][m]; // initialize matrix with the entered dimensions

    // get elements of matrix from user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // calculate the sum of all elements in matrix
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    printf("The sum of all elements in the matrix is: %d\n", sum);

    // calculate the transpose of matrix
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    // calculate the product of matrix with a scalar
    int scalar;
    printf("Enter a scalar to multiply with the matrix: ");
    scanf("%d", &scalar);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] *= scalar;
        }
    }
    printf("The matrix after multiplying with scalar is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}