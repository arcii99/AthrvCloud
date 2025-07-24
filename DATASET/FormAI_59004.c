//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

void print_grid() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    // Check if number is already in row or column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check if number is already in 3x3 subgrid
    int subgrid_row = row - (row % 3);
    int subgrid_col = col - (col % 3);
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(row, col, num)) {
                        grid[row][col] = num;
                        if (solve()) {
                            return 1;
                        }
                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Input sudoku puzzle here
    grid[0][0] = 5;
    grid[0][1] = 3;
    grid[0][4] = 7;
    grid[1][0] = 6;
    grid[1][3] = 1;
    grid[1][4] = 9;
    grid[1][5] = 5;
    grid[2][1] = 9;
    grid[2][2] = 8;
    grid[2][7] = 6;
    grid[3][0] = 8;
    grid[3][4] = 6;
    grid[3][8] = 3;
    grid[4][0] = 4;
    grid[4][3] = 8;
    grid[4][5] = 3;
    grid[4][8] = 1;
    grid[5][0] = 7;
    grid[5][4] = 2;
    grid[5][8] = 6;
    grid[6][1] = 6;
    grid[6][6] = 2;
    grid[6][7] = 8;
    grid[7][3] = 4;
    grid[7][4] = 1;
    grid[7][5] = 9;
    grid[7][8] = 5;
    grid[8][4] = 8;
    grid[8][7] = 7;
    grid[8][8] = 9;

    printf("Sudoku puzzle:\n");
    print_grid();

    if (solve()) {
        printf("\nSolution:\n");
        print_grid();
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}