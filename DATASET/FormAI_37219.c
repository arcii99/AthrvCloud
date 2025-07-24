//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int get_matrix_input(int rows, int cols, int matrix[rows][cols]) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int rows, int cols, int matrix[rows][cols]) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result_matrix[rows][cols]) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result_matrix[rows][cols]) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply_matrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result_matrix[rows1][cols2]) {
    int i, j, k;
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            result_matrix[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    printf("Enter elements of first matrix:\n");
    get_matrix_input(rows1, cols1, matrix1);
    printf("First matrix:\n");
    display_matrix(rows1, cols1, matrix1);
    
    printf("\nEnter rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    while(cols1 != rows2) {
        printf("Error! Number of columns in first matrix not equal to number of rows in second.\n");
        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &rows2, &cols2);
    }
    int matrix2[rows2][cols2];
    printf("Enter elements of second matrix:\n");
    get_matrix_input(rows2, cols2, matrix2);
    printf("Second matrix:\n");
    display_matrix(rows2, cols2, matrix2);
    
    // Add matrices
    int result_matrix_add[rows1][cols1];
    add_matrices(rows1, cols1, matrix1, matrix2, result_matrix_add);
    printf("\nResult of matrix addition:\n");
    display_matrix(rows1, cols1, result_matrix_add);
    
    // Subtract matrices
    int result_matrix_sub[rows1][cols1];
    subtract_matrices(rows1, cols1, matrix1, matrix2, result_matrix_sub);
    printf("\nResult of matrix subtraction:\n");
    display_matrix(rows1, cols1, result_matrix_sub);
    
    // Multiply matrices
    int result_matrix_mul[rows1][cols2];
    multiply_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result_matrix_mul);
    printf("\nResult of matrix multiplication:\n");
    display_matrix(rows1, cols2, result_matrix_mul);
    
    return 0;
}