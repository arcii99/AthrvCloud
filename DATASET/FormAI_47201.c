//FormAI DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include <stdio.h>

void print_board(int board[9][9]) {
    // This function prints the Sudoku board.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int board[9][9], int row, int col, int num) {
    // This function checks if we can place a number 'num' in board[row][col]
    // without violating the Sudoku rules.
    
    // Check the row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == num) {
            return 0;
        }
    }
    
    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    
    // Check the 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solve_board(int board[9][9]) {
    // This function recursively solves the Sudoku board using backtracking.
    // Returns 1 if the board is solvable, 0 otherwise.
    
    int row = -1;
    int col = -1;
    int empty = 0;
    
    // Find the next empty cell
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                empty = 1;
                break;
            }
        }
        if (empty) {
            break;
        }
    }
    
    // If there is no empty cell, the board is solved
    if (!empty) {
        return 1;
    }
    
    // Try to fill the empty cell with numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    
    return 0;
}

int main() {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };
    
    printf("Unsolved board:\n");
    print_board(board);
    
    if (solve_board(board)) {
        printf("\nSolved board:\n");
        print_board(board);
    } else {
        printf("\nNo solution found.\n");
    }
    
    return 0;
}