//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]);
void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]);
void subtractMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]);
void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]);

int main() {

    int matrixA[ROWS][COLS] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    int matrixB[ROWS][COLS] = {{9, 8, 7},
                               {6, 5, 4},
                               {3, 2, 1}};

    printf("\nMatrix A:\n");
    printMatrix(matrixA);
    printf("\nMatrix B:\n");
    printMatrix(matrixB);

    printf("\nAdding A and B:\n");
    addMatrices(matrixA, matrixB);

    printf("\nSubtracting B from A:\n");
    subtractMatrices(matrixA, matrixB);

    printf("\nMultiplying A and B:\n");
    multiplyMatrices(matrixA, matrixB);

    return 0;
}

void printMatrix(int matrix[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    printMatrix(result);
}

void subtractMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    printMatrix(result);
}

void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for(int k = 0; k < COLS; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printMatrix(result);
}