//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void scalarMultiplyMatrix(int matrix[ROWS][COLS], int scalarValue, int resultMatrix[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrix[i][j] * scalarValue;
        }
    }
}

void transposeMatrix(int matrix[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            resultMatrix[j][i] = matrix[i][j];
        }
    }
}

int main() {

    int matrixA[ROWS][COLS] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
                               
    int matrixB[ROWS][COLS] = {{9, 8, 7},
                               {6, 5, 4},
                               {3, 2, 1}};
                               
    int resultMatrix[ROWS][COLS];
                               
    printf("Matrix A:\n");
    printMatrix(matrixA);
    
    printf("\n\nMatrix B:\n");
    printMatrix(matrixB);
    
    printf("\n\nAdding Matrix A and B:\n");
    addMatrix(matrixA, matrixB, resultMatrix);
    printMatrix(resultMatrix);
    
    printf("\n\nMultiplying Matrix A by scalar 2:\n");
    scalarMultiplyMatrix(matrixA, 2, resultMatrix);
    printMatrix(resultMatrix);
    
    printf("\n\nTransposing Matrix A:\n");
    transposeMatrix(matrixA, resultMatrix);
    printMatrix(resultMatrix);

    return 0;
}