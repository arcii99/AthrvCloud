//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>

int main() {
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    printf("Original Matrix: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Transpose the matrix
    printf("Transposed Matrix: \n");
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Multiply the matrix with a scalar value
    printf("Matrix multiplied with scalar value 2: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = matrix[i][j] * 2;
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Add two matrices
    int matrix1[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7},
                        {6, 5, 4},
                        {3, 2, 1}};
    int result_matrix[3][3];
    printf("Resultant Matrix after addition of matrix1 and matrix2: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d   ", result_matrix[i][j]);
        }
        printf("\n");
    }
}