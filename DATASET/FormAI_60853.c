//FormAI DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>

#define ROW 3
#define COL 3

// Function to print matrix
void printMatrix(int matrix[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int m1[ROW][COL], int m2[ROW][COL], int add[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            add[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to subtract two matrices
void subMatrix(int m1[ROW][COL], int m2[ROW][COL], int sub[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            sub[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

// Function to multiply two matrices
void mulMatrix(int m1[ROW][COL], int m2[ROW][COL], int mul[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < COL; k++) {
                mul[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    // Declare matrices
    int matrix1[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROW][COL] = {{5, 4, 3}, {2, 1, 0}, {-1, -2, -3}};
    int addMatrixResult[ROW][COL];
    int subMatrixResult[ROW][COL];
    int mulMatrixResult[ROW][COL];

    // Add two matrices
    addMatrix(matrix1, matrix2, addMatrixResult);
    printf("Addition of two matrices: \n");
    printMatrix(addMatrixResult);

    // Subtract two matrices
    subMatrix(matrix1, matrix2, subMatrixResult);
    printf("\nSubtraction of two matrices: \n");
    printMatrix(subMatrixResult);

    // Multiply two matrices
    mulMatrix(matrix1, matrix2, mulMatrixResult);
    printf("\nMultiplication of two matrices: \n");
    printMatrix(mulMatrixResult);

    return 0;
}