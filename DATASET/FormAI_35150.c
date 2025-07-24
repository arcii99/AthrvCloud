//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include<stdio.h>
#define ROWS 3
#define COLS 3

void initMatrix(int matrix[][COLS], int rows, int cols) {
    printf("Initializing the Matrix...\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = i+j;
        }
    }
}

void printMatrix(int matrix[][COLS], int rows, int cols) {
    printf("Printing the Matrix...\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS], int rows, int cols) {
    printf("Performing Matrix Addition...\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS], int rows, int cols) {
    printf("Performing Matrix Subtraction...\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplication(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS], int rows, int cols) {
    printf("Performing Matrix Multiplication...\n");
    int sum = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            sum = 0;
            for(int k=0; k<rows; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int result[ROWS][COLS];

    initMatrix(matrix1, ROWS, COLS);
    printf("\n");
    printMatrix(matrix1, ROWS, COLS);
    printf("\n");

    initMatrix(matrix2, ROWS, COLS);
    printf("\n");
    printMatrix(matrix2, ROWS, COLS);
    printf("\n");

    matrixAddition(matrix1, matrix2, result, ROWS, COLS);
    printf("\n");
    printMatrix(result, ROWS, COLS);
    printf("\n");

    matrixSubtraction(matrix1, matrix2, result, ROWS, COLS);
    printf("\n");
    printMatrix(result, ROWS, COLS);
    printf("\n");

    matrixMultiplication(matrix1, matrix2, result, ROWS, COLS);
    printf("\n");
    printMatrix(result, ROWS, COLS);
    printf("\n");

    return 0;
}