//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>

// Function to check if placing a value in a particular position is valid
int is_valid(int puzzle[9][9], int row, int col, int value) {
    // Check if value exists in row
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == value) {
            return 0;
        }
    }
    // Check if value exists in column
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == value) {
            return 0;
        }
    }
    // Check if value exists in 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (puzzle[i][j] == value) {
                return 0;
            }
        }
    }
    // If value passes all checks, return 1
    return 1;
}

// Function to solve the puzzle
int solve(int puzzle[9][9], int row, int col) {
    // Check if we have reached the end of the puzzle
    if (row == 9) {
        return 1;
    }
    // Check if we have reached the end of a row
    if (col == 9) {
        return solve(puzzle, row+1, 0);
    }
    // Check if the current spot is already filled
    if (puzzle[row][col] != 0) {
        return solve(puzzle, row, col+1);
    }
    // Try placing values in the current spot
    for (int i = 1; i <= 9; i++) {
        if (is_valid(puzzle, row, col, i)) {
            puzzle[row][col] = i;
            if (solve(puzzle, row, col+1)) {
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    // If no values work, return 0
    return 0;
}

int main() {
    // Initialize puzzle
    int puzzle[9][9] = {
        {0, 0, 0, 0, 3, 0, 0, 6, 0},
        {0, 0, 7, 0, 0, 0, 0, 4, 8},
        {0, 0, 0, 8, 0, 4, 0, 0, 0},
        {0, 0, 5, 0, 7, 0, 0, 8, 0},
        {0, 0, 4, 0, 2, 0, 7, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 5},
        {0, 9, 0, 0, 0, 0, 5, 0, 3},
        {4, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 0}
    };
    // Print original puzzle
    printf("Original Puzzle:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
    // Solve the puzzle
    solve(puzzle, 0, 0);
    // Print solved puzzle
    printf("Solved Puzzle:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
    return 0;
}