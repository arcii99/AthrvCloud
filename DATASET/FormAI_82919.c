//FormAI DATASET v1.0 Category: Sudoku solver ; Style: funny
#include <stdio.h>
#include <stdbool.h>

bool is_empty(int row, int col, int grid[9][9]) {
    return grid[row][col] == 0;
}

bool is_valid(int row, int col, int num, int grid[9][9]) {
    // check row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    // check column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    // check subgrid
    int sub_row = row - row % 3;
    int sub_col = col - col % 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int grid[9][9]) {
    int row, col;
    bool found = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (is_empty(row, col, grid)) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(row, col, num, grid)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[9][9] = {
        {0, 0, 0, 9, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 3, 0, 0},
        {5, 0, 0, 0, 0, 8, 0, 4, 0},
        {1, 0, 0, 0, 5, 4, 0, 7, 0},
        {9, 6, 0, 0, 0, 0, 0, 8, 5},
        {0, 7, 0, 8, 6, 0, 0, 0, 2},
        {0, 5, 0, 4, 0, 0, 0, 0, 7},
        {0, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 0}
    };

    printf("Let's solve this Sudoku puzzle!\n");

    if (solve_sudoku(grid)) {
        printf("Ta-dah! The solution is:\n");
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                printf("%d ", grid[row][col]);
            }
            printf("\n");
        }
    } else {
        printf("Oh no! I couldn't solve this Sudoku puzzle.\n");
    }

    printf("Don't worry, I'll keep trying until I find a solution!\n");

    return 0;
}