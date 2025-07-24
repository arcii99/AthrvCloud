//FormAI DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>

// Function to print the matrix
void printMatrix(int matrix[][3], int rows, int columns) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int matrix1[][3], int matrix2[][3], int result[][3], int rows, int columns) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[][3], int matrix2[][3], int result[][3], int rows1, int columns1, int columns2) {
    int i, j, k;
    for(i=0; i<rows1; i++) {
        for(j=0; j<columns2; j++) {
            result[i][j] = 0;
            for(k=0; k<columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Driver function
int main() {
    int matrix1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int result1[3][3];
    int result2[3][3];

    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);

    printf("\nMatrix 1 + Matrix 2:\n");
    addMatrix(matrix1, matrix2, result1, 3, 3);
    printMatrix(result1, 3, 3);

    printf("\nMatrix 1 * Matrix 2:\n");
    multiplyMatrix(matrix1, matrix2, result2, 3, 3, 3);
    printMatrix(result2, 3, 3);

    return 0;
}