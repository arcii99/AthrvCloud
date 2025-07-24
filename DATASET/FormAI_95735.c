//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define N 9

int puzzle[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 0, 0, 0, 2, 0},
    {9, 0, 0, 8, 0, 0, 0, 0, 5},
    {0, 5, 0, 0, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

bool check_row(int row, int num) {
    for (int col = 0; col < N; col++) {
        if (puzzle[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool check_column(int col, int num) {
    for (int row = 0; row < N; row++) {
        if (puzzle[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool check_box(int start_row, int start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (puzzle[row + start_row][col + start_col] == num) {
                return true;
            }
        }
    }
    return false;
}

void print_puzzle() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
}

bool find_empty_cell(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (puzzle[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve_puzzle() {
    int row, col;
    if (!find_empty_cell(&row, &col)) {
        return true; // Puzzle is solved!
    }

    for (int num = 1; num <= 9; num++) {
        if (!check_row(row, num) && !check_column(col, num) && !check_box(row - row % 3, col - col % 3, num)) {
            puzzle[row][col] = num;

            if (solve_puzzle()) {
                return true;
            }

            puzzle[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    printf("Sudoku Puzzle:\n");
    print_puzzle();

    if (solve_puzzle()) {
        printf("Solution:\n");
        print_puzzle();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}