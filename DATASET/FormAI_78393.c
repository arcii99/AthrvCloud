//FormAI DATASET v1.0 Category: Sudoku solver ; Style: active
#include <stdio.h>

// display the sudoku grid
void display(int grid[9][9]) {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// check if a certain number can be placed in a certain cell
int is_valid(int grid[9][9], int row, int col, int num) {
    // check row
    for(int i=0;i<9;i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }
    // check column
    for(int i=0;i<9;i++) {
        if(grid[i][col] == num) {
            return 0;
        }
    }
    // check 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for(int i=box_row;i<box_row+3;i++) {
        for(int j=box_col;j<box_col+3;j++) {
            if(grid[i][j] == num) {
                return 0;
            }
        }
    }
    // number can be placed in the cell
    return 1;
}

// solve the sudoku
int solve(int grid[9][9], int row, int col) {
    if(row == 9) {
        // sudoku solved
        return 1;
    }
    if(col == 9) {
        // move to next row
        return solve(grid, row+1, 0);
    }
    if(grid[row][col] != 0) {
        // cell already filled, move to next cell
        return solve(grid, row, col+1);
    }
    for(int num=1;num<=9;num++) {
        if(is_valid(grid, row, col, num)) {
            // place the number in the cell
            grid[row][col] = num;
            // check if sudoku can be solved with this number in the cell
            if(solve(grid, row, col+1)) {
                return 1;
            }
            // backtrack
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // example sudoku
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
    // display original sudoku
    printf("Original Sudoku:\n");
    display(grid);
    // solve sudoku
    if(solve(grid, 0, 0)) {
        // display solved sudoku
        printf("Solved Sudoku:\n");
        display(grid);
    }
    else {
        printf("No solution found\n");
    }
    // finished
    return 0;
}