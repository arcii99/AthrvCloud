//FormAI DATASET v1.0 Category: Matrix operations ; Style: bold
#include <stdio.h>

#define ROWS 3
#define COLS 3

void print_matrix(int matrix[ROWS][COLS]) {
    printf("[");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d", matrix[i][j]);
            if(j < COLS - 1) {
                printf(", ");
            }
        }
        if(i < ROWS - 1) {
            printf("\n");
        }
    }
    printf("]\n");
}

void matrix_add(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_subtract(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrix_multiply(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int sum = 0;
            for(int k = 0; k < COLS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROWS][COLS];
    
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    
    printf("\nMatrix 2:\n");
    print_matrix(matrix2);
    
    printf("\nAddition:\n");
    matrix_add(matrix1, matrix2, result);
    print_matrix(result);
    
    printf("\nSubtraction:\n");
    matrix_subtract(matrix1, matrix2, result);
    print_matrix(result);
    
    printf("\nMultiplication:\n");
    matrix_multiply(matrix1, matrix2, result);
    print_matrix(result);
    
    return 0;
}