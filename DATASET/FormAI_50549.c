//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

void print_matrix(int matrix[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void scalar_product(int matrix[ROW][COL], int scalar){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            matrix[i][j] = matrix[i][j] * scalar;
        }
    }
}

void add_matrices(int matrix1[ROW][COL], int matrix2[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void transpose(int matrix[ROW][COL]){
    int temp;
    for(int i=0; i<ROW; i++){
        for(int j=i+1; j<COL; j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void matrix_multiplication(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]){
    int sum;
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            sum = 0;
            for(int k=0; k<COL; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main(){
    int matrix[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int scalar = 2;
    printf("Original Matrix:\n");
    print_matrix(matrix);
    printf("\n");

    scalar_product(matrix, scalar);
    printf("Matrix after scalar product:\n");
    print_matrix(matrix);
    printf("\n");

    int matrix2[ROW][COL] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    printf("Matrix 1:\n");
    print_matrix(matrix);
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    add_matrices(matrix, matrix2);
    printf("Matrix after adding Matrix 1 and Matrix 2:\n");
    print_matrix(matrix);
    printf("\n");

    printf("Matrix after transposing:\n");
    transpose(matrix);
    print_matrix(matrix);
    printf("\n");

    int result[ROW][COL];
    matrix_multiplication(matrix, matrix2, result);
    printf("Resultant matrix after multiplication:\n");
    print_matrix(result);
    printf("\n");

    return 0;
}