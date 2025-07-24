//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the size of the Sudoku board
#define SIZE 9

// Function for printing the Sudoku board
void print_board(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function for checking if a value can be placed in a specific cell
int is_valid(int board[][SIZE], int row, int col, int value) {
    // Check if value already exists in row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }
    // Check if value already exists in column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }
    // Check if value already exists in 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }
    // Value can be placed in cell
    return 1;
}

// Function for solving the Sudoku board recursively
int solve_board(int board[][SIZE], int row, int col) {
    // Base case: end of board reached
    if (row == SIZE - 1 && col == SIZE) {
        return 1;
    }
    // Move to next row if current row is filled
    if (col == SIZE) {
        row++;
        col = 0;
    }
    // Check if current cell is already filled
    if (board[row][col] != 0) {
        return solve_board(board, row, col + 1);
    }
    // Try filling current cell with all numbers between 1 and 9
    for (int value = 1; value <= SIZE; value++) {
        // Check if number can be placed in current cell
        if (is_valid(board, row, col, value)) {
            board[row][col] = value;
            // Move to next cell recursively
            if (solve_board(board, row, col + 1)) {
                return 1;
            }
            // Backtrack if solution not found
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Define initial Sudoku board
    int board[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    // Call solve_board function and print solved board
    if (solve_board(board, 0, 0)) {
        printf("Solved Sudoku board:\n");
        print_board(board);
    } else {
        printf("No solution found for Sudoku board.\n");
    }
    return 0;
}