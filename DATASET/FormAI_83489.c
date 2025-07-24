//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE];

// Function to print the current state of the board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the current number is safe to assign to a particular cell
int is_safe(int row, int col, int num) {
    // Check if the number is already assigned in the row or column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    // Check if the number is already assigned in the sub-grid
    int subgrid_row = row - (row % 3);
    int subgrid_col = col - (col % 3);
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    // If all checks pass, return 1
    return 1;
}

// Function to solve the Sudoku
int solve_sudoku(int row, int col) {
    // If we have reached the last column, move to the next row
    if (col == BOARD_SIZE) {
        col = 0;
        row++;

        // If we have reached the last row, we have solved the Sudoku
        if (row == BOARD_SIZE) {
            return 1;
        }
    }

    // If the cell is already filled, move to the next cell
    if (board[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }

    // Try out each number and backtrack if necessary
    for (int num = 1; num <= BOARD_SIZE; num++) {
        if (is_safe(row, col, num)) {
            board[row][col] = num;

            if (solve_sudoku(row, col + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    // If no number works, backtrack
    return 0;
}

int main() {
    // Sample Sudoku board
    int sample[9][9] = {
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

    // Copy sample board to the actual board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = sample[i][j];
        }
    }

    printf("Original Sudoku Board:\n");
    print_board();

    // Solve the Sudoku
    if (solve_sudoku(0, 0)) {
        printf("Solved Sudoku Board:\n");
        print_board();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}