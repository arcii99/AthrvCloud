//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

// Function to print the grid
void printGrid() {
    printf("-------------------------\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("|");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf(" %d ", grid[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

// Function to check if a number is valid in a cell
int isValid(int row, int col, int num) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the sudoku using backtracking
int solve(int row, int col) {
    if (row == GRID_SIZE) {
        return 1;
    }
    if (col == GRID_SIZE) {
        return solve(row + 1, 0);
    }
    if (grid[row][col] != 0) {
        return solve(row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            grid[row][col] = num;
            if (solve(row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Generate a random grid
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 10;
        }
    }
    
    // Solve the sudoku
    if (solve(0, 0) == 1) {
        printf("Solved Sudoku:\n");
        printGrid();
    } else {
        printf("Unable to solve.\n");
    }

    return 0;
}