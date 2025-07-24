//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of matrix

void generateMatrix(int (*matrix)[N]) {
    srand(time(NULL)); // Set random seed based on current time

    // Initialize matrix with random 0's and 1's
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

void printMatrix(int (*matrix)[N]) {
    // Print matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void percolate(int (*matrix)[N]) {
    int flag = 1; // Flag to mark if any changes made in last iteration
    // Keep checking and changing the matrix until no further changes can be made
    while (flag) {
        flag = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 1) {
                    // Check if any neighboring cell is also 1, if yes, change the current cell to 1
                    if ((j < N - 1 && matrix[i][j+1] == 2) ||
                        (i < N - 1 && matrix[i+1][j] == 2) ||
                        (j > 0 && matrix[i][j-1] == 2) ||
                        (i > 0 && matrix[i-1][j] == 2)) {
                        matrix[i][j] = 2;
                        flag = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int matrix[N][N];

    generateMatrix(matrix);
    printf("Initial matrix:\n");
    printMatrix(matrix);

    percolate(matrix);
    printf("Final matrix:\n");
    printMatrix(matrix);

    return 0;
}