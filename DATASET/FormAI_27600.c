//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS]; // Grid of cells

void initialize(); // Initializes the grid with random values
void show(); // Displays the grid
int percolates(); // Returns 1 if the system percolates, otherwise 0
void percolate(int row, int col); // Marks the neighboring cells as open if they are also connected
int isOpen(int row, int col); // Checks if a given cell is open
int isFull(int row, int col); // Checks if a given cell is full

int main() {
    initialize();
    printf("\nInitial Grid\n");
    show();
    if (percolates()) {
        printf("\nPercolation achieved!\n");
    } else {
        printf("\nPercolation not achieved!\n");
    }
    return 0;
}

void initialize() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1; // A cell is open
            } else {
                grid[i][j] = 0; // A cell is blocked
            }
        }
    }
}

void show() {
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (isOpen(i, j)) {
                printf(" ");
            } else {
                printf("X");
            }
        }
        printf("|\n");
    }
}

int isOpen(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0; // Bounds check
    }
    return grid[row][col] == 1;
}

int isFull(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0; // Bounds check
    }
    return grid[row][col] == 2;
}

void percolate(int row, int col) {
    if (isOpen(row, col) && !isFull(row, col)) {
        grid[row][col] = 2;
        percolate(row - 1, col); // Top
        percolate(row + 1, col); // Bottom
        percolate(row, col - 1); // Left
        percolate(row, col + 1); // Right
    }
}

int percolates() {
    // Start the percolation process from the top row
    for (int col = 0; col < COLS; col++) {
        percolate(0, col);
    }
    // Check if any cell in the bottom row is full
    for (int col = 0; col < COLS; col++) {
        if (isFull(ROWS - 1, col)) {
            return 1;
        }
    }
    return 0; // Percolation not achieved
}