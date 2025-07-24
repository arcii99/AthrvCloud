//FormAI DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>
#include <stdbool.h> // for bool data type

// helper function to print the Sudoku puzzle
void print_puzzle(int puzzle[9][9]) {
    printf("-------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
            if (j % 3 == 2) {
                printf("| ");
            }
        }
        printf("\n");
        if (i % 3 == 2) {
            printf("-------------------------\n");
        }
    }
}

// helper function to check if a number can be placed in a given cell
bool is_valid(int puzzle[9][9], int row, int col, int num) {
    // check if the number already exists in the same row
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == num) {
            return false;
        }
    }
    // check if the number already exists in the same column
    for (int j = 0; j < 9; j++) {
        if (puzzle[j][col] == num) {
            return false;
        }
    }
    // check if the number already exists in the same 3x3 box
    int box_row = row / 3 * 3;
    int box_col = col / 3 * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }
    // if the number can be placed in the cell without violating Sudoku rules
    return true;
}

// Sudoku solver function
bool solve_sudoku(int puzzle[9][9], int row, int col) {
    // go to the next row if all columns are filled in the current row
    if (col == 9) {
        col = 0;
        row++;
    }
    // base case: if all rows are filled, the puzzle is solved
    if (row == 9) {
        return true;
    }
    // if the cell is already filled, move to the next cell
    if (puzzle[row][col] != 0) {
        return solve_sudoku(puzzle, row, col + 1);
    }
    // try to place numbers 1 to 9 in the cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            // recursively solve the rest of the puzzle
            if (solve_sudoku(puzzle, row, col + 1)) {
                return true;
            }
            puzzle[row][col] = 0; // backtrack if the current choice is not valid
        }
    }
    // if no number can be placed in the cell without violating Sudoku rules
    return false;
}

int main() {
    printf("Welcome to the cheerful Sudoku solver!\n\n");
    int puzzle[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    printf("The original puzzle is:\n");
    print_puzzle(puzzle);
    printf("\nSolving the puzzle...\n");
    if (solve_sudoku(puzzle, 0, 0)) {
        printf("\nDone! The solution is:\n");
        print_puzzle(puzzle);
    } else {
        printf("\nOops, cannot solve the puzzle!\n");
    }
    return 0;
}