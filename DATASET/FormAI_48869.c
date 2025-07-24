//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 3
#define MAX_COLUMNS 3

// Function to initialize a matrix
void initialize_matrix(int matrix[MAX_ROWS][MAX_COLUMNS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void print_matrix(int matrix[MAX_ROWS][MAX_COLUMNS]) {
    printf("Matrix:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to compute the sum of the diagonal elements of a matrix
int diagonal_sum(int matrix[MAX_ROWS][MAX_COLUMNS]) {
    int sum = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    // Seed the random number generator
    srand(1234);

    // Declare and initialize the matrix
    int matrix[MAX_ROWS][MAX_COLUMNS];
    initialize_matrix(matrix);

    // Print the matrix
    print_matrix(matrix);

    // Compute the sum of the diagonal elements
    int sum = diagonal_sum(matrix);
    printf("Sum of diagonal elements: %d\n", sum);

    return 0;
}