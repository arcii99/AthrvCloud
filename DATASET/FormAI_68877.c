//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool is_possible(int grid[][SIZE], int row, int col, int num) {
    // Check if the number already exists in row
    for(int i=0; i<SIZE; i++) {
        if(grid[row][i] == num) {
            return false;
        }
    }

    // Check if the number already exists in column
    for(int i=0; i<SIZE; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number already exists in 3x3 subgrid
    int subgrid_row = row - (row % 3);
    int subgrid_col = col - (col % 3);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[subgrid_row+i][subgrid_col+j] == num) {
                return false;
            }
        }
    }

    // It is possible to place the number
    return true;
}

bool solve_sudoku(int grid[][SIZE], int row, int col) {
    // Check if all cells have been filled
    if(row == SIZE) {
        return true;
    }

    // Move to next row if current row is filled
    if(col == SIZE) {
        return solve_sudoku(grid, row+1, 0);
    }

    // Check if the cell is already filled
    if(grid[row][col] != 0) {
        return solve_sudoku(grid, row, col+1);
    }

    // Try all possible numbers in the cell
    for(int num=1; num<=9; num++) {
        if(is_possible(grid, row, col, num)) {
            // Place the number in the cell
            grid[row][col] = num;

            // Recursively try to fill the rest of the board
            if(solve_sudoku(grid, row, col+1)) {
                return true;
            }

            // Backtrack and try another number if the solution is not possible
            grid[row][col] = 0;
        }
    }

    // Backtrack to the previous cell if none of the numbers work
    return false;
}

void print_sudoku(int grid[][SIZE]) {
    printf("+-------+-------+-------+\n");
    for(int i=0; i<SIZE; i++) {
        printf("| ");
        for(int j=0; j<SIZE; j++) {
            printf("%d ", grid[i][j]);
            if((j+1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");

        if((i+1) % 3 == 0) {
            printf("+-------+-------+-------+\n");
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    printf("Sudoku before solving:\n");
    print_sudoku(grid);

    if(solve_sudoku(grid, 0, 0)) {
        printf("\nSudoku after solving:\n");
        print_sudoku(grid);
    } else {
        printf("No possible solution found.\n");
    }

    return 0;
}