//FormAI DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

bool is_valid(int puzzle[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[i][col] == num) {
            return false;
        }
    }
    // Check 3x3 box
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }
    // If all checks pass, the number is valid
    return true;
}

bool solve(int puzzle[SIZE][SIZE]) {
    int row = -1;
    int col = -1;
    bool is_empty = true;

    // Check if puzzle is solved
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 0) {
                row = i;
                col = j;
                is_empty = false;
                break;
            }
        }
        if (!is_empty) {
            break;
        }
    }
    if (is_empty) {
        return true;
    }

    // Try numbers 1-9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            if (solve(puzzle)) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }
    return false;
}

void print_puzzle(int puzzle[SIZE][SIZE]) {
    printf("-------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", puzzle[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------\n");
        }
    }
}

int main() {
    int puzzle[SIZE][SIZE] = {
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {7, 8, 0, 0, 0, 0, 0, 3, 1},
        {0, 0, 0, 2, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Original puzzle:\n");
    print_puzzle(puzzle);

    if (solve(puzzle)) {
        printf("Solved puzzle:\n");
        print_puzzle(puzzle);
    } else {
        printf("Puzzle could not be solved.\n");
    }

    return 0;
}