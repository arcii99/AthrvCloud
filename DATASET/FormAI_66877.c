//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>

// Function to print a matrix
void printMatrix(int matrix[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrix(int matrix1[3][3], int matrix2[3][3], int rows, int cols) {
    int result[3][3];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The sum of the two matrices is:\n");
    printMatrix(result, rows, cols);
}

// Function to subtract two matrices
void subtractMatrix(int matrix1[3][3], int matrix2[3][3], int rows, int cols) {
    int result[3][3];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("The difference of the two matrices is:\n");
    printMatrix(result, rows, cols);
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[3][3], int matrix2[3][3], int rows1, int cols1, int cols2) {
    int result[3][3];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("The product of the two matrices is:\n");
    printMatrix(result, rows1, cols2);
}

int main() {
    int matrix1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int rows1 = 3, cols1 = 3, rows2 = 3, cols2 = 3;

    printf("Welcome to my cheerful matrix operations program!\n");
    printf("Let's start by printing the two matrices:\n");
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    printf("Now, let's add the two matrices:\n");
    addMatrix(matrix1, matrix2, rows1, cols1);

    printf("Let's subtract the two matrices now:\n");
    subtractMatrix(matrix1, matrix2, rows1, cols1);

    printf("Finally, let's multiply the two matrices:\n");
    multiplyMatrix(matrix1, matrix2, rows1, cols1, cols2);

    printf("Thanks for using my cheerful matrix operations program!\n");
    return 0;
}