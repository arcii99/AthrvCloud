//FormAI DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>

// define a constant
#define ROWS 3
#define COLS 3

// Function to display a matrix
void displayMatrix(int mat[ROWS][COLS]) {
    printf("The Matrix:\n");
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            int sum = 0;
            for(int k=0;k<ROWS;k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    // Initialize 2 matrices
    int matrix1[ROWS][COLS] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[ROWS][COLS] = {{2,3,4}, {5,6,7}, {8,9,10}};

    // Display the matrices
    displayMatrix(matrix1);
    displayMatrix(matrix2);

    // Initialize a result matrix for multiplying the two matrices
    int resultMatrix[ROWS][COLS];

    // Multiply the two matrices and display the result
    multiplyMatrices(matrix1, matrix2, resultMatrix);
    displayMatrix(resultMatrix);

    return 0;
}