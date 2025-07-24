//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>

// Function to check if a number is safe to add to a row,column or box
int isSafe(int grid[9][9], int row, int col, int num) {
    // Check if the same number is already present in the current row
    for (int i = 0; i < 9; i++)
        if (grid[row][i] == num)
            return 0;

    // Check if the same number is already present in the current column
    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return 0;

    // Check if the same number is already present in the current box
    int boxRow = row / 3;
    int boxCol = col / 3;
    for (int i = boxRow * 3; i < (boxRow * 3 + 3); i++)
        for (int j = boxCol * 3; j < (boxCol * 3 + 3); j++)
            if (grid[i][j] == num)
                return 0;

    // If the number is safe, return 1
    return 1;
}

// Function to solve the given Sudoku puzzle
int solveSudoku(int grid[9][9], int row, int col) {
    // If we have reached the last row and column of the grid, the Sudoku puzzle is solved
    if (row == 8 && col == 9)
        return 1;

    // If we have reached the last column of the grid, move to the next row
    if (col == 9) {
        row++;
        col = 0;
    }

    // If the current cell is not empty, move to the next cell
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // If the current cell is empty, try adding numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // If the current number is safe to add, add it to the grid and move to the next cell
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return 1;
        }
        // If the current number is not safe to add, reset the cell to 0 and try the next number
        grid[row][col] = 0;
    }

    // If none of the numbers can be added to the current cell, backtrack
    return 0;
}

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

int main() {
    // Initialize the Sudoku grid
    int grid[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Update the grid with the given Sudoku puzzle
    // (Replace the zeros with the actual numbers in the unsolved puzzle)
    grid[0][0] = 5; grid[0][2] = 6; grid[0][5] = 4; grid[0][7] = 1;
    grid[1][0] = 3; grid[1][5] = 8; grid[1][8] = 6;
    grid[2][2] = 9; grid[2][3] = 5; grid[2][8] = 7;
    grid[3][1] = 4; grid[3][3] = 6; grid[3][5] = 1; grid[3][7] = 9;
    grid[4][2] = 8; grid[4][4] = 9; grid[4][6] = 5;
    grid[5][1] = 8; grid[5][3] = 2; grid[5][5] = 5; grid[5][7] = 4;
    grid[6][0] = 7; grid[6][5] = 2; grid[6][6] = 4;
    grid[7][0] = 9; grid[7][3] = 8; grid[7][8] = 3;
    grid[8][1] = 7; grid[8][4] = 3; grid[8][5] = 9; grid[8][8] = 4;

    // Solve the Sudoku puzzle
    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        printf("No solution exists\n");

    return 0;
}