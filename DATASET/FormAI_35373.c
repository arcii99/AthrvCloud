//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Alan Touring
#include <stdio.h>

#define N 9

// check if the given digit is safe to use in the given row, column or box.
int isSafe(int puzzle[N][N], int row, int col, int digit) {
    int i, j;
    for (i = 0; i < N; i++) {
        // check for row
        if (puzzle[row][i] == digit)
            return 0;
        // check for column
        if (puzzle[i][col] == digit)
            return 0;
    }
    // check for box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (i = boxRowStart; i < boxRowStart + 3; i++) {
        for (j = boxColStart; j < boxColStart + 3; j++) {
            if (puzzle[i][j] == digit)
                return 0;
        }
    }
    // digit is safe to use
    return 1;
}

// recursive function to solve the puzzle
int solve(int puzzle[N][N], int row, int col) {
    // if all cells are filled, puzzle is solved
    if (row == N - 1 && col == N)
        return 1;
    // if current column has been filled, move to next row
    if (col == N) {
        row++;
        col = 0;
    }
    // if current cell is already filled, move to next cell
    if (puzzle[row][col] != 0)
        return solve(puzzle, row, col + 1);
    int digit;
    for (digit = 1; digit <= N; digit++) {
        if (isSafe(puzzle, row, col, digit)) {
            puzzle[row][col] = digit;
            if (solve(puzzle, row, col + 1))
                return 1;
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

// function to print the puzzle
void printPuzzle(int puzzle[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int puzzle[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // sample sudoku puzzle
    puzzle[0][1] = 4;
    puzzle[0][2] = 3;
    puzzle[0][4] = 8;
    puzzle[1][2] = 7;
    puzzle[1][3] = 3;
    puzzle[2][0] = 6;
    puzzle[2][4] = 5;
    puzzle[2][5] = 9;
    puzzle[2][8] = 8;
    puzzle[3][2] = 4;
    puzzle[3][5] = 7;
    puzzle[3][6] = 2;
    puzzle[3][8] = 6;
    puzzle[4][0] = 7;
    puzzle[4][2] = 1;
    puzzle[4][6] = 8;
    puzzle[5][0] = 9;
    puzzle[5][2] = 5;
    puzzle[5][3] = 2;
    puzzle[5][6] = 1;
    puzzle[6][0] = 1;
    puzzle[6][3] = 1;
    puzzle[6][4] = 7;
    puzzle[6][8] = 4;
    puzzle[7][0] = 2;
    puzzle[7][1] = 8;
    puzzle[7][5] = 5;
    puzzle[8][4] = 6;
    puzzle[8][5] = 2;
    puzzle[8][6] = 3;
    puzzle[8][7] = 1;

    if (solve(puzzle, 0, 0))
        printPuzzle(puzzle);
    else
        printf("No solution exists.\n");
    return 0;
}