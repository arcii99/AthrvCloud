//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>

#define SIZE 9

int solveSudoku(int grid[SIZE][SIZE], int row, int col);
int isSafe(int grid[SIZE][SIZE], int row, int col, int num);
void printGrid(int grid[SIZE][SIZE]);

int main() {
    int grid[SIZE][SIZE] = {
        {0, 0, 1, 0, 7, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 2, 0, 8, 0, 0, 7, 0},
        {0, 1, 0, 0, 0, 0, 5, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 0}
    };
    
    // Call the function to solve the Sudoku puzzle
    if(solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        printf("No solution exists");
    
    return 0;
}

int solveSudoku(int grid[SIZE][SIZE], int row, int col) {
    // If we have reached the end of the puzzle, return true
    if(row == SIZE-1 && col == SIZE)
        return 1;
    
    // If we have reached the end of a row, move to the next row
    if(col == SIZE) {
        row++;
        col = 0;
    }
    
    // Check if the current cell already has a number, skip to the next cell
    if(grid[row][col] > 0)
        return solveSudoku(grid, row, col+1);
    
    // Try different numbers from 1 to 9 until a valid solution is found
    for(int num = 1; num <= 9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            if(solveSudoku(grid, row, col+1))
                return 1;
        }
    }
    
    // If no valid solution is found, backtrack to the previous cell
    grid[row][col] = 0;
    
    return 0;
}

int isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if the number is already present in the same row
    for(int i = 0; i < SIZE; i++) {
        if(grid[row][i] == num)
            return 0;
    }
    
    // Check if the number is already present in the same column
    for(int j = 0; j < SIZE; j++) {
        if(grid[j][col] == num)
            return 0;
    }
    
    // Check if the number is already present in the same 3x3 square
    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    
    for(int i = rowStart; i < rowStart+3; i++) {
        for(int j = colStart; j < colStart+3; j++) {
            if(grid[i][j] == num)
                return 0;
        }
    }
    
    // If all checks are passed, return true
    return 1;
}

void printGrid(int grid[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}