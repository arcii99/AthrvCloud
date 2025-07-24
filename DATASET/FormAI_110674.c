//FormAI DATASET v1.0 Category: Matrix operations ; Style: configurable
#include<stdio.h>

#define ROWS 3
#define COLS 3

/* Function to display the matrix */
void display(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to multiply two matrices */
void multiply(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (k = 0; k < ROWS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

/* Function to add two matrices */
void add(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matrix2[ROWS][COLS] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    int result[ROWS][COLS];

    // Display matrix1
    printf("Matrix 1:\n");
    display(matrix1);

    // Display matrix2
    printf("Matrix 2:\n");
    display(matrix2);

    // Matrix multiplication
    multiply(matrix1, matrix2, result);
    printf("Matrix multiplication result:\n");
    display(result);

    // Matrix addition
    add(matrix1, matrix2, result);
    printf("Matrix addition result:\n");
    display(result);

    return 0;
}