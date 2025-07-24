//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>

int main() {
    printf("Let's do some Matrix operations!\n");

    // Create a 2D array for Matrix A
    int A[2][2] = {{1, 2}, {3, 4}};

    // Create a 2D array for Matrix B
    int B[2][2] = {{5, 6}, {7, 8}};

    // Create a 2D array for Matrix C that will be used to store the result of our calculations
    int C[2][2] = {{0, 0}, {0, 0}};

    // Add Matrix A and Matrix B
    printf("Add Matrix A and Matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Subtract Matrix A from Matrix B
    printf("Subtract Matrix A from Matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = B[i][j] - A[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Multiply Matrix A and Matrix B
    printf("Multiply Matrix A and Matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Transpose Matrix A
    printf("Transpose Matrix A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[j][i];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}