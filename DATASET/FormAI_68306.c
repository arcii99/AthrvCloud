//FormAI DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>

// function to check if a number is a valid candidate for a cell in the Sudoku puzzle
int is_valid(int puzzle[9][9], int row, int col, int num) {
    // check if the number exists in the same row or column
    for(int i = 0; i < 9; i++) {
        if(puzzle[row][i] == num || puzzle[i][col] == num)
            return 0;
    }
    // check if number exists in the same 3x3 box
    int box_row = (row/3) * 3;
    int box_col = (col/3) * 3;
    for(int i = box_row; i < box_row + 3; i++) {
        for(int j = box_col; j < box_col + 3; j++) {
            if(puzzle[i][j] == num)
                return 0;
        }
    }
    // if all conditions pass, return 1
    return 1;
}

// recursive function to solve the Sudoku puzzle
int solve_sudoku(int puzzle[9][9], int row, int col) {
    // if current row and column are at the end of the puzzle,
    // the puzzle is solved and we return 1
    if(row == 8 && col == 9)
        return 1;
    // if current column is at the end of the row,
    // move to the next row
    if(col == 9) {
        row++;
        col = 0;    
    }
    // if the current cell is not empty, move to the next cell
    if(puzzle[row][col] != 0)
        return solve_sudoku(puzzle, row, col+1);
    // if the current cell is empty, try filling it with numbers
    for(int i = 1; i <= 9; i++) {
        if(is_valid(puzzle, row, col, i)) {
            puzzle[row][col] = i;
            if(solve_sudoku(puzzle, row, col+1))
                return 1;
            puzzle[row][col] = 0;
        }
    }
    // if all numbers have been tried and none work, backtrack
    return 0;
}

// function to print the solved Sudoku puzzle
void print_puzzle(int puzzle[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++)
            printf("%d ", puzzle[i][j]);
        printf("\n");
    }
}

int main() {
    int puzzle[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    if(solve_sudoku(puzzle, 0, 0) == 1)
        print_puzzle(puzzle);
    else
        printf("Unable to solve Sudoku puzzle!");
    return 0;
}