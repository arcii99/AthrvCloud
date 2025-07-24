//FormAI DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int matrix[ROWS][COLS];

void init_matrix() {
    // Initialize matrix with random values
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix() {
    // Print out matrix in a fun arcade-style format
    printf("\n");
    printf("   ");
    for (int i = 0; i < COLS; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    printf("  +");
    for (int i = 0; i < COLS; i++) {
        printf("---");
    }
    printf("+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d |", i);
        for (int j = 0; j < COLS; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("  +");
    for (int i = 0; i < COLS; i++) {
        printf("---");
    }
    printf("+\n");
}

void add_matrices() {
    // Add two matrices together and store the result in the first matrix
    int add_matrix[ROWS][COLS];
    printf("\n-- ADDING MATRICES --\n");
    printf("Enter another matrix to add: (format: 5 values separated by spaces)\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &add_matrix[i][j]);
            matrix[i][j] += add_matrix[i][j];
        }
    }
}

void multiply_matrices() {
    // Multiply two matrices together and store the result in the first matrix
    int multiply_matrix[COLS][ROWS];
    int result_matrix[ROWS][ROWS];
    printf("\n-- MULTIPLYING MATRICES --\n");
    printf("Enter another matrix to multiply: (format: 5 values separated by spaces)\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            scanf("%d", &multiply_matrix[i][j]);
        }
    }
    // Perform matrix multiplication
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result_matrix[i][j] += matrix[i][k] * multiply_matrix[k][j];
            }
        }
    }
    // Copy result back to matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            matrix[i][j] = result_matrix[i][j];
        }
    }
}

int main() {
    init_matrix();
    print_matrix();

    // Allow user to perform operations on matrix until they quit
    int choice = 0;
    while (choice != 3) {
        printf("\n-- MATRIX OPERATIONS --\n");
        printf("1. Add matrices\n");
        printf("2. Multiply matrices\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_matrices();
                break;
            case 2:
                multiply_matrices();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }

        print_matrix();
    }

    return 0;
}