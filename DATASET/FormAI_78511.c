//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define PROBABILITY 0.55 // Probability of a cell being open

// Grid representation using a two-dimensional array
int grid[SIZE][SIZE];

// Function declaration
void generateGrid();
void printGrid();
int percolation();
void openCells(int row, int col);
int isFull(int row, int col);

int main() {
    srand(time(NULL)); // Seed the random number generator
    generateGrid(); // Generate the grid
    printGrid(); // Print the original grid
    percolation(); // Run the percolation algorithm
    printGrid(); // Print the final grid
    return 0;
}

// Function to generate the grid
void generateGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((double) rand() / (double) RAND_MAX < PROBABILITY) {
                grid[i][j] = 1; // Open cell
            } else {
                grid[i][j] = 0; // Blocked cell
            }
        }
    }
}

// Function to print the grid
void printGrid() {
    printf("\nGrid:\n\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf("X "); // Blocked cell
            } else if (isFull(i, j)) {
                printf("O "); // Full cell
            } else {
                printf(". "); // Open cell
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Percolation algorithm
int percolation() {
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] == 1) {
            openCells(0, i); // Open cell if it is connected to the top row
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (isFull(SIZE - 1, i)) {
            return 1; // The grid percolates
        }
    }
    return 0; // The grid does not percolate
}

// Function to open connected cells
void openCells(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || grid[row][col] == 0 || isFull(row, col)) {
        return; // Out of bounds or already open or already full
    }
    grid[row][col] = 2; // Mark cell as visited
    openCells(row - 1, col); // Open cell above
    openCells(row + 1, col); // Open cell below
    openCells(row, col - 1); // Open cell left
    openCells(row, col + 1); // Open cell right
}

// Function to check if a cell is connected to the top row
int isFull(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || grid[row][col] != 1) {
        return 0; // Out of bounds or not open
    }
    if (row == 0) {
        return 1; // Cell is connected to the top row
    }
    grid[row][col] = 2; // Mark cell as visited
    if (isFull(row - 1, col) || isFull(row + 1, col) || isFull(row, col - 1) || isFull(row, col + 1)) {
        return 1; // Cell is connected to the top row through neighboring cells
    }
    return 0; // Cell is not connected to the top row
}