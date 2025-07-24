//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

/* this function takes two matrices and performs matrix multiplication */
void matrix_multiplication(int matrix_one[3][3], int matrix_two[3][3], int result_matrix[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result_matrix[i][j] = 0;
            for (k=0; k<3; ++k) {
                result_matrix[i][j] += matrix_one[i][k] * matrix_two[k][j];
            }
        }
    }
}

/* this function takes a matrix and prints its contents */
void print_matrix(int matrix[3][3]) {
    int i, j;
    printf("Matrix contents:\n");
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix_one[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_two[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int result_matrix[3][3];

    printf("Matrix One:\n");
    print_matrix(matrix_one);
    printf("\n");

    printf("Matrix Two:\n");
    print_matrix(matrix_two);
    printf("\n");

    printf("Multiplying the matrices...\n");
    matrix_multiplication(matrix_one, matrix_two, result_matrix);
    printf("Result Matrix:\n");
    print_matrix(result_matrix);

    return 0;
}