//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>

#define ROWS 3
#define COLS 3

void print_matrix(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int arr1[][COLS], int arr2[][COLS], int result[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void multiply_matrices(int arr1[][COLS], int arr2[][COLS], int result[][COLS], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    int m1[ROWS][COLS] = {{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    int m2[ROWS][COLS] = {{9, 8, 7},
                          {6, 5, 4},
                          {3, 2, 1}};
    int sum[ROWS][COLS], product[ROWS][COLS];
    
    printf("Matrix 1:\n");
    print_matrix(m1, ROWS);
    printf("\nMatrix 2:\n");
    print_matrix(m2, ROWS);
    
    add_matrices(m1, m2, sum, ROWS);
    printf("\nSum of matrices:\n");
    print_matrix(sum, ROWS);
    
    multiply_matrices(m1, m2, product, ROWS, COLS, ROWS);
    printf("\nProduct of matrices:\n");
    print_matrix(product, ROWS);
    
    return 0;
}