//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>

#define GRID_SIZE 9

void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int i, j;
    printf("-------------------\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
            if ((j + 1) % 3 == 0) printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0) printf("-------------------\n");
    }
}

int find_unassigned_cell(int grid[GRID_SIZE][GRID_SIZE], int *row, int *col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) return 1;
        }
    }
    return 0;
}

int is_valid_number(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) return 0;
        if (grid[i][col] == num) return 0;
    }
    int box_row_start = row - row % 3;
    int box_col_start = col - col % 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[box_row_start + i][box_col_start + j] == num) return 0;
        }
    }
    return 1;
}

int solve_sudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    if (!find_unassigned_cell(grid, &row, &col)) return 1;
    int num;
    for (num = 1; num <= 9; num++) {
        if (is_valid_number(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {{0, 0, 0, 5, 4, 0, 2, 0, 0},
                                      {5, 6, 0, 0, 8, 1, 0, 3, 0},
                                      {0, 0, 0, 0, 0, 0, 9, 1, 0},
                                      {9, 0, 7, 0, 0, 0, 0, 8, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 0, 7},
                                      {0, 9, 8, 0, 0, 0, 0, 0, 0},
                                      {0, 2, 0, 8, 1, 0, 0, 7, 9},
                                      {0, 0, 6, 0, 7, 3, 0, 0, 0}};
    print_grid(grid);
    if (solve_sudoku(grid)) {
        printf("Solved Sudoku:\n");
        print_grid(grid);
    } else {
        printf("Couldn't solve sudoku.\n");
    }
    return 0;
}