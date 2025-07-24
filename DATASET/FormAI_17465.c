//FormAI DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

// Function to display the matrix
void display(int matrix[ROWS][COLUMNS]) {
    printf("Matrix:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void add(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], int result[ROWS][COLUMNS]) {
    printf("Addition Result:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to multiply two matrices
void multiply(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], int result[ROWS][COLUMNS]) {
    int sum = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            for(int k=0; k<COLUMNS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
    printf("Multiplication Result:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to transpose a matrix
void transpose(int matrix[ROWS][COLUMNS], int result[COLUMNS][ROWS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    printf("Transpose Result:\n");
    for(int i=0; i<COLUMNS; i++) {
        for(int j=0; j<ROWS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int matrix1[ROWS][COLUMNS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[ROWS][COLUMNS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int result[ROWS][COLUMNS];
    int transposeResult[COLUMNS][ROWS];

    display(matrix1);
    display(matrix2);

    add(matrix1, matrix2, result);

    multiply(matrix1, matrix2, result);

    transpose(matrix1, transposeResult);

    return 0;
}