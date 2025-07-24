//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include <stdio.h>

void add_matrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    int i, j;
    
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    int i, j;
    
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply_matrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    int i, j, k;
    
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            result[i][j] = 0;
            for(k=0;k<3;k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void print_matrix(int matrix[][3]) {
    int i, j;
    
    printf("[\n");
    for(i=0;i<3;i++) {
        printf("\t[");
        for(j=0;j<3;j++) {
            printf("%d", matrix[i][j]);
            if(j!=2) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("]\n");
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];
    
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    
    printf("Matrix 1 + Matrix 2:\n");
    add_matrices(matrix1, matrix2, result);
    print_matrix(result);
    
    printf("Matrix 1 - Matrix 2:\n");
    subtract_matrices(matrix1, matrix2, result);
    print_matrix(result);
    
    printf("Matrix 1 * Matrix 2:\n");
    multiply_matrices(matrix1, matrix2, result);
    print_matrix(result);
    
    return 0;
}