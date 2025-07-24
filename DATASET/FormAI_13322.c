//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplyMatrix(int matrixA[][COLS], int matrixB[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void addMatrix(int matrixA[][COLS], int matrixB[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrix(int matrixA[][COLS], int matrixB[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

int main() {
    int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrixC[ROWS][COLS];
    int matrixD[ROWS][COLS];
    int matrixE[ROWS][COLS];
    
    printf("Matrix A:\n");
    printMatrix(matrixA);
    
    printf("Matrix B:\n");
    printMatrix(matrixB);
    
    // Matrix multiplication
    multiplyMatrix(matrixA, matrixB, matrixC);
    printf("Matrix A * Matrix B:\n");
    printMatrix(matrixC);
    
    // Matrix addition
    addMatrix(matrixA, matrixB, matrixD);
    printf("Matrix A + Matrix B:\n");
    printMatrix(matrixD);
    
    // Matrix subtraction
    subtractMatrix(matrixA, matrixB, matrixE);
    printf("Matrix A - Matrix B:\n");
    printMatrix(matrixE);
    
    return 0;
}