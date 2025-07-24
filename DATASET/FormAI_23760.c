//FormAI DATASET v1.0 Category: Matrix operations ; Style: mind-bending
#include <stdio.h>

// Matrix multiplication function
void matrix_multiply(int a[][3], int b[][2], int row1, int col1, int row2, int col2) {
    int result[row1][col2]; // Initialize the resulting matrix

    // For each element in the resulting matrix, find the dot product of the corresponding row in A and column in B
    for(int i=0; i<row1; i++) {
        for(int j=0; j<col2; j++) {
            int sum = 0;
            for(int k=0; k<col1; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }

    // Print the resulting matrix
    for(int i=0; i<row1; i++) {
        for(int j=0; j<col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[2][3] = {{1,2,3}, {4,5,6}};
    int b[3][2] = {{1,2}, {3,4}, {5,6}};
    int row1 = 2, col1 = 3, row2 = 3, col2 = 2;
    
    printf("Matrix A:\n");
    for(int i=0; i<row1; i++) {
        for(int j=0; j<col1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(int i=0; i<row2; i++) {
        for(int j=0; j<col2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix A*B:\n");
    matrix_multiply(a, b, row1, col1, row2, col2);

    return 0;
}