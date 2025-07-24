//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>

// Define the size of the Sudoku board
#define BOARD_SIZE 9

// Helper function to print the Sudoku board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------\n");
        }
    }
}

// Helper function to check if a potential move is valid
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int move) {
    // Check if the move is present in the same row or column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == move || board[i][col] == move) {
            return 0;
        }
    }

    // Check if the move is present in the same 3x3 square
    int square_row = row - (row % 3);
    int square_col = col - (col % 3);
    for (int i = square_row; i < square_row + 3; i++) {
        for (int j = square_col; j < square_col + 3; j++) {
            if (board[i][j] == move) {
                return 0;
            }
        }
    }

    // If the move is valid, return 1
    return 1;
}

// Main solver function using backtracking
int solve_board(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    // Check if we have reached the end of the board
    if (row == BOARD_SIZE) {
        print_board(board);
        return 1;
    }

    // Check if we have filled up the current row and need to move to the next
    if (col == BOARD_SIZE) {
        return solve_board(board, row + 1, 0);
    }

    // Check if the current cell is empty and try all possible moves
    if (board[row][col] == 0) {
        for (int move = 1; move <= BOARD_SIZE; move++) {
            // Check if the move is valid
            if (is_valid_move(board, row, col, move)) {
                // Try the current move
                board[row][col] = move;
                // Move on to the next cell in the row
                if (solve_board(board, row, col + 1)) {
                    return 1;
                }
                // Backtrack if the current move did not lead to a solution
                board[row][col] = 0;
            }
        }
    } else {
        // If the current cell is not empty, move on to the next cell in the row
        return solve_board(board, row, col + 1);
    }

    // If no moves are valid, return 0
    return 0;
}

int main() {
    // Define the Sudoku board
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 8, 0, 0, 0, 2},
        {0, 0, 0, 6, 0, 5, 0, 0, 7},
        {5, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 4, 0, 9, 0, 3, 0, 0},
        {0, 0, 8, 0, 0, 0, 0, 0, 6},
        {8, 0, 0, 0, 0, 6, 0, 9, 0},
        {9, 0, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 4, 0}
    };

    printf("Solving Sudoku puzzle:\n");
    print_board(board);

    printf("\nSolution:\n");
    solve_board(board, 0, 0);

    return 0;
}