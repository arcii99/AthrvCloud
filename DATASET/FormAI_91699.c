//FormAI DATASET v1.0 Category: Sudoku solver ; Style: puzzling
// Welcome to the Sudoku solver program!
// This puzzling program will solve any Sudoku puzzle you throw at it.
// Get ready to be amazed as we unlock the secrets of the Sudoku universe.

#include <stdio.h>

// First, we need to define our Sudoku board.
// We'll represent it as a two-dimensional array with 9 rows and 9 columns.

int board[9][9];

// We also need to keep track of whether a cell is fixed or not.
// We'll represent this with another two-dimensional array with the same dimensions.

int fixed[9][9];

// Now, let's define some helper functions.
// These will help us navigate the board and check for errors.

int get_row(int cell) {
    return cell / 9;
}

int get_col(int cell) {
    return cell % 9;
}

int get_box(int cell) {
    int row = get_row(cell);
    int col = get_col(cell);
    return (row / 3) * 3 + (col / 3);
}

int is_valid(int cell, int value) {
    int row = get_row(cell);
    int col = get_col(cell);
    int box = get_box(cell);

    // Check row

    for (int i = 0; i < 9; i++) {
        if (board[row][i] == value && i != col) {
            return 0;
        }
    }

    // Check column

    for (int i = 0; i < 9; i++) {
        if (board[i][col] == value && i != row) {
            return 0;
        }
    }

    // Check box

    int box_row = (box / 3) * 3;
    int box_col = (box % 3) * 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == value && (i != row || j != col)) {
                return 0;
            }
        }
    }

    // If we get here, the value is valid

    return 1;
}

int find_next_empty_cell(int cell) {
    for (int i = cell + 1; i < 81; i++) {
        if (fixed[get_row(i)][get_col(i)] == 0 && board[get_row(i)][get_col(i)] == 0) {
            return i;
        }
    }

    return -1;
}

int solve(int cell) {
    if (cell == -1) {
        // We've filled in all the cells, so the puzzle is solved!
        return 1;
    }

    int row = get_row(cell);
    int col = get_col(cell);

    for (int i = 1; i <= 9; i++) {
        if (is_valid(cell, i)) {
            board[row][col] = i;
            if (solve(find_next_empty_cell(cell))) {
                // We've found a valid solution!
                return 1;
            }
            board[row][col] = 0;
        }
    }

    return 0;
}

// Finally, let's put it all together and solve a puzzle!

int main() {
    // We'll start with a simple puzzle that's missing only one number.
    // Our program should be able to solve this in a jiffy.

    board[0][0] = 4;
    board[0][1] = 3;
    board[0][2] = 5;
    board[0][3] = 2;
    board[0][4] = 6;
    board[0][5] = 9;
    board[0][6] = 7;
    board[0][7] = 8;
    board[0][8] = 1;

    board[1][0] = 6;
    board[1][1] = 8;
    board[1][2] = 2;
    board[1][3] = 5;
    board[1][4] = 7;
    board[1][5] = 1;
    board[1][6] = 4;
    board[1][7] = 9;
    board[1][8] = 3;

    board[2][0] = 1;
    board[2][1] = 9;
    board[2][2] = 7;
    board[2][3] = 8;
    board[2][4] = 3;
    board[2][5] = 4;
    board[2][6] = 5;
    board[2][7] = 6;
    board[2][8] = 2;

    board[3][0] = 8;
    board[3][1] = 2;
    board[3][2] = 6;
    board[3][3] = 1;
    board[3][4] = 9;
    board[3][5] = 5;
    board[3][6] = 3;
    board[3][7] = 4;
    board[3][8] = 7;

    board[4][0] = 3;
    board[4][1] = 7;
    board[4][2] = 4;
    board[4][3] = 6;
    board[4][4] = 8;
    board[4][5] = 2;
    board[4][6] = 9;
    board[4][7] = 1;
    board[4][8] = 5;

    board[5][0] = 9;
    board[5][1] = 5;
    board[5][2] = 1;
    board[5][3] = 7;
    board[5][4] = 4;
    board[5][5] = 3;
    board[5][6] = 6;
    board[5][7] = 2;
    board[5][8] = 8;

    board[6][0] = 5;
    board[6][1] = 1;
    board[6][2] = 9;
    board[6][3] = 3;
    board[6][4] = 2;
    board[6][5] = 6;
    board[6][6] = 8;
    board[6][7] = 7;
    board[6][8] = 4;

    board[7][0] = 2;
    board[7][1] = 4;
    board[7][2] = 8;
    board[7][3] = 9;
    board[7][4] = 5;
    board[7][5] = 7;
    board[7][6] = 1;
    board[7][7] = 3;
    board[7][8] = 6;

    board[8][0] = 7;
    board[8][1] = 6;
    board[8][2] = 3;
    board[8][3] = 4;
    board[8][4] = 1;
    board[8][5] = 8;
    board[8][6] = 2;
    board[8][7] = 5;
    // The missing number is at row 8, column 1. 

    // We'll mark all cells as fixed except for the missing one.

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == 8 && j == 1) {
                fixed[i][j] = 0;
            } else {
                fixed[i][j] = 1;
            }
        }
    }

    // Let's print the starting board.

    printf("Starting board:\n");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else {
                printf("%d", board[i][j]);
            }
            printf(" ");
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5) {
            printf("---------------------\n");
        }
    }

    // Now, let's solve the puzzle!

    solve(-1);

    // And print the solution.

    printf("\nSolution:\n");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5) {
            printf("---------------------\n");
        }
    }

    // Congratulations, you have solved a Sudoku puzzle with our amazing program!

    return 0;
}