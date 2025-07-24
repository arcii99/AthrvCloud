//FormAI DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

void printMatrix(int matrix[ROWS][COLUMNS]) { // function to print the matrix
    printf("\nMatrix:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void transpose(int matrix[ROWS][COLUMNS]) { // function to transpose the matrix
    int temp;
    for(int i = 0; i < ROWS; i++) {
        for(int j = i+1; j < COLUMNS; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void multiply(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS]) { // function to multiply two matrices
    int resultMatrix[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < COLUMNS; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("\nResult of matrix multiplication:\n");
    printMatrix(resultMatrix);
}

void add(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS]) { // function to add two matrices
    int resultMatrix[ROWS][COLUMNS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++)
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    printf("\nResult of matrix addition:\n");
    printMatrix(resultMatrix);
}

int main() {
    int matrix1[ROWS][COLUMNS] = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
                                  
    int matrix2[ROWS][COLUMNS] = {{9, 8, 7},
                                  {6, 5, 4},
                                  {3, 2, 1}};
    
    printf("Matrix Operations!\n");
    
    printMatrix(matrix1);
    transpose(matrix1);
    printf("\nTransposing matrix...\n");
    printMatrix(matrix1);
    
    printMatrix(matrix2);
    transpose(matrix2);
    printf("\nTransposing matrix...\n");
    printMatrix(matrix2);
    
    add(matrix1, matrix2);
    
    multiply(matrix1, matrix2);
    
    return 0;
}