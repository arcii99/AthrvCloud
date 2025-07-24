//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku grid
void print_grid(int grid[9][9]) {
    printf("-------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("|");
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                printf(" .");
            } else {
                printf(" %d", grid[i][j]);
            }
            if ((j + 1) % 3 == 0) {
                printf(" |");
            }
        }
        if ((i + 1) % 3 == 0) {
            printf("\n-------------------");
        }
        printf("\n");
    }
}

// Function to find the next empty cell in the grid
bool find_empty(int grid[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if a number can be placed in a given cell
bool is_safe(int grid[9][9], int row, int col, int num) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku grid
bool solve_sudoku(int grid[9][9]) {
    int row, col;

    // Find next empty cell
    if (!find_empty(grid, &row, &col)) {
        // No more empty cells, Sudoku is solved
        return true;
    }

    // Try numbers 1-9 in the empty cell until a valid number is found
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursive call to solve the remaining grid
            if (solve_sudoku(grid)) {
                return true;
            }

            // Backtrack if the recursive call fails
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[9][9] = {
        { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
        { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
        { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
        { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
        { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
        { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
        { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
        { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
        { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
    };

    printf("Sudoku grid before solving:\n");
    print_grid(grid);

    if (solve_sudoku(grid)) {
        printf("\nSudoku grid after solving:\n");
        print_grid(grid);
    } else {
        printf("No solution exists!");
    }

    return 0;
}