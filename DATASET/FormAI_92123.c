//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>

// Artistic style matrix operations example program

void printMatrix(int arr[][3], int row, int col) { // function to print matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("***************************************************\n");
    printf("************* Artistic Matrix Operations **********\n");
    printf("***************************************************\n\n");
    
    int row = 3, col = 3;
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};

    printf("The first matrix is:\n");
    printMatrix(matrix1, row, col);
    printf("\nThe second matrix is:\n");
    printMatrix(matrix2, row, col);

    printf("\n***************************************************\n");
    printf("******************** Add matrices *****************\n");
    printf("***************************************************\n\n");

    int sum_matrix[3][3];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The addition of the matrices is:\n");
    printMatrix(sum_matrix, row, col);

    printf("\n***************************************************\n");
    printf("******************* Multiply matrices *************\n");
    printf("***************************************************\n\n");

    int product_matrix[3][3];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            product_matrix[i][j] = 0;
            for (int k = 0; k < col; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The product of the matrices is:\n");
    printMatrix(product_matrix, row, col);

    printf("\n***************************************************\n");
    printf("******************** Transpose matrix *************\n");
    printf("***************************************************\n\n");

    int transpose_matrix[3][3];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose_matrix[i][j] = matrix1[j][i];
        }
    }

    printf("The transpose of the first matrix is:\n");
    printMatrix(transpose_matrix, col, row);

    return 0;
}