//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void transposeMatrix(int matrix[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[ROWS][COLS] = {{9,8,7}, {6,5,4}, {3,2,1}};
    
    printf("Matrix1:\n");
    printMatrix(matrix1);
    
    printf("Matrix2:\n");
    printMatrix(matrix2);
    
    // Add matrix1 and matrix2
    int result1[ROWS][COLS];
    addMatrix(matrix1, matrix2, result1);
    
    printf("Result of matrix addition:\n");
    printMatrix(result1);
    
    // Transpose matrix1
    int result2[ROWS][COLS];
    transposeMatrix(matrix1, result2);
    
    printf("Result of matrix transpose:\n");
    printMatrix(result2);
    
    // Multiply matrix1 and matrix2
    int result3[ROWS][COLS];
    multiplyMatrix(matrix1, matrix2, result3);
    
    printf("Result of matrix multiplication:\n");
    printMatrix(result3);
    
    return 0;
}