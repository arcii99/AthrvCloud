//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int a[][COLS], int b[][COLS], int c[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            c[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void addMatrix(int a[][COLS], int b[][COLS], int c[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    int matrixA[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrixB[ROWS][COLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int product[ROWS][COLS];
    int sum[ROWS][COLS];

    printf("Matrix A:\n");
    printMatrix(matrixA, ROWS);

    printf("Matrix B:\n");
    printMatrix(matrixB, ROWS);

    multiplyMatrix(matrixA, matrixB, product);

    printf("A * B:\n");
    printMatrix(product, ROWS);

    addMatrix(matrixA, matrixB, sum);

    printf("A + B:\n");
    printMatrix(sum, ROWS);

    return 0;
}