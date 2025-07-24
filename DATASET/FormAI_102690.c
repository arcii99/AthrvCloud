//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>

void print_board(int board[9][9]) {
    // Print out the current state of the board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_square(int board[9][9], int row, int col) {
    // Given a row and column, return the square number for the 3x3 sub-grid
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    int square = 0;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (board[i][j] != 0) square |= 1 << (board[i][j] - 1);
        }
    }
    return square;
}

int get_possible_values(int board[9][9], int row, int col) {
    // Given a row and column, return a bitset of possible values to try
    int square = get_square(board, row, col);
    int row_values = 0, col_values = 0, value_mask = 0;
    for (int i = 0; i < 9; i++) {
        if (board[row][i] != 0) row_values |= 1 << (board[row][i] - 1);
        if (board[i][col] != 0) col_values |= 1 << (board[i][col] - 1);
    }
    value_mask = square | row_values | col_values;
    // Invert the mask and return the possible values as a bitset
    return ~value_mask & 0x1ff;
}

void solve_board(int board[9][9]) {
    // Iterate over each cell and try possible values until a solution is found
    int row = -1, col = -1, values = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                // If this cell is empty, get possible values
                int possible_values = get_possible_values(board, i, j);
                if (possible_values == 0) return;
                // If there's only one possible value, fill it in
                if (__builtin_popcount(possible_values) == 1) {
                    for (int k = 0; k < 9; k++) {
                        if (possible_values & (1 << k)) {
                            board[i][j] = k + 1;
                            break;
                        }
                    }
                    solve_board(board);
                    if (row != -1 && col != -1) {
                        // If we're backtracking, reset backtracking flag and return
                        board[row][col] = values;
                        row = -1;
                        col = -1;
                        values = -1;
                        return;
                    }
                }
                else {
                    // Otherwise, try possible values and backtrack if they don't work
                    for (int k = 0; k < 9; k++) {
                        if (possible_values & (1 << k)) {
                            int temp = board[i][j];
                            board[i][j] = k + 1;
                            solve_board(board);
                            if (row == -1 && col == -1) {
                                row = i;
                                col = j;
                                values = temp;
                            }
                            else {
                                // If already backtracking, fill in original value and return
                                board[row][col] = values;
                                row = -1;
                                col = -1;
                                values = -1;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int board[9][9] = {
        {0, 0, 0, 0, 5, 0, 0, 2, 0},
        {7, 6, 0, 0, 9, 8, 0, 0, 0},
        {3, 0, 0, 2, 0, 0, 0, 0, 6},
        {0, 0, 0, 9, 0, 0, 0, 0, 8},
        {0, 7, 2, 0, 0, 0, 1, 5, 0},
        {8, 0, 0, 0, 0, 6, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 6, 4, 0, 0, 8, 5},
        {0, 4, 0, 0, 2, 0, 0, 0, 0}
    };
    printf("Original board:\n");
    print_board(board);
    solve_board(board);
    printf("Solved board:\n");
    print_board(board);
    return 0;
}