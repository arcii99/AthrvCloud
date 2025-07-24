//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Alan Touring
#include <stdio.h>

int grid[9][9] = {  // the initial Sudoku grid
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

// function to print the Sudoku grid
void printGrid(int grid[][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// function to check if a number can be placed in a given cell
int canPlace(int grid[][9], int row, int col, int num) {
    // check row and column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    // check 3x3 subgrid
    int subRow = (row / 3) * 3;
    int subCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subRow + i][subCol + j] == num) {
                return 0;
            }
        }
    }
    // number can be placed in the cell
    return 1;
}

// function to solve the Sudoku grid recursively
int solve(int grid[][9], int row, int col) {
    // find the next empty cell
    while (row < 9 && grid[row][col] != 0) {
        if (++col == 9) {
            row++;
            col = 0;
        }
    }
    // the Sudoku grid is solved
    if (row == 9) {
        return 1;
    }
    // try to place a number in the cell
    for (int num = 1; num <= 9; num++) {
        if (canPlace(grid, row, col, num)) {
            grid[row][col] = num;
            // recursively solve the Sudoku grid
            if (solve(grid, row, col)) {
                return 1;
            }
            // undo the placement
            grid[row][col] = 0;
        }
    }
    // no number can be placed, backtrack
    return 0;
}

int main() {
    printf("Initial grid:\n");
    printGrid(grid);
    if (solve(grid, 0, 0)) {
        printf("\nSolved grid:\n");
        printGrid(grid);
    }
    else {
        printf("\nUnable to solve the Sudoku grid.\n");
    }
    return 0;
}