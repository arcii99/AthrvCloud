//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>

#define SIZE 9   // Set the board size to 9x9

// Function to print the board
void print_board(int board[][SIZE]) {
    printf("\n");

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the value is valid in the given row, column and subgrid
int is_valid(int board[][SIZE], int row, int col, int val) {
    // Check row
    for(int j = 0; j < SIZE; j++) {
        if(board[row][j] == val) {
            return 0;
        }
    }

    // Check column
    for(int i = 0; i < SIZE; i++) {
        if(board[i][col] == val) {
            return 0;
        }
    }

    // Check subgrid
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);

    for(int i = start_row; i < start_row + 3; i++) {
        for(int j = start_col; j < start_col + 3; j++) {
            if(board[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solve_board(int board[][SIZE], int row, int col) {
    // Check if we have reached the end of the board
    if(row == SIZE) {
        return 1;
    }

    // Check if we need to move to the next row
    if(col == SIZE) {
        return solve_board(board, row + 1, 0);
    }

    // Check if the current cell is already filled
    if(board[row][col] != 0) {
        return solve_board(board, row, col + 1);
    }

    // Try all possible values in the current cell
    for(int val = 1; val <= SIZE; val++) {
        if(is_valid(board, row, col, val)) {
            board[row][col] = val;

            if(solve_board(board, row, col + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    // If no valid value was found, backtrack
    return 0;
}

int main() {
    int board[SIZE][SIZE] = {
        {0, 2, 0, 6, 0, 8, 0, 0, 0},
        {5, 8, 0, 0, 0, 9, 7, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {3, 7, 0, 0, 0, 0, 5, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 8, 0, 0, 0, 0, 1, 3},
        {0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 9, 8, 0, 0, 0, 3, 6},
        {0, 0, 0, 3, 0, 0, 0, 9, 0}
    };

    if(solve_board(board, 0, 0)) {
        printf("The Sudoku puzzle has been solved:\n");
        print_board(board);
    }
    else {
        printf("The Sudoku puzzle cannot be solved.\n");
    }

    return 0;
}