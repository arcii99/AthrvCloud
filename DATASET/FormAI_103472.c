//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to print matrix
void print_matrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if percolation occurs
int percolates(int matrix[ROWS][COLS]) {
    int i, j, current, down;
    for (j = 0; j < COLS; j++) {
        current = 0;
        down = 0;
        for (i = 0; i < ROWS; i++) {
            if (matrix[i][j] == 1) {
                current = 1;
            }
            if (current == 1 && down == 1) {
                return 1;
            }
            if (i < ROWS - 1) {
                down = matrix[i+1][j];
            }
        }
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    
    // Initialize matrix with 0's and randomly set some to 1's
    int matrix[ROWS][COLS] = {0};
    int i, j, rand_val;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            rand_val = rand() % 2;
            matrix[i][j] = rand_val;
        }
    }
    
    // Print matrix and check for percolation
    print_matrix(matrix);
    int percolation = percolates(matrix);
    
    if (percolation == 1) {
        printf("Percolation occurs!\n");
    } else {
        printf("Percolation does not occur :(\n");
    }
    
    return 0;
}