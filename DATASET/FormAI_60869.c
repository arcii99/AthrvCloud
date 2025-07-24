//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROW 3 //Number of Rows
#define COL 4 //Number of Columns

void printMatrix(int matrix[ROW][COL]);
void matrixMultiplication(int matrix1[ROW][COL], int matrix2[COL][ROW], int result[ROW][ROW]);

int main() {
    int matrix1[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int matrix2[COL][ROW] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int result[ROW][ROW];
    
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);
    
    matrixMultiplication(matrix1, matrix2, result);
    
    printf("\nResultant Matrix:\n");
    printMatrix(result);
    
    return 0;
}

void printMatrix(int matrix[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication(int matrix1[ROW][COL], int matrix2[COL][ROW], int result[ROW][ROW]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < ROW; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COL; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}