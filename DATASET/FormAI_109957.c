//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>

// Size of the sudoku board
#define SIZE 9

// Function to print the sudoku board
void print_board(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a given position of the board
int is_valid(int board[][SIZE], int row, int col, int num) {
    // Check if num is already present in the same row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0; // Invalid move
        }
    }

    // Check if num is already present in the same col
    for (int j = 0; j < SIZE; j++) {
        if (board[j][col] == num) {
            return 0; // Invalid move
        }
    }

    // Check if num is already present in the same 3x3 subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (board[i][j] == num) {
                return 0; // Invalid move
            }
        }
    }

    return 1; // Valid move
}

// Function to solve the sudoku board
int solve_board(int board[][SIZE], int row, int col) {
    // Check if all positions have been filled
    if (row == SIZE) {
        return 1; // Board has been solved
    }

    // Check if we have reached the end of the current row
    if (col == SIZE) {
        return solve_board(board, row + 1, 0); // Move to the next row
    }

    // Check if the current position is already filled
    if (board[row][col] != 0) {
        return solve_board(board, row, col + 1); // Move to the next column
    }

    // Try all possible numbers for the current position
    for (int i = 1; i <= SIZE; i++) {
        // Check if the current number is valid in the current position
        if (is_valid(board, row, col, i)) {
            board[row][col] = i; // Place the number in the current position

            // Recursively solve the rest of the board
            if (solve_board(board, row, col + 1)) {
                return 1; // Board has been solved
            }

            board[row][col] = 0; // Reset the current position if the number is not valid
        }
    }

    return 0; // Board cannot be solved from this position
}

int main() {
    // Example board (0 indicates empty positions)
    int board[SIZE][SIZE] = {
        {0, 2, 0, 0, 0, 0, 0, 6, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 9, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Print the original board
    printf("Original board:\n");
    print_board(board);

    // Solve the board
    if (solve_board(board, 0, 0)) {
        // Print the solved board
        printf("\nSolved board:\n");
        print_board(board);
    } else {
        printf("\nBoard cannot be solved.\n");
    }

    return 0;
}