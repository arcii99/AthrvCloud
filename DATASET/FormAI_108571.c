//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print the pixel art matrix
void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to shift the rows of the matrix to the right
void shift_rows_right(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int temp = matrix[i][COLS-1];
        for (int j = COLS-1; j > 0; j--) {
            matrix[i][j] = matrix[i][j-1];
        }
        matrix[i][0] = temp;
    }
}

// Function to shift the columns of the matrix down
void shift_cols_down(int matrix[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        int temp = matrix[ROWS-1][j];
        for (int i = ROWS-1; i > 0; i--) {
            matrix[i][j] = matrix[i-1][j];
        }
        matrix[0][j] = temp;
    }
}

// Function to generate a random pixel art matrix
void generate_matrix(int matrix[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

int main() {
    int matrix[ROWS][COLS];
    generate_matrix(matrix);
    printf("Pixel Art Matrix:\n");
    print_matrix(matrix);

    printf("\n");

    printf("Shifting Rows Right:\n");
    shift_rows_right(matrix);
    print_matrix(matrix);

    printf("\n");

    printf("Shifting Columns Down:\n");
    shift_cols_down(matrix);
    print_matrix(matrix);

    return 0;
}