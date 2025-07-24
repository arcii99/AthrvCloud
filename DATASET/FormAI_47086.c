//FormAI DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>

#define ROWS 3
#define COLS 3

int matrix[ROWS][COLS];

void initialize_matrix() {
    /* Initialize the matrix with random values */
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix() {
    /* Print the contents of the matrix */
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix() {
    /* Transpose the matrix */
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = i+1; j < COLS; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void multiply_matrices(int m1[ROWS][COLS], int m2[ROWS][COLS], int result[ROWS][COLS]) {
    /* Multiply two matrices */
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (k = 0; k < ROWS; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    /* Driver code */
    srand(time(NULL));
    printf("Original matrix:\n");
    initialize_matrix();
    print_matrix();
    
    printf("\nTranspose of the matrix:\n");
    transpose_matrix();
    print_matrix();
    
    printf("\nMultiplication of the matrix with itself:\n");
    int result[ROWS][COLS];
    multiply_matrices(matrix, matrix, result);
    print_matrix();
    
    return 0;
}