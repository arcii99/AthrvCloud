//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

void print_board(int board[N][N]) {
    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++)
            printf("%d ", board[row][col]);
        printf("\n");
    }
}

int find_empty(int board[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (board[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

int is_valid(int board[N][N], int row, int col, int num) {
    int i, j;

    // Check row
    for (j = 0; j < N; j++)
        if (board[row][j] == num)
            return 0;

    // Check column
    for (i = 0; i < N; i++)
        if (board[i][col] == num)
            return 0;

    // Check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i + box_row][j + box_col] == num)
                return 0;

    return 1;
}

int solve_sudoku(int board[N][N]) {
    int row, col;
    if (!find_empty(board, &row, &col))
        return 1;

    int num;
    for (num = 1; num <= N; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board))
                return 1;
            board[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main() {
    int board[N][N] = { 
                        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                        { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                        { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                        { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
                    };

    printf("Sudoku puzzle:\n");
    print_board(board);
    printf("\n");

    if (solve_sudoku(board)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}