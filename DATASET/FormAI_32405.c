//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>

// Function to print a matrix
void printMatrix(int matrix[][3], int size) {
    printf("Your matrix is: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[][3], int size) {
    printf("\nLet's transpose your matrix! \n");

    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    printMatrix(matrix, size);
}

// Function to add two matrices
void addMatrices(int matrix1[][3], int matrix2[][3], int size) {
    printf("\nLet's add your matrices! \n");

    int sum[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the sum matrix
    printf("The sum of your matrices is: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hello there! Let's do some matrix operations! \n");

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
    int size = 3;

    // Print the original matrices
    printMatrix(matrix1, size);
    printf("\n");
    printMatrix(matrix2, size);

    // Transpose the first matrix
    transposeMatrix(matrix1, size);

    // Add the two matrices
    addMatrices(matrix1, matrix2, size);

    printf("\nYay, we did it! Goodbye for now! \n");

    return 0;
}