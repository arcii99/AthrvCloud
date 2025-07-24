//FormAI DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// function to print the sudoku puzzle
void print_sudoku(int sudoku[SIZE][SIZE]) {
    printf("=======================\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("=======================\n");
}

// function to check if a number is valid to place in a certain position
bool is_valid(int sudoku[SIZE][SIZE], int row, int col, int num) {
    // check row
    for (int j = 0; j < SIZE; j++) {
        if (sudoku[row][j] == num) {
            return false;
        }
    }
    
    // check column
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[i][col] == num) {
            return false;
        }
    }
    
    // check 3x3 square
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[start_row + i][start_col + j] == num) {
                return false;
            }
        }
    }
    
    // if number is valid to place in the given position, return true
    return true;
}

// recursive function to solve sudoku puzzle
bool solve_sudoku(int sudoku[SIZE][SIZE], int row, int col) {
    // if we have reached the end of the sudoku, return true
    if (row == SIZE && col == SIZE) {
        return true;
    }
    
    // if we have reached the end of a row, move to the next row
    if (col == SIZE) {
        row++;
        col = 0;
    }
    
    // if the current position is already filled, move to the next position
    if (sudoku[row][col] != 0) {
        if (solve_sudoku(sudoku, row, col+1)) {
            return true;
        }
    }
    
    // try all possible numbers in the empty position
    for (int i = 1; i <= SIZE; i++) {
        if (is_valid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solve_sudoku(sudoku, row, col+1)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    
    // if no number in the current position is valid, backtrack
    return false;
}

int main() {
    int sudoku[SIZE][SIZE] = {{0, 0, 0, 0, 9, 0, 0, 1, 5},
                              {6, 0, 0, 8, 0, 0, 3, 0, 0},
                              {0, 0, 0, 6, 0, 4, 0, 0, 0},
                              {0, 7, 0, 1, 2, 0, 4, 0, 0},
                              {0, 4, 0, 0, 0, 0, 0, 5, 0},
                              {0, 0, 5, 0, 7, 8, 0, 9, 0},
                              {0, 0, 0, 3, 0, 2, 0, 0, 0},
                              {0, 0, 7, 0, 0, 9, 0, 0, 8},
                              {5, 3, 0, 0, 8, 0, 0, 0, 0}};
    
    print_sudoku(sudoku);
    
    if (solve_sudoku(sudoku, 0, 0)) {
        printf("Solution:\n");
        print_sudoku(sudoku);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}