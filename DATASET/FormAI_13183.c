//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>

// function to check if a number is valid in a Sudoku puzzle
int isValid(int puzzle[][9], int row, int col, int num) {
    // check row for existing num
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == num) {
            return 0; // not valid
        }
    }

    // check column for existing num
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == num) {
            return 0; // not valid
        }
    }

    // check box for existing num
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0; // not valid
            }
        }
    }

    return 1; // valid
}

// function to solve a Sudoku puzzle
int solveSudoku(int puzzle[][9], int row, int col) {
    // check if we have reached the end of the puzzle
    if (row == 9) {
        return 1; // solved
    }

    // calculate next row and column values
    int next_row = col == 8 ? row + 1 : row;
    int next_col = col == 8 ? 0 : col + 1;

    // if current cell is already filled, move on to next cell
    if (puzzle[row][col] != 0) {
        return solveSudoku(puzzle, next_row, next_col);
    }

    // try filling the cell with each number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isValid(puzzle, row, col, num)) {
            // set current cell to num
            puzzle[row][col] = num;

            // recursively check if this leads to a solution
            if (solveSudoku(puzzle, next_row, next_col)) {
                return 1; // solved
            }

            // if it doesn't lead to a solution, backtrack
            puzzle[row][col] = 0;
        }
    }

    return 0; // unsolvable
}

// function to print a Sudoku puzzle
void printSudoku(int puzzle[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int puzzle[9][9] = {
        {0, 0, 0, 0, 5, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 6, 0, 3, 0, 8, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 2, 4, 0, 0, 0, 0, 7},
        {6, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 6, 7, 0, 0, 0, 0, 2}
    };

    printf("Original Puzzle:\n");
    printSudoku(puzzle);
    printf("\n");

    if (solveSudoku(puzzle, 0, 0)) {
        printf("Solution Found:\n");
        printSudoku(puzzle);
    } else {
        printf("Puzzle is unsolvable.\n");
    }

    return 0;
}