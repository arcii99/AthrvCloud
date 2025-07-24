//FormAI DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>

// Initialize the Sudoku board
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

// Function to print the Sudoku board
void print_board() {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}


// Function to check if a number can be placed in a particular position on the board
int can_place(int num, int row, int col) {
    int i, j;

    // Check if the number is already in the row
    for (i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check if the number is already in the column
    for (j = 0; j < 9; j++) {
        if (board[j][col] == num) {
            return 0;
        }
    }

    // Check if the number is already in the 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    // If the number can be placed in this position, return 1
    // Otherwise, return 0
    return 1;
}


// Function to solve the Sudoku puzzle recursively
int solve(int row, int col) {
    // Check if we have reached the end of the board
    if (row == 8 && col == 9) {
        return 1;
    }

    // Check if we have reached the end of the row
    if (col == 9) {
        row++;
        col = 0;
    }

    // Check if this position is already filled
    if (board[row][col] > 0) {
        return solve(row, col+1);
    }

    int num;

    // Try all possible numbers in this position
    for (num = 1; num <= 9; num++) {
        if (can_place(num, row, col)) {
            board[row][col] = num;

            if (solve(row, col+1)) {
                return 1;
            }
        }

        board[row][col] = 0;
    }

    // If we cannot find a valid number for this position, return 0
    return 0;
}


int main() {
    // Print the initial board
    printf("Original Board:\n");
    print_board();

    // Solve the board
    if (solve(0, 0)) {
        printf("\nSolved Board:\n");
        print_board();
    } else {
        printf("\nThere is no solution.\n");
    }

    return 0;
}