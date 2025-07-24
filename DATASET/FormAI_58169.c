//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#define ROWS 3
#define COLS 3

void printMatrix(int matrix[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            result[i][j] = 0;
            for (k = 0; k < COLS; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];
    
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\n");
    
    printf("Matrix 2:\n");
    printMatrix(matrix2);
    printf("\n");
    
    addMatrix(matrix1, matrix2, result);
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(result);
    printf("\n");
    
    subtractMatrix(matrix1, matrix2, result);
    printf("Matrix 1 - Matrix 2:\n");
    printMatrix(result);
    printf("\n");
    
    multiplyMatrix(matrix1, matrix2, result);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(result);
    printf("\n");

    return 0;
}