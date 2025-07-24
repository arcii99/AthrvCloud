//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

//function to generate a matrix
void generateMatrix(int matrix[10][10], int rows, int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            matrix[i][j] = rand() % 100; //generating a random number between 0-99
        }
    }
}

//function to print a matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrix(int matrix1[10][10], int matrix2[10][10], int rows, int cols) {
    int sumMatrix[10][10];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("\nAddition of two matrices is:\n");
    printMatrix(sumMatrix,rows,cols);
}

//function to multiply two matrices
void multiplyMatrix(int matrix1[10][10], int matrix2[10][10], int rows, int cols) {
    int multiplyMatrix[10][10];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            multiplyMatrix[i][j] = 0;
            for(int k=0;k<cols;k++) {
                multiplyMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("\nMultiplication of two matrices is:\n");
    printMatrix(multiplyMatrix,rows,cols);
}

int main() {
    int rows = 3, cols = 3;
    int matrix1[10][10], matrix2[10][10];

    printf("Generating Matrix 1...\n");
    generateMatrix(matrix1,rows,cols);
    printf("Matrix 1:\n");
    printMatrix(matrix1,rows,cols);

    printf("\nGenerating Matrix 2...\n");
    generateMatrix(matrix2,rows,cols);
    printf("Matrix 2:\n");
    printMatrix(matrix2,rows,cols);

    addMatrix(matrix1, matrix2, rows, cols);
    multiplyMatrix(matrix1, matrix2, rows, cols);

    return 0;
}