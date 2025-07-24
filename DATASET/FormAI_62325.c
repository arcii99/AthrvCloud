//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>

#define SIZE 9
#define EMPTY 0

int board[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int solve(int row, int col);
void print_board(void);

int main(void)
{
    print_board();
    solve(0, 0);
    return 0;
}

int solve(int row, int col)
{
    int i, num;
    if (row == SIZE) {
        printf("Solution: \n");
        print_board();
        return 1;
    }
    if (board[row][col] != EMPTY) {
        if (col == SIZE-1) {
            return solve(row + 1, 0);
        }
        return solve(row, col + 1);
    }
    for (num=1; num <= SIZE; num++) {
        int ok = 1;
        int r, c;
        for (i=0; i<SIZE; i++) {
            if (board[row][i] == num) { ok = 0; break; }
            if (board[i][col] == num) { ok = 0; break; }
            r = 3*(row/3) + (i/3);
            c = 3*(col/3) + (i%3);
            if (board[r][c] == num) { ok = 0; break; }
        }
        if (ok) {
            board[row][col] = num;
            if (col == SIZE-1) {
                if (solve(row + 1, 0)) return 1;
            } else {
                if (solve(row, col + 1)) return 1;
            }
            board[row][col] = EMPTY;
        }
    }
    return 0;
}

void print_board(void)
{
    int i, j;
    printf(" +-----+-----+-----+\n");
    for (i=0; i<SIZE; i++) {
        printf(" | ");
        for (j=0; j<SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j+1)%3 == 0) printf("| ");
        }
        printf("\n");
        if ((i+1)%3 == 0) printf(" +-----+-----+-----+\n");
    }
}