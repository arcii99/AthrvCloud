//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Alan Touring
#include <stdio.h>

int board[9][9];

// Function to print the board
void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a number is valid in a particular cell
int valid(int row, int col, int num) {
    // Check for duplicates in row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check for duplicates in column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check for duplicates in 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    // If no duplicates found, return 1
    return 1;
}

// Function to solve sudoku
int solve_sudoku() {
    int row = -1;
    int col = -1;
    int no_empty_cells = 1;
    // Check for empty cells
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                no_empty_cells = 0;
                break;
            }
        }
        if (!no_empty_cells) {
            break;
        }
    }
    // If no empty cells found, return 1
    if (no_empty_cells) {
        return 1;
    }
    for (int num = 1; num <= 9; num++) {
        // Check if num is valid in cell
        if (valid(row, col, num)) {
            board[row][col] = num;
            // Recursively solve
            if (solve_sudoku()) {
                return 1;
            }
            // If solution not found, backtrack
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Sample board
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
    printf("Original board:\n");
    print_board();
    // Solve sudoku
    solve_sudoku();
    printf("Solved board:\n");
    print_board();
    return 0;
}