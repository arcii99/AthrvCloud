//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>

#define ROWS 3
#define COLS 3

// function to print a matrix
void printMatrix(int mat[][COLS]) {
    printf("Matrix: \n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[ROWS][COLS] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    int mat2[ROWS][COLS] = {{9, 8, 7},
                            {6, 5, 4},
                            {3, 2, 1}};

    int result[ROWS][COLS];

    printf("Matrix 1:\n");
    printMatrix(mat1);

    printf("Matrix 2:\n");
    printMatrix(mat2);

    // addition of two matrices
    printf("Addition of matrices:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printMatrix(result);

    // subtraction of two matrices
    printf("Subtraction of matrices:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printMatrix(result);

    // multiplication of two matrices
    printf("Multiplication of matrices:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = 0;
            for(int k=0; k<ROWS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printMatrix(result);

    return 0;
}