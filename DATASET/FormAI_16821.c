//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>

void printMatrix(int matrix[][3], int rows, int columns);
void addMatrices(int matrix1[][3], int matrix2[][3], int result[][3], int rows, int columns);
void multiplyMatrices(int matrix1[][3], int matrix2[][3], int result[][3], int rows1, int columns1, int rows2, int columns2);
void transposeMatrix(int matrix[][3], int result[][3], int rows, int columns);
void scalarMultiply(int matrix[][3], int scalar, int result[][3], int rows, int columns);

int main() {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int result[3][3];
    int scalar = 2;
    
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("Matrix 2:\n");
    printMatrix(matrix2, 3, 3);
    
    printf("Matrix 1 + Matrix 2:\n");
    addMatrices(matrix1, matrix2, result, 3, 3);
    printMatrix(result, 3, 3);
    
    printf("Matrix 1 * Matrix 2:\n");
    multiplyMatrices(matrix1, matrix2, result, 3, 3, 3, 3);
    printMatrix(result, 3, 3);
    
    printf("Transpose of Matrix 1:\n");
    transposeMatrix(matrix1, result, 3, 3);
    printMatrix(result, 3, 3);
    
    printf("Matrix 1 * 2:\n");
    scalarMultiply(matrix1, scalar, result, 3, 3);
    printMatrix(result, 3, 3);
    
    return 0;
}

void printMatrix(int matrix[][3], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[][3], int matrix2[][3], int result[][3], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][3], int matrix2[][3], int result[][3], int rows1, int columns1, int rows2, int columns2) {
    if(columns1 != rows2) {
        printf("Error: invalid matrix dimensions");
        return;
    }
    
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < columns2; j++) {
            int sum = 0;
            for(int k = 0; k < columns1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void transposeMatrix(int matrix[][3], int result[][3], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void scalarMultiply(int matrix[][3], int scalar, int result[][3], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}