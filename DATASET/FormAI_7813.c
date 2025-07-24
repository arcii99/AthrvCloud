//FormAI DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>

#define ROW_SIZE 3
#define COL_SIZE 3

// Function to print matrix
void printMatrix(int matrix[ROW_SIZE][COL_SIZE]) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int matrix1[ROW_SIZE][COL_SIZE], int matrix2[ROW_SIZE][COL_SIZE], int resultMatrix[ROW_SIZE][COL_SIZE]) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[ROW_SIZE][COL_SIZE], int matrix2[ROW_SIZE][COL_SIZE], int resultMatrix[ROW_SIZE][COL_SIZE]) {
    int i, j, k;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            resultMatrix[i][j] = 0;
            for (k = 0; k < ROW_SIZE; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROW_SIZE][COL_SIZE] = {{2, 4, 6}, {1, 3, 5}, {7, 8, 9}};
    int matrix2[ROW_SIZE][COL_SIZE] = {{1, 3, 5}, {2, 4, 6}, {8, 7, 9}};
    int sumResult[ROW_SIZE][COL_SIZE];
    int productResult[ROW_SIZE][COL_SIZE];

    // Find the sum of two matrices
    addMatrix(matrix1, matrix2, sumResult);
    printf("\nSum of two matrices:\n");
    printMatrix(sumResult);

    // Find the product of two matrices
    multiplyMatrix(matrix1, matrix2, productResult);
    printf("\nProduct of two matrices:\n");
    printMatrix(productResult);

    return 0;
}