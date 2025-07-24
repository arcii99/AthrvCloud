//FormAI DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include <stdio.h>

#define ROWS 3
#define COLS 3

void display(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7},
                               {6, 5, 4},
                               {3, 2, 1}};
    int result[ROWS][COLS] = {0};

    printf("Matrix 1:\n");
    display(matrix1);

    printf("Matrix 2:\n");
    display(matrix2);

    printf("Matrix 1 + Matrix 2:\n");
    add(matrix1, matrix2, result);
    display(result);

    printf("Matrix 1 - Matrix 2:\n");
    subtract(matrix1, matrix2, result);
    display(result);

    printf("Matrix 1 * Matrix 2:\n");
    multiply(matrix1, matrix2, result);
    display(result);

    return 0;
}