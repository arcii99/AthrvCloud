//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int matrix[ROWS][COLS];

void initialize_matrix(int matrix[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int matrix[ROWS][COLS]) {
    printf("MATRIX: \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiply_matrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    initialize_matrix(matrix);
    print_matrix(matrix);

    int matrix2[ROWS][COLS] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int result[ROWS][COLS];
    add_matrix(matrix, matrix2, result);
    printf("\nADDED MATRIX:\n");
    print_matrix(result);

    multiply_matrix(matrix, matrix2, result);
    printf("\nMULTIPLIED MATRIX:\n");
    print_matrix(result);

    return 0;
}