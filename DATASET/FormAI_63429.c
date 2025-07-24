//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>

// Function to print a matrix
void printMatrix(int matrix[][10], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Matrix declaration and initialization
    int matrix1[10][10] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[10][10] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[10][10] = {0};

    // Printing the original matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // Adding the matrices
    printf("\nAddition of the matrices:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result, 3, 3);

    // Multiplying the matrices
    printf("\nMultiplication of the matrices:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result, 3, 3);

    // Transposing the matrix
    printf("\nTranspose of the matrix:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = matrix1[j][i];
        }
    }
    printMatrix(result, 3, 3);

    return 0;
}