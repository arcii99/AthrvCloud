//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size
#define ROWS 8
#define COLS 8

// Function to print the current state of the board
void printBoard(int board[][COLS]) {
    printf("\n\n\n");
    printf("   A B C D E F G H\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("|Q");
            } else {
                printf("| ");
            }

            if (j == COLS-1) {
                printf("|\n");
            }
        }
    }
}

// Function to check if the current board is conflict-free
int isValid(int board[][COLS], int row, int col) {
    int i, j;

    // Check the row for any conflicts
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return 0;
        }
    }

    // Check the upper diagonal for any conflicts
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // Check the lower diagonal for any conflicts
    for (i = row, j = col; j >= 0 && i < ROWS; i++, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

// Function to solve the n-queens problem
int solve(int board[][COLS], int col) {
    // Base case: all queens have been placed
    if (col >= COLS) {
        return 1;
    }

    // Check each row in the current column
    for (int i = 0; i < ROWS; i++) {
        // Check if placing a queen in this row is valid
        if (isValid(board, i, col)) {
            // Place the queen in this cell
            board[i][col] = 1;

            // Recursively solve for the next column
            if (solve(board, col+1)) {
                return 1;
            }

            // Backtrack if the next column cannot be solved
            board[i][col] = 0;
        }
    }

    // Return 0 if the problem cannot be solved
    return 0;
}

int main() {
    int board[ROWS][COLS] = {0};
    if (solve(board, 0)) {
        printf("Solution found!\n");
        printBoard(board);
    } else {
        printf("Solution not found.\n");
    }
    return 0;
}