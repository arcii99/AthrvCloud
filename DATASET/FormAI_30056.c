//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>

// Function to display a matrix
void displayMatrix(int matrix[][3], int rows, int cols) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the transpose of a matrix
void findTranspose(int matrix[][3], int rows, int cols) {
    int transpose[cols][rows];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }
    printf("\nTranspose:\n");
    displayMatrix(transpose, cols, rows);
}

// Function to add two matrices
void addMatrix(int matrix1[][3], int matrix2[][3], int rows, int cols) {
    int sum[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("\nSum:\n");
    displayMatrix(sum, rows, cols);
}

// Main function
int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printf("Matrix 1:");
    displayMatrix(matrix1, 3, 3);

    printf("\nMatrix 2:");
    displayMatrix(matrix2, 3, 3);

    findTranspose(matrix1, 3, 3);
    findTranspose(matrix2, 3, 3);

    addMatrix(matrix1, matrix2, 3, 3);

    return 0;
}