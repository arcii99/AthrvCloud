//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define ROWS 3
#define COLS 3

void printMatrix(double complex matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2lf + %.2lfi\t", creal(matrix[i][j]), cimag(matrix[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(double complex matrix1[ROWS][COLS], double complex matrix2[ROWS][COLS], double complex result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(double complex matrix1[ROWS][COLS], double complex matrix2[ROWS][COLS], double complex result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(double complex matrix1[ROWS][COLS], double complex matrix2[ROWS][COLS], double complex result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][0] * matrix2[0][j] + matrix1[i][1] * matrix2[1][j] + matrix1[i][2] * matrix2[2][j];
        }
    }
}

int main() {
    double complex matrix1[ROWS][COLS] = {{1.0 + 2.0*I, 2.0 - 3.0*I, 3.5 - 4.5*I}, {4.5 + 5.5*I, 1.5 + 2.5*I, 1.0 - 1.5*I}, {0.5 - 0.5*I, 1.5 + 0.5*I, 2.0 - 1.0*I}};
    double complex matrix2[ROWS][COLS] = {{3.0 - 2.0*I, 4.0 + 3.0*I, 2.5 + 1.5*I}, {1.5 - 2.5*I, 2.5 - 1.5*I, 3.0 + 1.5*I}, {2.5 + 0.5*I, 0.5 - 1.5*I, 1.0 + 2.0*I}};
    double complex result[ROWS][COLS];

    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);

    printf("Adding matrices:\n");
    addMatrices(matrix1, matrix2, result);
    printMatrix(result);

    printf("Subtracting matrices:\n");
    subtractMatrices(matrix1, matrix2, result);
    printMatrix(result);

    printf("Multiplying matrices:\n");
    multiplyMatrices(matrix1, matrix2, result);
    printMatrix(result);

    return 0;
}