//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>

// Function to print the matrix
void printMatrix(int matrix[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Original Matrix:\n");
    printMatrix(matrix);

    // Puzzle #1
    printf("\n******************************************\n\n");
    int temp = matrix[0][0];
    matrix[0][0] = matrix[2][2];
    matrix[2][2] = temp;
    printMatrix(matrix);

    // Puzzle #2
    printf("\n******************************************\n\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix[i][j] *= 2;
        }
    }
    printMatrix(matrix);

    // Puzzle #3
    printf("\n******************************************\n\n");
    matrix[0][1] = 10;
    matrix[1][2] = 20;
    matrix[2][0] = 30;
    printMatrix(matrix);

    // Puzzle #4
    printf("\n******************************************\n\n");
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum of all elements in matrix: %d", sum);

    return 0;
}