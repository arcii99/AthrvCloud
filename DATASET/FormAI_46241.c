//FormAI DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

void print_grid(int grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int grid[][GRID_SIZE], int row, int col, int num) {
    // Check the row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check the 3x3 box
    int box_x = row - row % 3;
    int box_y = col - col % 3;

    for (int i = box_x; i < box_x + 3; i++) {
        for (int j = box_y; j < box_y + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_grid(int grid[][GRID_SIZE]) {
    int row, col;

    // Check if the grid is already solved
    bool is_solved = true;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                is_solved = false;
                row = i;
                col = j;
                break;
            }
        }
        if (!is_solved) {
            break;
        }
    }

    if (is_solved) {
        return true;
    }

    // Try each number in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve_grid(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Unsolved Grid:\n");
    print_grid(grid);

    if (solve_grid(grid)) {
        printf("Solved Grid:\n");
        print_grid(grid);
    } else {
        printf("Could not solve the grid.\n");
    }

    return 0;
}