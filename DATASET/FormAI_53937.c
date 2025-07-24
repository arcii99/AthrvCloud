//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdbool.h>

/* The Sudoku board */
int board[9][9] = { 
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

/* Function to check if a number can be placed in a particular cell */
bool is_valid(int row, int col, int num) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    
    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    
    // Check 3x3 grid
    int grid_row = (row/3) * 3;
    int grid_col = (col/3) * 3;
    for (int i = grid_row; i < grid_row + 3; i++) {
        for (int j = grid_col; j < grid_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

/* Function to solve the Sudoku puzzle */
bool solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(row, col, num)) {
                        board[row][col] = num;
                        if (solve()) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    printf("Solving Sudoku puzzle...\n\n");
    
    // Print initial board
    printf("Initial board:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Solve the puzzle
    if (solve()) {
        printf("Solved board:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Unable to solve the Sudoku puzzle.\n");
    }
    
    return 0;
}