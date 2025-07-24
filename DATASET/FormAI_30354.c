//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

// Function to print the matrix in a easy-to-read format
void printMatrix(int matrix[][3], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the exciting world of matrix operations in C!\n");

    // Creating a matrix of size 3x3
    int matrix1[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

    // Creating another matrix of size 3x3 to perform operations
    int matrix2[3][3] = {{10, 11, 12},
                         {13, 14, 15},
                         {16, 17, 18}};

    // Printing the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("\n");

    printf("Matrix 2:\n");
    printMatrix(matrix2, 3, 3);
    printf("\n");

    // Adding the two matrices and storing the result in a new matrix
    int resultMatrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Printing the result matrix
    printf("Result Matrix after addition:\n");
    printMatrix(resultMatrix, 3, 3);
    printf("\n");

    // Transposing the first matrix
    int transposeMatrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposeMatrix[i][j] = matrix1[j][i];
        }
    }

    // Printing the transpose matrix
    printf("Transpose of Matrix 1:\n");
    printMatrix(transposeMatrix, 3, 3);
    printf("\n");

    printf("Awesome! You have just performed two exciting operations on matrices in C!\n");

    return 0;
}