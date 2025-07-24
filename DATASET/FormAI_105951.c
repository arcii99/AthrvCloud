//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>

#define ROWS 3
#define COLS 3

/* Function to print a matrix */
void print_matrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

/* Function to add two matrices */
void add_matrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

/* Function to transpose a matrix */
void transpose_matrix(int mat[ROWS][COLS], int transposed[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

/* Function to multiply two matrices */
void multiply_matrices(int mat1[ROWS][COLS], int mat2[COLS][ROWS], int result[ROWS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            int sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int mat1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int added[ROWS][COLS];
    int transposed[COLS][ROWS];
    int multiplied[ROWS][ROWS];

    printf("Matrix 1:\n");
    print_matrix(mat1);

    printf("\nMatrix 2:\n");
    print_matrix(mat2);

    add_matrices(mat1, mat2, added);
    printf("\nAdded matrix:\n");
    print_matrix(added);

    transpose_matrix(mat1, transposed);
    printf("\nTransposed matrix:\n");
    print_matrix(transposed);

    multiply_matrices(mat1, transposed, multiplied);
    printf("\nMultiplied matrix:\n");
    print_matrix(multiplied);

    return 0;
}