//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to display the matrix
void displayMatrix(int**, int, int);

// Function to multiply the matrix
int** multiplyMatrix(int**, int**, int, int, int, int);

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows in matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns in matrix 1: ");
    scanf("%d", &cols1);

    // Allocate memory for matrix 1
    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*)malloc(cols1 * sizeof(int));
    }

    printf("Enter the elements of matrix 1: \n");

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows in matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in matrix 2: ");
    scanf("%d", &cols2);

    // Allocate memory for matrix 2
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*)malloc(cols2 * sizeof(int));
    }

    printf("Enter the elements of matrix 2: \n");

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Display the matrices
    printf("Matrix 1:\n");
    displayMatrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    displayMatrix(matrix2, rows2, cols2);

    // Multiply the matrices
    int** result = multiplyMatrix(matrix1, matrix2, rows1, cols1, rows2, cols2);

    // Display the result
    printf("Result:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** multiplyMatrix(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: cannot multiply matrices with incompatible dimensions\n");
        exit(0);
    }

    // Allocate memory for the result matrix
    int** result = (int**)malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        result[i] = (int*)malloc(cols2 * sizeof(int));
    }

    // Multiply the matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}