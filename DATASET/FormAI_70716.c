//FormAI DATASET v1.0 Category: Sudoku solver ; Style: unmistakable
#include <stdio.h>

#define SIZE 9

int is_possible(int puzzle[][SIZE], int row, int col, int num) {
    // check row
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num) {
            return 0;
        }
    }

    // check column
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[i][col] == num) {
            return 0;
        }
    }

    // check square
    int square_row = (row / 3) * 3;
    int square_col = (col / 3) * 3;
    for (int i = square_row; i < square_row + 3; i++) {
        for (int j = square_col; j < square_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int puzzle[][SIZE], int row, int col) {
    if (row == SIZE && col == 0) {
        // solved the puzzle
        return 1;
    }

    if (puzzle[row][col] == 0) {
        // find possible numbers for current cell
        for (int i = 1; i <= SIZE; i++) {
            if (is_possible(puzzle, row, col, i)) {
                puzzle[row][col] = i;
                // move to next cell
                if (col == SIZE - 1) {
                    if (solve_sudoku(puzzle, row + 1, 0)) {
                        return 1;
                    }
                } else {
                    if (solve_sudoku(puzzle, row, col + 1)) {
                        return 1;
                    }
                }
            }
        }
        // couldn't find valid number, backtrack
        puzzle[row][col] = 0;
    } else {
        // move to next cell
        if (col == SIZE - 1) {
            if (solve_sudoku(puzzle, row + 1, 0)) {
                return 1;
            }
        } else {
            if (solve_sudoku(puzzle, row, col + 1)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int puzzle[SIZE][SIZE] = {
        {0, 0, 0, 5, 0, 4, 7, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 5},
        {0, 6, 2, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 6, 0, 0, 0, 2},
        {0, 0, 7, 0, 0, 0, 8, 0, 0},
        {1, 0, 0, 0, 8, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 5, 9, 0},
        {8, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 7, 0, 0, 0}
    };

    printf("Unsolved Puzzle:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }

    // solve puzzle
    if (solve_sudoku(puzzle, 0, 0)) {
        printf("\nSolved Puzzle:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", puzzle[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Unable to solve puzzle.");
    }

    return 0;
}