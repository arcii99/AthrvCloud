//FormAI DATASET v1.0 Category: Sudoku solver ; Style: synchronous
/**
 * Program to solve a Sudoku board using backtracking in a synchronous style
 **/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int puzzle[SIZE][SIZE];

/**
 * Function to print the Sudoku board
 **/
void print_board() {
    int row, col;
    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Function to check if a number is valid to be placed at a particular position in the Sudoku board
 **/
bool valid_number(int num, int row, int col) {
    int i, j;
    // Check row and column for duplicates
    for(i = 0; i < SIZE; i++) {
        if(puzzle[row][i] == num || puzzle[i][col] == num) {
            return false;
        }
    }
    // Check for duplicates in the box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for(i = box_row; i < box_row + 3; i++) {
        for(j = box_col; j < box_col + 3; j++) {
            if(puzzle[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Function to solve the Sudoku board using backtracking in a synchronous style
 **/
bool solve_sudoku(int row, int col) {
    // Base case: end of puzzle
    if(row == SIZE && col == 0) {
        return true;
    }
    // If we reached end of row, move to the next row
    if(col == SIZE) {
        row++;
        col = 0;
    }
    // If the cell is not empty, move to the next cell
    if(puzzle[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }
    // Try to fill the empty cell with a valid number
    int i;
    for(i = 1; i <= SIZE; i++) {
        if(valid_number(i, row, col)) {
            puzzle[row][col] = i;
            if(solve_sudoku(row, col + 1)) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Sample Sudoku puzzle
    int board[SIZE][SIZE] = {
        {6, 0, 0, 0, 1, 0, 4, 9, 0},
        {0, 2, 0, 9, 0, 4, 0, 5, 0},
        {1, 0, 0, 0, 0, 0, 7, 0, 6},
        {0, 0, 5, 0, 0, 8, 0, 1, 0},
        {3, 0, 0, 5, 0, 9, 0, 0, 4},
        {0, 9, 0, 7, 0, 0, 2, 0, 0},
        {7, 0, 9, 0, 0, 0, 0, 0, 2},
        {0, 4, 0, 8, 0, 6, 0, 3, 0},
        {0, 3, 2, 0, 7, 0, 0, 0, 5}
    };
    // Copy the sample puzzle to the puzzle variable
    int row, col;
    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            puzzle[row][col] = board[row][col];
        }
    }
    printf("Sudoku puzzle:\n");
    print_board();
    bool solved = solve_sudoku(0, 0);
    if(solved) {
        printf("Solved Sudoku board:\n");
        print_board();
    } else {
        printf("Could not solve the Sudoku board.\n");
    }
    return 0;
}