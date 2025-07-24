//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

// Define the size of matrix
#define ROW 3
#define COL 3

// Function to print matrix
void printMatrix(int mat[][COL]) {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[][COL], int mat2[][COL], int res[][COL]) {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[][COL], int mat2[][COL], int res[][COL]) {
    int i, j, k;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            res[i][j] = 0;
            for(k = 0; k < COL; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[ROW][COL] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int res[ROW][COL];
    
    printf("Matrix 1:\n");
    printMatrix(mat1);
    
    printf("Matrix 2:\n");
    printMatrix(mat2);
    
    // Add two matrices
    addMatrices(mat1, mat2, res);
    printf("Result after adding two matrices:\n");
    printMatrix(res);
    
    // Multiply two matrices
    multiplyMatrices(mat1, mat2, res);
    printf("Result after multiplying two matrices:\n");
    printMatrix(res);
    
    return 0;
}