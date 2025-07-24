//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int grid[9][9]; // 9x9 grid for the Sudoku puzzle

void display_grid() {
    printf("\n\t ** The Enchanted Sudoku Grid **\n");
    printf("\t*********************************\n");
    
    // Loop through each row and column to print out the grid
    for(int row = 0; row < 9; row++) {
        printf("\t*");
        for(int col = 0; col < 9; col++) {
            if(grid[row][col] != 0) {
                printf(" %d ", grid[row][col]);
            } else {
                printf(" § ");
            }
            // Insert an astrix after every third column to separate each 3x3 sub-grid
            if((col + 1) % 3 == 0) {
                printf("*");
            }
        }
        printf("\n");
        // Insert a line of hyphens after every third row to separate each 3x3 sub-grid
        if((row + 1) % 3 == 0) {
            printf("\t*********************************");
        }
        printf("\n");
    }
    printf("\n");
}

int check_row(int row, int num) {
    // Check if the number already exists in the given row
    for(int col = 0; col < 9; col++) {
        if(grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int check_col(int col, int num) {
    // Check if the number already exists in the given column
    for(int row = 0; row < 9; row++) {
        if(grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int check_subgrid(int row_start, int col_start, int num) {
    // Check if the number already exists in the given 3x3 sub-grid
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(grid[row_start + row][col_start + col] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int find_empty_cell(int *row, int *col) {
    // Find an empty cell in the grid (marked with 0)
    for(*row = 0; *row < 9; (*row)++) {
        for(*col = 0; *col < 9; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_puzzle() {
    int row, col, num;
    
    if(!find_empty_cell(&row, &col)) {
        // If there are no more empty cells, the puzzle is solved!
        return 1;
    }
    
    // Try each number from 1 to 9 until a valid solution is found
    for(num = 1; num <= 9; num++) {
        if(check_row(row, num) && check_col(col, num) && check_subgrid(row - row % 3, col - col % 3, num)) {
            grid[row][col] = num;
            if(solve_puzzle()) {
                return 1; // recursive call to solve the rest of the puzzle
            }
            grid[row][col] = 0; // backtrack if a solution is not found
        }
    }
    
    return 0;
}

int main() {
    printf("Welcome to the Enchanted Sudoku Solver!\n");
    printf("Enter the numbers for your Sudoku puzzle, row by row (use 0 to represent empty cells):\n");
    printf("Example: 530070000\n         600195000\n         098000060\n         800060003\n         400803001\n         700020006\n         060000280\n         000419005\n         000080079\n");
    
    // Read in the numbers provided by the user and initialize the grid
    char input[10];
    for(int row = 0; row < 9; row++) {
        printf("Row %d: ", row + 1);
        fgets(input, 10, stdin);
        for(int col = 0; col < 9; col++) {
            grid[row][col] = input[col] - '0'; // convert the char to an int
        }
    }
    
    display_grid(); // display the initial puzzle
    
    if(solve_puzzle()) {
        printf("The Enchanted Sudoku puzzle has been solved!\n");
        display_grid(); // display the solved puzzle
    } else {
        printf("The Enchanted Sudoku puzzle could not be solved.\n");
    }
    
    return 0;
}