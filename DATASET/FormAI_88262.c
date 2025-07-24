//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define N 9

int puzzle[N][N] = {
    {6, 5, 0, 8, 7, 3, 0, 9, 0},
    {0, 0, 3, 2, 5, 0, 0, 0, 8},
    {9, 8, 0, 1, 0, 4, 3, 5, 7},
    {1, 0, 5, 0, 0, 0, 0, 0, 0},
    {4, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 5, 0, 3},
    {5, 7, 8, 3, 0, 1, 0, 2, 6},
    {2, 0, 0, 0, 4, 0, 0, 0, 0},
    {0, 9, 0, 6, 2, 8, 0, 7, 5}
};

void print_board() {
    printf("+---+---+---+\n");
    for (int i = 0; i < N; i++) {
        printf("| ");
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] == 0) {
                printf("  ");
            } else {
                printf("%d ", puzzle[i][j]);
            }
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("+---+---+---+\n");
        }
    }
}

bool is_valid(int row, int col, int num) {
    // check row
    for (int i = 0; i < N; i++) {
        if (puzzle[row][i] == num) {
            return false;
        }
    }
    // check column
    for (int i = 0; i < N; i++) {
        if (puzzle[i][col] == num) {
            return false;
        }
    }
    // check 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int row, int col) {
    if (col == N) {
        col = 0;
        row++;
        if (row == N) {
            return true;
        }
    }
    if (puzzle[row][col] > 0) {
        return solve(row, col + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (is_valid(row, col, num)) {
            puzzle[row][col] = num;
            if (solve(row, col + 1)) {
                return true;
            }
        }
        puzzle[row][col] = 0;
    }
    return false;
}

int main() {
    printf("Sudoku Puzzle:\n");
    print_board();
    printf("\nSolving...\n\n");
    if (solve(0, 0)) {
        printf("Solution:\n");
        print_board();
    } else {
        printf("No solution found.");
    }
    return 0;
}