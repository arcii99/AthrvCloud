//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to print the matrix
void printMatrix(int mat[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subMatrix(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void mulMatrix(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = 0;
            for(int k=0; k<ROWS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[ROWS][COLS] = { {1, 1, 1},
                             {2, 2, 2},
                             {3, 3, 3} };
                             
    int mat2[ROWS][COLS] = { {4, 4, 4},
                             {5, 5, 5},
                             {6, 6, 6} };
                             
    int res[ROWS][COLS];
    
    // Add matrices
    printf("Addition of matrices:\n");
    addMatrix(mat1, mat2, res);
    printMatrix(res);
    
    // Subtract matrices
    printf("\nSubtraction of matrices:\n");
    subMatrix(mat1, mat2, res);
    printMatrix(res);
    
    // Multiply matrices
    printf("\nMultiplication of matrices:\n");
    mulMatrix(mat1, mat2, res);
    printMatrix(res);
    
    return 0;
}