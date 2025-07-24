//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

// Function to check if current guess is valid in row, column and 3x3 box
int is_valid(int board[9][9], int row, int col, int guess) {

    // Check row
    for(int i=0; i<9; i++) {
        if(board[row][i] == guess) {
            return 0;
        }
    }

    // Check column
    for(int i=0; i<9; i++) {
        if(board[i][col] == guess) {
            return 0;
        }
    }

    // Check 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for(int i=box_row*3; i<(box_row+1)*3; i++) {
        for(int j=box_col*3; j<(box_col+1)*3; j++) {
            if(board[i][j] == guess) {
                return 0;
            }
        }
    }

    // If guess is valid, return 1
    return 1;
}

// Function to solve the sudoku board using backtracking
int solve_sudoku(int board[9][9], int row, int col) {

    // If reached the end of column, move to the next row
    if(col == 9) {
        row++;
        col = 0;
    }

    // If reached end of board, it is a solution
    if(row == 9) {
        return 1;
    }

    // Skip cells that already have a value in them
    if(board[row][col] != 0) {
        return solve_sudoku(board, row, col+1);
    }

    // Iterate through all possible guesses and check if valid
    for(int guess=1; guess<=9; guess++) {
        if(is_valid(board, row, col, guess)) {
            board[row][col] = guess;
            if(solve_sudoku(board, row, col+1)) {
                return 1;
            }
        }
    }

    // If no valid guess found, backtrack and set current cell to 0
    board[row][col] = 0;
    return 0;
}

// Function to print the sudoku board
void print_board(int board[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define the sudoku board to solve
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

    // Print the unsolved board
    printf("Unsolved sudoku board: \n");
    print_board(board);

    // Solve the board
    solve_sudoku(board, 0, 0);

    // Print the solved board
    printf("\nSolved sudoku board: \n");
    print_board(board);

    return 0;
}