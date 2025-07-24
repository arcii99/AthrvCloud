//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scientific
#include <stdio.h>

// Function to check if a number is safe to place
int isSafe(int grid[9][9], int row, int col, int num) {
    // Check if number is already in row or column
    for(int i = 0; i < 9; i++) {
        if(grid[row][i] == num || grid[i][col] == num)
            return 0;
    }

    // Check if number is already in 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for(int i = boxRow; i < boxRow + 3; i++) {
        for(int j = boxCol; j < boxCol + 3; j++) {
            if(grid[i][j] == num)
                return 0;
        }
    }

    // If number is safe to place, return true
    return 1;
}

// Function to solve sudoku recursively
int solveSudoku(int grid[9][9], int row, int col) {
    // Check if we have reached the end of the puzzle
    if(row == 9)
        return 1;

    // Check if we have reached the end of the row
    if(col == 9)
        return solveSudoku(grid, row + 1, 0);

    // Check if cell is already solved
    if(grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // Try placing numbers 1 to 9
    for(int num = 1; num <= 9; num++) {
        // Check if number is safe to place
        if(isSafe(grid, row, col, num)) {
            // Place number in cell and try solving next cell
            grid[row][col] = num;
            if(solveSudoku(grid, row, col + 1))
                return 1;
            // If solution not found, backtrack and undo cell
            grid[row][col] = 0;
        }
    }

    // If no number is safe to place, backtrack
    return 0;
}

int main() {
    int grid[9][9] = {
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

    // Print initial grid
    printf("Initial grid:\n");
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Solve the sudoku
    if(solveSudoku(grid, 0, 0)) {
        // Print solved grid
        printf("Solved grid:\n");
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}