//FormAI DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 20

void print_board(int board[ROWS][COLS]) {
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == 1) {
                printf(" # ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = (row + i + ROWS) % ROWS;
            int c = (col + j + COLS) % COLS;
            if (board[r][c] == 1) {
                count++;
            }
        }
    }

    return count - board[row][col];
}

void next_gen(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(board, row, col);

            if (board[row][col] == 1 && neighbors < 2) {
                new_board[row][col] = 0;
            } else if (board[row][col] == 1 && neighbors > 3) {
                new_board[row][col] = 0;
            } else if (board[row][col] == 0 && neighbors == 3) {
                new_board[row][col] = 1;
            } else {
                new_board[row][col] = board[row][col];
            }
        }
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = new_board[row][col];
        }
    }
}

int main(void) {
    int board[ROWS][COLS] = {0};
    srand(time(0));

    // randomly set the initial state of the board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }

    while (1) {
        print_board(board);
        next_gen(board);
        usleep(100000);
        system("clear");
    }

    return 0;
}