//FormAI DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>

// Function to print a matrix
void printMatrix(int matrix[][3], int rows, int cols) {
    printf("\nMatrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[][3], int matrix2[][3], int product[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            product[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matrix2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int product[3][3];
    
    // Print the matrices
    printMatrix(matrix1, 3, 3);
    printMatrix(matrix2, 3, 3);
    
    // Multiply the matrices
    multiplyMatrix(matrix1, matrix2, product);
    
    // Print the product
    printMatrix(product, 3, 3);
    
    return 0;
}