//FormAI DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

//function prototypes
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]);
int scalarMultiply(int rows, int cols, int matrix[rows][cols], int scalar, int result[rows][cols]);
int determinant(int n, int matrix[n][n]);

int main() {
    int rows, cols;
    printf("Enter number of rows and columns:\n");
    scanf("%d%d", &rows, &cols);

    //allocate memory for matrices
    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];

    //initialize matrices
    printf("Enter matrix1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter matrix2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix1:\n");
    printMatrix(rows, cols, matrix1);
    printf("\nMatrix2:\n");
    printMatrix(rows, cols, matrix2);

    //add matrices
    addMatrices(rows, cols, matrix1, matrix2, result);
    printf("\nMatrix1 + Matrix2:\n");
    printMatrix(rows, cols, result);

    //scalar multiplication
    int scalar;
    printf("\nEnter a scalar value: ");
    scanf("%d", &scalar);
    scalarMultiply(rows, cols, matrix1, scalar, result);
    printf("\n%d * Matrix1:\n", scalar);
    printMatrix(rows, cols, result);

    //determinant
    if (rows == cols) {
        int d = determinant(rows, matrix1);
        printf("\nDeterminant of Matrix1: %d\n", d);
    } else {
        printf("\nCannot calculate determinant as matrix is not square\n");
    }

    return 0;
}

//function to print matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//function to multiply matrix by scalar
int scalarMultiply(int rows, int cols, int matrix[rows][cols], int scalar, int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = scalar * matrix[i][j];
        }
    }
    return 0;
}

//function to calculate determinant of square matrix
int determinant(int n, int matrix[n][n]) {
    int det = 0;
    if (n == 1) {
        det = matrix[0][0];
    } else if (n == 2) {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        for (int i = 0; i < n; i++) {
            int temp[n - 1][n - 1];
            for (int j = 0; j < n - 1; j++) {
                for (int k = 0; k < n - 1; k++) {
                    if (k < i) {
                        temp[j][k] = matrix[j + 1][k];
                    } else {
                        temp[j][k] = matrix[j + 1][k + 1];
                    }
                }
            }
            det += (matrix[0][i] * determinant(n - 1, temp) * ((i % 2 == 0) ? 1 : -1));
        }
    }
    return det;
}