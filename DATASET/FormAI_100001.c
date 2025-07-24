//FormAI DATASET v1.0 Category: Sudoku solver ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int board[SIZE][SIZE];

void print_board()
{
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

void solve()
{
    int row, col, num;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (num = 1; num <= SIZE; num++) {
                    int i, j;
                    int valid = 1;
                    for (i = 0; i < SIZE; i++) {
                        if (board[i][col] == num) {
                            valid = 0;
                            break;
                        }
                    }
                    for (j = 0; j < SIZE; j++) {
                        if (board[row][j] == num) {
                            valid = 0;
                            break;
                        }
                    }
                    int box_row = row / 3;
                    int box_col = col / 3;
                    for (i = box_row*3; i < box_row*3+3; i++) {
                        for (j = box_col*3; j < box_col*3+3; j++) {
                            if (board[i][j] == num) {
                                valid = 0;
                                break;
                            }
                        }
                    }
                    if (valid) {
                        board[row][col] = num;
                        solve();
                        board[row][col] = 0;
                    }
                }
                return;
            }
        }
    }
    print_board();
    exit(0);
}

int main()
{
    // Initialize the board
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            scanf("%d", &board[row][col]);
        }
    }
    // Solve the puzzle
    solve();
    printf("No solution found.");
    return 0;
}