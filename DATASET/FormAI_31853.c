//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Helper function to print the sudoku board
void print_sudoku(int sudoku[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Helper function to check if a number is valid for the given position in the sudoku board
bool is_valid(int sudoku[SIZE][SIZE], int row, int col, int num) {
    // Check if the number exists in the same row or column
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return false;
        }
    }
    // Check if the number exists in the same 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// The main function to solve the sudoku
bool solve_sudoku(int sudoku[SIZE][SIZE]) {
    int row = -1;
    int col = -1;
    bool found_empty = false;
    // Find the next empty cell in the sudoku
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudoku[i][j] == 0) {
                row = i;
                col = j;
                found_empty = true;
                break;
            }
        }
        if (found_empty) {
            break;
        }
    }
    // If there are no empty cells left, the sudoku is solved
    if (!found_empty) {
        return true;
    }
    // Try all possible numbers in the empty cell
    for (int i = 1; i <= 9; i++) {
        if (is_valid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solve_sudoku(sudoku)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    // If no number works, backtrack
    return false;
}

int main() {
    int sudoku[SIZE][SIZE] = {
        {0, 0, 0, 0, 8, 0, 3, 2, 0},
        {1, 0, 0, 0, 0, 9, 0, 0, 0},
        {9, 0, 3, 0, 7, 0, 0, 6, 0},
        {6, 4, 8, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 3, 0, 7, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 9, 5},
        {0, 3, 0, 0, 2, 0, 8, 0, 9},
        {0, 0, 0, 7, 0, 0, 0, 0, 4},
        {0, 9, 1, 0, 3, 0, 0, 0, 0}
    };
    printf("Initial Sudoku:\n");
    print_sudoku(sudoku);
    if (solve_sudoku(sudoku)) {
        printf("Sudoku solved:\n");
        print_sudoku(sudoku);
    } else {
        printf("Sudoku could not be solved\n");
    }
    return 0;
}