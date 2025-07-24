//FormAI DATASET v1.0 Category: Sudoku solver ; Style: automated
#include <stdio.h>

//Function to print the sudoku grid
void print_grid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//Function to check whether a number is safe to place at a certain position
int is_safe(int grid[9][9], int i, int j, int num) {
    //Check whether num is already present in the row
    for(int x=0; x<9; x++) {
        if(grid[i][x] == num) {
            return 0;
        }
    }
    
    //Check whether num is already present in the column
    for(int x=0; x<9; x++) {
        if(grid[x][j] == num) {
            return 0;
        }
    }
    
    //Check whether num is already present in the 3x3 subgrid
    int subgrid_i = 3 * (i / 3);
    int subgrid_j = 3 * (j / 3);
    for(int x=subgrid_i; x<subgrid_i+3; x++) {
        for(int y=subgrid_j; y<subgrid_j+3; y++) {
            if(grid[x][y] == num) {
                return 0;
            }
        }
    }
    
    //If all checks pass, then num is safe to place at position (i, j)
    return 1;
}

//Function to solve the sudoku grid using backtracking
int solve_sudoku(int grid[9][9], int i, int j) {
    //If we have reached the end of the grid, then the sudoku has been solved
    if(i == 9) {
        return 1;
    }
    
    //If we have reached the end of a row, move to the next row
    if(j == 9) {
        return solve_sudoku(grid, i+1, 0);
    }
    
    //If the current cell is not empty, move to the next cell
    if(grid[i][j] != 0) {
        return solve_sudoku(grid, i, j+1);
    }
    
    //If the current cell is empty, try filling it with numbers 1-9
    for(int num=1; num<=9; num++) {
        if(is_safe(grid, i, j, num)) {
            grid[i][j] = num;
            if(solve_sudoku(grid, i, j+1)) {
                //If we have found a solution, return true
                return 1;
            }
            else {
                //If this num did not lead to a solution, backtrack and try the next num
                grid[i][j] = 0;
            }
        }
    }
    
    //If none of the numbers worked, then the sudoku cannot be solved
    return 0;
}

//Driver function
int main() {
    //Initialize the sudoku grid
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    printf("Sudoku grid before solving:\n");
    print_grid(grid);
    
    if(solve_sudoku(grid, 0, 0)) {
        printf("Sudoku grid after solving:\n");
        print_grid(grid);
    }
    else {
        printf("The sudoku cannot be solved.\n");
    }

    return 0;
}