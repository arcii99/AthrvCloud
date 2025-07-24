//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>
#include <stdbool.h>

// size of the Sudoku grid
#define SIZE 9

// function to print the Sudoku grid
void print_grid(int grid[][SIZE]) {
    printf("-------------------\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
}

// function to check if a number is valid for a given cell
bool is_valid(int grid[][SIZE], int row, int col, int num) {
    // check if the number already exists in the same row
    for(int i=0; i<SIZE; i++) {
        if(grid[row][i] == num) {
            return false;
        }
    }
    // check if the number already exists in the same column
    for(int i=0; i<SIZE; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }
    // check if the number already exists in the same 3x3 grid
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for(int i=start_row; i<start_row+3; i++) {
        for(int j=start_col; j<start_col+3; j++) {
            if(grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// function to solve the Sudoku grid
bool solve_sudoku(int grid[][SIZE], int row, int col) {
    // check if we have reached the end of the grid
    if(row == SIZE-1 && col == SIZE) {
        return true;
    }
    // check if we have reached the end of the current row
    if(col == SIZE) {
        row++;
        col = 0;
    }
    // check if the current cell is already filled
    if(grid[row][col] != 0) {
        return solve_sudoku(grid, row, col+1);
    }
    // try all numbers from 1 to 9
    for(int num=1; num<=9; num++) {
        if(is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if(solve_sudoku(grid, row, col+1)) {
                return true;
            }
        }
        // undo the changes if the current number does not lead to a valid solution
        grid[row][col] = 0;
    }
    return false;
}

int main() {
    // sample Sudoku grid
    int grid[SIZE][SIZE] = {
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
    printf("Before solving:\n");
    print_grid(grid);
    printf("Solving...\n");
    if(solve_sudoku(grid, 0, 0)) {
        printf("Sudoku solved:\n");
        print_grid(grid);
    } else {
        printf("No solution exists!\n");
    }
    return 0;
}