//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>

#define ROWS 9
#define COLS 9
#define EMPTY 0

int grid[ROWS][COLS];

int find_empty(int *row, int *col) {
    for (*row = 0; *row < ROWS; (*row)++) {
        for (*col = 0; *col < COLS; (*col)++) {
            if (grid[*row][*col] == EMPTY) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int num, int row, int col) {
    // check row
    for (int i = 0; i < COLS; i++) {
        if (grid[row][i] == num && i != col) {
            return 0;
        }
    }
    
    // check column
    for (int i = 0; i < ROWS; i++) {
        if (grid[i][col] == num && i != row) {
            return 0;
        }
    }
    
    // check square
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (grid[i][j] == num && (i != row || j != col)) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solve() {
    int row, col;
    if (!find_empty(&row, &col)) {
        return 1;
    }
    
    for (int i = 1; i <= 9; i++) {
        if (is_valid(i, row, col)) {
            grid[row][col] = i;
            if (solve()) {
                return 1;
            }
            grid[row][col] = EMPTY;
        }
    }
    return 0;
}

void print_grid() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // initialize the grid with test problem
    int problem_grid[ROWS][COLS] = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = problem_grid[i][j];
        }
    }
    
    printf("Original problem:\n");
    print_grid();
    
    if (solve()) {
        printf("Solution:\n");
        print_grid();
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}