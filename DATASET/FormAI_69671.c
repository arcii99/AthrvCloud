//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int puzzle[SIZE][SIZE] = {
    {0, 0, 0, 6, 0, 4, 0, 0, 0},
    {7, 0, 0, 0, 0, 0, 3, 9, 0},
    {8, 0, 0, 0, 0, 0, 0, 4, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 5, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 8, 0},
    {0, 0, 0, 4, 0, 0, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

bool is_valid(int row, int col, int num) {
    // check row
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num) {
            return false;
        }
    }

    // check column
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[i][col] == num) {
            return false;
        }
    }

    // check 3x3 subgrid
    int subrow = row - row % 3;
    int subcol = col - col % 3;
    for (int i = subrow; i < subrow + 3; i++) {
        for (int j = subcol; j < subcol + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool find_empty(int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (puzzle[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve() {
    int row, col;
    if (!find_empty(&row, &col)) {
        return true;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(row, col, num)) {
            puzzle[row][col] = num;
            if (solve()) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }

    return false;
}

void print_puzzle() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("Initial puzzle:\n");
    print_puzzle();

    if (solve()) {
        printf("\nSolution:\n");
        print_puzzle();
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}