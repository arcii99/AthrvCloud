//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>

// function to display the matrix
void display_matrix(int matrix[][3], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void add_matrices(int matrix1[][3], int matrix2[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int sum[3][3];

    printf("Original matrices:\n");
    display_matrix(matrix1, 3, 3);
    display_matrix(matrix2, 3, 3);

    add_matrices(matrix1, matrix2, sum, 3, 3);

    printf("\nResultant matrix after addition:\n");
    display_matrix(sum, 3, 3);

    return 0;
}