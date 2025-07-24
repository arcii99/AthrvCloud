//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>

#define N 9

int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 0, 0, 0, 2, 0},
    {9, 0, 0, 8, 0, 0, 0, 0, 5},
    {0, 5, 0, 0, 0, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col, int num) {
    // Check if num is not already present in the same row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
  
    // Check if num is not already present in the same 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
  
    return 1;
}

int solveSudoku() {
    int row, col;
    // Find an unassigned cell in the grid
    int found = 0;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    // If all cells are assigned, the Sudoku is solved
    if (!found) {
        return 1;
    }
    // Try all numbers from 1 to 9
    for (int i = 1; i <= 9; i++) {
        // Check if the selected number is safe to place in the current cell
        if (isSafe(row, col, i)) {
            // Place the number in the current cell
            grid[row][col] = i;
            // Recursively solve the remaining grid
            if (solveSudoku()) {
                return 1;
            }
            // If the chosen number does not lead to a solution, undo the choice
            grid[row][col] = 0;
        }
    }
    // If none of the numbers lead to a solution, backtrack
    return 0;
}

int main() {
    if (solveSudoku()) {
        printf("Sudoku solved successfully:\n");
        printGrid();
    } else {
        printf("Sudoku cannot be solved.\n");
    }
    return 0;
}