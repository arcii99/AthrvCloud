//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdbool.h>

// print the sudoku grid
void print_grid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// check if the given number can be placed in the cell
bool is_valid(int grid[9][9], int row, int col, int num) {
    // check row
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num)
            return false;
    }
    // check column
    for(int i=0; i<9; i++) {
        if(grid[i][col] == num)
            return false;
    }
    // check 3x3 subgrid
    int subgrid_row = (row/3)*3;
    int subgrid_col = (col/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[subgrid_row+i][subgrid_col+j] == num)
                return false;
        }
    }
    // number can be placed in the cell
    return true;
}

// solve the sudoku puzzle
bool solve_sudoku(int grid[9][9]) {
    int row, col;

    // find unassigned cell
    bool is_unassigned = false;
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(grid[row][col] == 0) {
                is_unassigned = true;
                break;
            }
        }
        if(is_unassigned)
            break;
    }

    // if no unassigned cell found, the puzzle is solved
    if(!is_unassigned)
        return true;

    // try each number to place in the cell
    for(int num=1; num<=9; num++) {
        if(is_valid(grid, row, col, num)) {
            // assign the number
            grid[row][col] = num;
            // solve the puzzle recursively
            if(solve_sudoku(grid))
                return true;
            // undo the assignment
            grid[row][col] = 0;
        }
    }

    // no number can be placed in the cell
    return false;
}

int main() {
    int grid[9][9] = {
        {7, 8, 0, 4, 0, 0, 1, 2, 0},
        {6, 0, 0, 0, 7, 5, 0, 0, 9},
        {0, 0, 0, 6, 0, 1, 0, 7, 8},
        {0, 0, 7, 0, 4, 0, 2, 6, 0},
        {0, 0, 1, 0, 5, 0, 9, 3, 0},
        {9, 0, 4, 0, 6, 0, 0, 0, 5},
        {0, 7, 0, 3, 0, 0, 0, 1, 2},
        {1, 2, 0, 0, 0, 7, 4, 0, 0},
        {0, 4, 9, 2, 0, 6, 0, 0, 7}
    };

    printf("Sudoku puzzle:\n");
    print_grid(grid);

    if(solve_sudoku(grid)) {
        printf("Sudoku puzzle solved:\n");
        print_grid(grid);
    }
    else {
        printf("No solution found for the sudoku puzzle\n");
    }

    return 0;
}