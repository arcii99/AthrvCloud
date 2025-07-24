//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>

// define the number of rows and columns for the matrix
#define ROWS 3
#define COLS 3

// function to display the matrix
void display(int matrix[ROWS][COLS]) {
    printf("Matrix:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void add(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Result of addition:\n");
    display(result);
}

// function to subtract two matrices
void subtract(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("Result of subtraction:\n");
    display(result);
}

// function to multiply two matrices
void multiply(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int result[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = 0;
            for(int k=0; k<COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("Result of multiplication:\n");
    display(result);
}

int main() {
    // define two matrices for operations
    int matrix1[ROWS][COLS] = { {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9} };
                                
    int matrix2[ROWS][COLS] = { {9, 8, 7},
                                {6, 5, 4},
                                {3, 2, 1} };
                                
    // display the matrices
    display(matrix1);
    printf("\n");
    display(matrix2);
    printf("\n");
    
    // perform operations on the matrices
    add(matrix1, matrix2);
    printf("\n");
    subtract(matrix1, matrix2);
    printf("\n");
    multiply(matrix1, matrix2);
    
    return 0;
}