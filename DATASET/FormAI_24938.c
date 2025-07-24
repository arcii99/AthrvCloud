//FormAI DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>

void printMatrix(int matrix[][3], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[][3], int matrix2[][3], int result[][3], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[][3], int matrix2[][3], int result[][3], int rows1, int cols1, int rows2, int cols2) {
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];

    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);

    addMatrix(matrix1, matrix2, result, 3, 3);
    printf("\nMatrix Addition:\n");
    printMatrix(result, 3, 3);

    multiplyMatrix(matrix1, matrix2, result, 3, 3, 3, 3);
    printf("\nMatrix Multiplication:\n");
    printMatrix(result, 3, 3);

    return 0;
}