//FormAI DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

#define N 9

int puzzle[N][N] = {
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};

/* Function to check if a particular value is valid in the given cell */
bool is_valid(int row, int col, int val) {
    int i, j;
    
    /* Check row and column */
    for (i = 0; i < N; i++) {
        if (puzzle[row][i] == val || puzzle[i][col] == val) {
            return false;
        }
    }
    
    /* Check 3x3 subgrid */
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    
    for (i = row_start; i < row_start + 3; i++) {
        for (j = col_start; j < col_start + 3; j++) {
            if (puzzle[i][j] == val) {
                return false;
            }
        }
    }
    
    /* If all checks pass, value is valid */
    return true;
}

/* Recursive function to solve the puzzle using backtracking */
bool solve_puzzle() {
    int row, col, val;
    
    /* Find first empty cell to start from */
    bool empty_cell_found = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (puzzle[row][col] == 0) {
                empty_cell_found = true;
                break;
            }
        }
        if (empty_cell_found) {
            break;
        }
    }
    
    /* Puzzle is solved if no empty cells remain */
    if (!empty_cell_found) {
        return true;
    }
    
    /* Try all valid values for the empty cell */
    for (val = 1; val <= N; val++) {
        if (is_valid(row, col, val)) {
            puzzle[row][col] = val;
            
            /* Recursively solve remaining cells */
            if (solve_puzzle()) {
                return true;
            }
            
            /* If remaining cells cannot be solved with this value, backtrack */
            puzzle[row][col] = 0;
        }
    }
    
    /* No solution possible with any value for this cell */
    return false;
}

/* Function to check if puzzle is solved */
bool is_puzzle_solved() {
    int row, col;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (puzzle[row][col] == 0 || !is_valid(row, col, puzzle[row][col])) {
                return false;
            }
        }
    }
    
    return true;
}

/* Function to print the puzzle grid */
void print_puzzle() {
    int row, col;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
}

/* Logical reasoning algorithm to fill in as many cells as possible */
void fill_in_logical() {
    int row, col, i, j, k;
    bool cell_filled;
    
    do {
        cell_filled = false;
        
        /* Check each row for missing values */
        for (row = 0; row < N; row++) {
            for (i = 1; i <= N; i++) {
                int count = 0;
                for (col = 0; col < N; col++) {
                    if (puzzle[row][col] == i) {
                        break;
                    } else if (puzzle[row][col] == 0 && is_valid(row, col, i)) {
                        count++;
                    }
                }
                if (count == 1) {
                    for (col = 0; col < N; col++) {
                        if (puzzle[row][col] == 0 && is_valid(row, col, i)) {
                            puzzle[row][col] = i;
                            cell_filled = true;
                            break;
                        }
                    }
                }
            }
        }
        
        /* Check each column for missing values */
        for (col = 0; col < N; col++) {
            for (i = 1; i <= N; i++) {
                int count = 0;
                for (row = 0; row < N; row++) {
                    if (puzzle[row][col] == i) {
                        break;
                    } else if (puzzle[row][col] == 0 && is_valid(row, col, i)) {
                        count++;
                    }
                }
                if (count == 1) {
                    for (row = 0; row < N; row++) {
                        if (puzzle[row][col] == 0 && is_valid(row, col, i)) {
                            puzzle[row][col] = i;
                            cell_filled = true;
                            break;
                        }
                    }
                }
            }
        }
        
        /* Check each 3x3 subgrid for missing values */
        for (i = 1; i <= N; i++) {
            for (row = 0; row < N; row += 3) {
                for (col = 0; col < N; col += 3) {
                    int count = 0, last_row = -1, last_col = -1;
                    for (j = row; j < row + 3; j++) {
                        for (k = col; k < col + 3; k++) {
                            if (puzzle[j][k] == i) {
                                break;
                            } else if (puzzle[j][k] == 0 && is_valid(j, k, i)) {
                                count++;
                                last_row = j;
                                last_col = k;
                            }
                        }
                        if (k < col + 3) {
                            break;
                        }
                    }
                    if (count == 1) {
                        puzzle[last_row][last_col] = i;
                        cell_filled = true;
                    }
                }
            }
        }
    } while (cell_filled);
}

/* Main function */
int main() {
    fill_in_logical();
    printf("Puzzle (with some cells filled in):\n");
    print_puzzle();
    
    if (solve_puzzle()) {
        printf("Solution:\n");
        print_puzzle();
    } else {
        printf("No Solution Possible\n");
    }
    
    if (is_puzzle_solved()) {
        printf("Puzzle is Solved\n");
    } else {
        printf("Puzzle is Not Solved\n");
    }
    
    return 0;
}