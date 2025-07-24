//FormAI DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Matrix structure definition
typedef struct {
    int data[ROWS][COLS];
    int rows;
    int cols;
} Matrix;

// Function to print a matrix
void printMatrix(Matrix matrix) {
    printf("Matrix:\n");
    for(int i = 0; i < matrix.rows; ++i) {
        for(int j = 0; j < matrix.cols; ++j) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix addMatrices(Matrix matrix1, Matrix matrix2){
    Matrix result = {.rows = matrix1.rows, .cols = matrix1.cols};
    for(int i = 0; i < result.rows; ++i) {
        for(int j = 0; j < result.cols; ++j) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix matrix1, Matrix matrix2) {
    Matrix result = {.rows = matrix1.rows, .cols = matrix2.cols};
    for(int i = 0; i < result.rows; ++i) {
        for(int j = 0; j < result.cols; ++j) {
            result.data[i][j] = 0;
            for(int k = 0; k < matrix1.cols; ++k) {
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Initialize two matrices
    Matrix matrix1 = {.rows = ROWS, .cols = COLS, .data = {{1,2,3},{4,5,6},{7,8,9}}};
    Matrix matrix2 = {.rows = ROWS, .cols = COLS, .data = {{9,8,7},{6,5,4},{3,2,1}}};
    
    // Print the matrices
    printMatrix(matrix1);
    printf("\n");
    printMatrix(matrix2);
    
    // Add and print the result
    Matrix addResult = addMatrices(matrix1, matrix2);
    printf("\n");
    printMatrix(addResult);
    
    // Multiply and print the result
    Matrix multResult = multiplyMatrices(matrix1, matrix2);
    printf("\n");
    printMatrix(multResult);
    
    return 0;
}