//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>

int is_valid(int grid[9][9], int row, int col, int num) {
    // Check if this number is already present in this row
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) {
            return 0;
        }
    }
    
    // Check if this number is already present in this column
    for (int x = 0; x < 9; x++) {
        if (grid[x][col] == num) {
            return 0;
        }
    }
    
    // Check if this number is already present in this 3x3 subgrid
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int x = box_row; x < box_row + 3; x++) {
        for (int y = box_col; y < box_col + 3; y++) {
            if (grid[x][y] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solve_sudoku(int grid[9][9]) {
    // Find an empty cell
    int row = -1;
    int col = -1;
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (grid[x][y] == 0) {
                row = x;
                col = y;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }
    
    // If no empty cell is found, the Sudoku is already solved
    if (row == -1) {
        return 1;
    }
    
    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (solve_sudoku(grid)) {
                return 1;
            }
            
            grid[row][col] = 0;
        }
    }
    
    return 0;
}

void print_sudoku(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
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
    
    printf("Before solving:\n");
    print_sudoku(grid);
    
    if (solve_sudoku(grid)) {
        printf("\nAfter solving:\n");
        print_sudoku(grid);
    } else {
        printf("The Sudoku cannot be solved.\n");
    }
    
    return 0;
}