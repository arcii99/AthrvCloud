//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 20
#define COLS 20

// Define the matrix and initialize it with 0 values
int matrix[ROWS][COLS] = {0};

// Define a function to print the matrix on the screen
void showMatrix(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Define a function to simulate the percolation
void percolation(int rows, int cols) {
    // Generate a random start point for the percolation
    int i = rand() % rows; 
    int j = 0; 
    matrix[i][j] = 1; // Set the start point as 1

    // Start the percolation process
    while (i < rows - 1) { 
        int r = rand() % 100;
        if (r < 50 && j > 0 && matrix[i][j - 1] == 0) { // If the random number generated is less than 50 and the left cell is not filled yet, move to the left
            j--;
        }
        else if (r > 50 && j < cols - 1 && matrix[i][j + 1] == 0) { // If the random number generated is greater than 50 and the right cell is not filled yet, move to the right
            j++;
        }
        i++; // Move one row down
        matrix[i][j] = 1; // Fill the current cell with 1
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Simulate the percolation
    percolation(ROWS, COLS);

    // Print the final matrix
    showMatrix(ROWS, COLS);

    return 0;
}