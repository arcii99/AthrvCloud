//FormAI DATASET v1.0 Category: Matrix operations ; Style: content
#include <stdio.h>

int main() {
    // Define the matrices
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];

    // Print the original matrices
    printf("Matrix 1:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", matrix1[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix 2:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", matrix2[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // Add the matrices together
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            result[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }

    // Print the result matrix
    printf("Result Matrix:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", result[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // Multiply the matrices together
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            result[row][col] = 0;
            for (int k = 0; k < 3; k++) {
                result[row][col] += matrix1[row][k] * matrix2[k][col];
            }
        }
    }

    // Print the result matrix
    printf("Result Matrix after Multiplication:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", result[row][col]);
        }
        printf("\n");
    }

    return 0;
}