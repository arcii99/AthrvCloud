//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Helper function to print the sudoku puzzle
void print_puzzle(int puzzle[SIZE][SIZE]) {
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Helper function to check if a number is valid at certain position
bool is_valid_number(int puzzle[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for(int j=0; j<SIZE; j++) {
        if(puzzle[row][j] == num) {
            return false;
        }
    }

    // Check column
    for(int i=0; i<SIZE; i++) {
        if(puzzle[i][col] == num) {
            return false;
        }
    }

    // Check sub-grid
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(puzzle[start_row+i][start_col+j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Main recursive function to solve the sudoku puzzle
bool solve_sudoku(int puzzle[SIZE][SIZE], int row, int col) {
    // Check if we have reached the end of the puzzle
    if(row == SIZE) {
        return true;
    }

    // Move to next row if current row is complete
    if(col == SIZE) {
        return solve_sudoku(puzzle, row+1, 0);
    }

    // Skip the cell if it is already filled with a number
    if(puzzle[row][col] != 0) {
        return solve_sudoku(puzzle, row, col+1);
    }

    // Try all numbers from 1 to 9 for the current position
    for(int num=1; num<=9; num++) {
        if(is_valid_number(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            // Recursively solve the puzzle
            if(solve_sudoku(puzzle, row, col+1)) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }

    return false;
}

int main() {
    // Define the puzzle to solve
    int puzzle[SIZE][SIZE] = {
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

    // Solve the puzzle
    if(solve_sudoku(puzzle, 0, 0)) {
        printf("Solution:\n");
        print_puzzle(puzzle);
    } else {
        printf("No solution found\n");
    }

    return 0;
}