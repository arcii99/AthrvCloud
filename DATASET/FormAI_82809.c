//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main() {
    int matrix[ROWS][COLS];

    // Initialize the matrix with random values from 1-20
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            matrix[i][j] = (rand() % 20) + 1;
        }
    }

    // Print the matrix before manipulation
    printf("Original Matrix:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the maximum value in the matrix and its location
    int max = -1, max_row, max_col;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    printf("Maximum value in matrix: %d\n", max);
    printf("Location of maximum value: row %d, column %d\n", max_row, max_col);

    // Transpose the matrix
    int transpose[COLS][ROWS];
    for(int i=0; i<COLS; i++) {
        for(int j=0; j<ROWS; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    for(int i=0; i<COLS; i++) {
        for(int j=0; j<ROWS; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    // Find the sum of each row in the transposed matrix
    int row_sums[COLS] = {0};
    for(int i=0; i<COLS; i++) {
        for(int j=0; j<ROWS; j++) {
            row_sums[i] += transpose[i][j];
        }
    }

    // Print the row sums
    printf("Row Sums:\n");
    for(int i=0; i<COLS; i++) {
        printf("Row %d: %d\n", i+1, row_sums[i]);
    }

    return 0;
}