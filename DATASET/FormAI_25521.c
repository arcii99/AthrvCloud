//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* Function to print a matrix. */
void printMatrix(int** matrix, int rows, int cols) {
    int i, j;
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    /* Dynamically allocate memory for the matrix. */
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    /* Fill the matrix with user input. */
    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Print the matrix. */
    printMatrix(matrix, rows, cols);

    /* Find the sum of all elements in the matrix. */
    int sum = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    printf("The sum of all elements in the matrix is %d.\n", sum);

    /* Find the transpose of the matrix. */
    int** transpose = (int**)malloc(cols * sizeof(int*));
    for (i = 0; i < cols; i++) {
        transpose[i] = (int*)malloc(rows * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    printMatrix(transpose, cols, rows);

    /* Find the product of two matrices. */
    int k, product;
    int** matrix2 = (int**)malloc(cols * sizeof(int*));
    for (i = 0; i < cols; i++) {
        matrix2[i] = (int*)malloc(rows * sizeof(int));
    }
    printf("Enter the second matrix elements:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    int** productMatrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        productMatrix[i] = (int*)malloc(rows * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            product = 0;
            for (k = 0; k < cols; k++) {
                product += matrix[i][k] * matrix2[k][j];
            }
            productMatrix[i][j] = product;
        }
    }
    printMatrix(productMatrix, rows, rows);

    /* Free the memory allocated for the matrices. */
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
        free(transpose[i]);
        free(productMatrix[i]);
    }
    for (i = 0; i < cols; i++) {
        free(matrix2[i]);
    }
    free(matrix);
    free(transpose);
    free(productMatrix);
    free(matrix2);

    return 0;
}