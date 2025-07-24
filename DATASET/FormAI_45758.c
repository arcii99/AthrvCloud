//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>

#define ROWS 3
#define COLS 3

// This function prints the given matrix
void printMatrix(int matrix[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example matrices
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Printing the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, ROWS, COLS);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, ROWS, COLS);

    // Transposing matrix1
    printf("\nTransposing Matrix 1...\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = i; j < COLS; j++) {
            int temp = matrix1[i][j];
            matrix1[i][j] = matrix1[j][i];
            matrix1[j][i] = temp;
        }
    }

    // Printing the transposed matrix1
    printf("\nMatrix 1 Transposed:\n");
    printMatrix(matrix1, ROWS, COLS);

    // Adding matrix1 and matrix2
    printf("\nAdding Matrix 1 and Matrix 2...\n");
    int sumMatrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Printing the sum matrix
    printf("\nSum Matrix:\n");
    printMatrix(sumMatrix, ROWS, COLS);

    // Multiplying matrix1 and matrix2
    printf("\nMultiplying Matrix 1 and Matrix 2...\n");
    int productMatrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            productMatrix[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Printing the product matrix
    printf("\nProduct Matrix:\n");
    printMatrix(productMatrix, ROWS, COLS);

    return 0;
}