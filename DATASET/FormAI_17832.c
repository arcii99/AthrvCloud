//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>

// Define the size of the board
#define BOARD_SIZE 9

// Define an empty spot on the board
#define EMPTY 0

// Define the board
int board[BOARD_SIZE][BOARD_SIZE] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 0, 0, 0, 2, 0},
    {9, 0, 0, 8, 1, 0, 0, 0, 4},
    {0, 4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Print the board
void print_board() {
    printf("+-----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("+-----------------+\n");
        }
    }
}

// Check if a number is valid at a position
int is_valid(int row, int col, int num) {
    // Check if the number is already in the row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check if the number is already in the column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check if the number is already in the box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[box_row + i][box_col + j] == num) {
                return 0;
            }
        }
    }
    // If the number is not already in the row, column, or box, it is valid
    return 1;
}

// Solve the board recursively
int solve_board(int row, int col) {
    // If we have reached the end of the board, return true
    if (row == BOARD_SIZE) {
        return 1;
    }
    // If the spot is not empty, move to the next spot
    if (board[row][col] != EMPTY) {
        if (col == BOARD_SIZE - 1) {
            return solve_board(row + 1, 0);
        }
        return solve_board(row, col + 1);
    }
    // Try each number to see if it is valid
    for (int i = 1; i <= BOARD_SIZE; i++) {
        if (is_valid(row, col, i)) {
            board[row][col] = i;
            if (col == BOARD_SIZE - 1) {
                if (solve_board(row + 1, 0)) {
                    return 1;
                }
            } else {
                if (solve_board(row, col + 1)) {
                    return 1;
                }
            }
        }
    }
    // If no number is valid, backtrack
    board[row][col] = EMPTY;
    return 0;
}

int main() {
    printf("Before:\n");
    print_board();
    if (solve_board(0, 0) == 1) {
        printf("After:\n");
        print_board();
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}