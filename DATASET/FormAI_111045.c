//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>

// Function to print the grid
void print_grid(int grid[][9]) {
    printf("Sudoku Grid:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the number is in the row
int in_row(int row, int num, int grid[][9]) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the number is in the column
int in_column(int column, int num, int grid[][9]) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][column] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the number is in the block
int in_block(int row, int column, int num, int grid[][9]) {
    int start_row = row - row % 3;
    int start_column = column - column % 3;
    
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_column; j < start_column + 3; j++) {
            if (grid[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the number can be placed in the grid
int is_valid(int row, int column, int num, int grid[][9]) {
    if (!in_row(row, num, grid) && !in_column(column, num, grid) 
        && !in_block(row, column, num, grid)) {
        return 1;
    }
    return 0;
}

// Recursive function to solve the Sudoku grid
int solve(int row, int column, int grid[][9]) {
    if (row == 8 && column == 9) {
        return 1;
    }
    
    if (column == 9) {
        row++;
        column = 0;
    }
    
    if (grid[row][column] != 0) {
        return solve(row, column + 1, grid);
    }
    
    for (int num = 1; num <= 9; num++) {
        if (is_valid(row, column, num, grid)) {
            grid[row][column] = num;
            
            if (solve(row, column + 1, grid)) {
                return 1;
            }
        }
        grid[row][column] = 0;
    }
    return 0;
}

int main() {
    // Example Sudoku grid
    int grid[9][9] = {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    };
    
    print_grid(grid);
    
    if (solve(0, 0, grid) == 1) {
        print_grid(grid);
    } else {
        printf("No solution exists.\n");
    }
    
    return 0;
}