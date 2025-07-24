//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>

int count = 0; // Global variable to keep count of solutions found

// Function to check if a given number can be placed in the grid
int isValid(int grid[][9], int row, int col, int num) {
    // Check if the number exists in the same row
    for(int colIndex = 0; colIndex < 9; colIndex++) {
        if(grid[row][colIndex] == num) {
            return 0;
        }
    }

    // Check if the number exists in the same column
    for(int rowIndex = 0; rowIndex < 9; rowIndex++) {
        if(grid[rowIndex][col] == num) {
            return 0;
        }
    }

    // Check if the number exists in the same 3x3 grid
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for(int rowIndex = 0; rowIndex < 3; rowIndex++) {
        for(int colIndex = 0; colIndex < 3; colIndex++) {
            if(grid[rowIndex + startRow][colIndex + startCol] == num) {
                return 0;
            }
        }
    }

    // If the number can be placed in the grid, return 1
    return 1;
}

// Function to solve the sudoku puzzle
void solveSudoku(int grid[][9], int row, int col) {
    // If we have reached the end of a row, move to the next row
    if(col == 9) {
        col = 0;
        row++;
    }

    // If we have reached the end of the grid, we have found a solution
    if(row == 9) {
        count++; // Increment the solution count
        printf("Solution #%d:\n", count);

        // Print out the solution
        for(int rowIndex = 0; rowIndex < 9; rowIndex++) {
            for(int colIndex = 0; colIndex < 9; colIndex++) {
                printf("%d ", grid[rowIndex][colIndex]);
            }

            printf("\n");
        }

        printf("\n");
        return;
    }

    // If the current cell is already filled, move to the next cell
    if(grid[row][col] != 0) {
        solveSudoku(grid, row, col + 1);
    } else {
        // Try to place a number in the current cell
        for(int num = 1; num <= 9; num++) {
            if(isValid(grid, row, col, num)) {
                grid[row][col] = num;

                // Try to solve the rest of the puzzle
                solveSudoku(grid, row, col + 1);

                // If a solution is not found, backtrack and try a different number
                grid[row][col] = 0;
            }
        }
    }
}

int main() {
    // Create an unsolved sudoku puzzle
    int grid[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 8, 5},
        {0, 0, 1, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 7, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 1, 0, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 7, 3},
        {0, 0, 2, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 9}
    };

    // Print out the unsolved puzzle
    printf("Unsolved Puzzle:\n");

    for(int rowIndex = 0; rowIndex < 9; rowIndex++) {
        for(int colIndex = 0; colIndex < 9; colIndex++) {
            printf("%d ", grid[rowIndex][colIndex]);
        }

        printf("\n");
    }

    printf("\n");

    // Solve the sudoku puzzle
    solveSudoku(grid, 0, 0);

    // If no solutions are found, print out a message
    if(count == 0) {
        printf("No solutions found.\n");
    }

    return 0;
}