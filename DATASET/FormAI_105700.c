//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

void printMatrix(int matrix[][3], int size) {
    int i, j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[][3], int matrix2[][3], int result[][3], int size) {
    int i, j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void transposeMatrix(int matrix[][3], int result[][3], int size) {
    int i, j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[][3], int matrix2[][3], int result[][3], int size) {
    int i, j, k;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            result[i][j] = 0;
            for(k=0;k<size;k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];
    
    // Printing the original matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3);
    
    // Adding the matrices
    addMatrix(matrix1, matrix2, result, 3);
    printf("\nMatrix 1 + Matrix 2:\n");
    printMatrix(result, 3);
    
    // Transposing the matrices
    transposeMatrix(matrix1, result, 3);
    printf("\nTranspose of Matrix 1:\n");
    printMatrix(result, 3);
    transposeMatrix(matrix2, result, 3);
    printf("\nTranspose of Matrix 2:\n");
    printMatrix(result, 3);
    
    // Multiplying the matrices
    multiplyMatrix(matrix1, matrix2, result, 3);
    printf("\nMatrix 1 x Matrix 2:\n");
    printMatrix(result, 3);
    
    return 0;
}