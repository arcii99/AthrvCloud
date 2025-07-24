//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdbool.h>

// Define the size of our Sudoku grid
#define GRID_SIZE 9

// Function to print out our Sudoku grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a value can be placed in a cell
bool isValueValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int value) {
    // Check the row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == value) {
            return false;
        }
    }
    
    // Check the column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == value) {
            return false;
        }
    }
    
    // Check the 3x3 square
    int squareRow = (row / 3) * 3;
    int squareCol = (col / 3) * 3;
    for (int i = squareRow; i < squareRow + 3; i++) {
        for (int j = squareCol; j < squareCol + 3; j++) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }
    
    // If we've made it here, the value is valid
    return true;
}

// Recursive function to solve the Sudoku grid
bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // If we've reached the last cell, the grid is solved
    if (row == GRID_SIZE - 1 && col == GRID_SIZE) {
        return true;
    }
    
    // If we've reached the last cell in a row, move to the next row
    if (col == GRID_SIZE) {
        row++;
        col = 0;
    }
    
    // If this cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    
    // Try every value from 1 to 9
    for (int value = 1; value <= GRID_SIZE; value++) {
        // If the value is valid, put it in the cell and move to the next cell
        if (isValueValid(grid, row, col, value)) {
            grid[row][col] = value;
            
            // If the Sudoku can be solved with this value, return true
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
        }
    }
    
    // If no value worked, backtrack and try a different value
    grid[row][col] = 0;
    return false;
}

// Main function to run the program
int main() {
    // Define our Sudoku grid
    int grid[GRID_SIZE][GRID_SIZE] = {{8,0,0,0,0,0,0,0,0},
                                      {0,0,3,6,0,0,0,0,0},
                                      {0,7,0,0,9,0,2,0,0},
                                      {0,5,0,0,0,7,0,0,0},
                                      {0,0,0,0,4,5,7,0,0},
                                      {0,0,0,1,0,0,0,3,0},
                                      {0,0,1,0,0,0,0,6,8},
                                      {0,0,8,5,0,0,0,1,0},
                                      {0,9,0,0,0,0,4,0,0}};
    
    // Print out the unsolved grid
    printf("Unsolved Sudoku puzzle:\n");
    printGrid(grid);
    
    // Solve the Sudoku grid
    if (solveSudoku(grid, 0, 0)) {
        // Print out the solved grid
        printf("Solved Sudoku puzzle:\n");
        printGrid(grid);
    } else {
        printf("Unable to solve Sudoku puzzle :(\n");
    }
    
    return 0;
}