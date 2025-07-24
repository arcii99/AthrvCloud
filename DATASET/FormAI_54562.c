//FormAI DATASET v1.0 Category: Matrix operations ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

void read_matrix(int row, int col, int matrix[row][col]);
void print_matrix(int row, int col, int matrix[row][col]);
void add_matrices(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]);
void scalar_multiplication(int row, int col, int matrix[row][col], int scalar, int result[row][col]);
void matrix_multiplication(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int result[row1][col2]);
int determinant(int size, int matrix[size][size]);

int main()
{
    int choice, size, scalar, result_scalar;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &size);
    int matrix1[size][size], matrix2[size][size], result_matrix[size][size];
    
    //Reading Input Matrices
    printf("Enter elements of first matrix:\n");
    read_matrix(size, size, matrix1);
    printf("Enter elements of second matrix:\n");
    read_matrix(size, size, matrix2);
    
    //Printing Input Matrices
    printf("\nThe entered matrices are:\n");
    printf("First Matrix:\n");
    print_matrix(size, size, matrix1);
    printf("Second Matrix:\n");
    print_matrix(size, size, matrix2);
    
    //Scalar Multiplication
    printf("\nEnter scalar value for multiplication: ");
    scanf("%d", &scalar);
    scalar_multiplication(size, size, matrix1, scalar, result_matrix);
    printf("\nThe scalar multiplication of the first matrix with %d is:\n", scalar);
    print_matrix(size, size, result_matrix);
    
    //Addition of Two Matrices
    add_matrices(size, size, matrix1, matrix2, result_matrix);
    printf("\nThe addition of the two matrices is:\n");
    print_matrix(size, size, result_matrix);
    
    //Multiplication of Two Matrices
    int row1 = size, col1 = size, row2 = size, col2 = size;
    matrix_multiplication(row1, col1, matrix1, row2, col2, matrix2, result_matrix);
    printf("\nThe multiplication of the two matrices is:\n");
    print_matrix(row1, col2, result_matrix);
    
    //Determinant of a Square Matrix
    int det = determinant(size, matrix1);
    printf("\nThe determinant of the first matrix is: %d\n", det);
    return 0;
}

void read_matrix(int row, int col, int matrix[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int row, int col, int matrix[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void scalar_multiplication(int row, int col, int matrix[row][col], int scalar, int result[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            result[i][j] = scalar*matrix[i][j];
        }
    }
}

void add_matrices(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_multiplication(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int result[row1][col2]){
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            result[i][j] = 0;
            for(int k=0; k<col1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int determinant(int size, int matrix[size][size]){
    int det = 0;
    if(size == 1){
        return matrix[0][0];
    }else if(size == 2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }else{
        for(int i=0; i<size; i++){
            int submatrix[size-1][size-1];
            for(int j=1; j<size; j++){
                int k = 0;
                for(int l=0; l<size; l++){
                    if(l!=i){
                        submatrix[j-1][k] = matrix[j][l];
                        k++;
                    }
                }
            }
            det += matrix[0][i] * (i%2==0?1:-1) * determinant(size-1, submatrix);
        }
    }
    return det;
}