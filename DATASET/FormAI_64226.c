//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initialize_matrix(int matrix[][COLS]);
void display_matrix(int matrix[][COLS]);
void multiply_matrices(int matrix1[][COLS], int matrix2[][COLS]);

int main(void) {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    
    // seed random number generator
    srand(time(NULL));
    
    // initialize matrices with random numbers
    initialize_matrix(matrix1);
    initialize_matrix(matrix2);
    
    printf("Matrix 1: \n");
    display_matrix(matrix1);
    printf("\n Matrix 2: \n");
    display_matrix(matrix2);
    
    // multiply the two matrices
    multiply_matrices(matrix1, matrix2);
    
    return 0;
}

void initialize_matrix(int matrix[][COLS]) {
    // fill matrix with random numbers between 0 and 9
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void display_matrix(int matrix[][COLS]) {
    // print the matrix
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[][COLS], int matrix2[][COLS]) {
    int result_matrix[ROWS][COLS];
    
    // multiply the two matrices
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result_matrix[i][j] = 0;
            for(int k=0; k<ROWS; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // print the resulting matrix
    printf("\nResulting Matrix: \n");
    display_matrix(result_matrix);
}