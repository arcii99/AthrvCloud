//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

int random_number(int min_num, int max_num)
{
    return (rand() % (max_num - min_num + 1)) + min_num;
}

void init_board(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = random_number(0, 1);
        }
    }
}

void print_board(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int row, int col)
{
    int count = 0;

    for (int i = row-1; i <= row+1; ++i) {
        for (int j = col-1; j <= col+1; ++j) {
            if (i == row && j == col) {
                continue;
            }
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            count += board[i][j];
        }
    }

    return count;
}

void update_board(int board[ROWS][COLS])
{
    int new_board[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int neighbors = count_neighbors(board, i, j);

            if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main()
{
    srand(time(0));

    int board[ROWS][COLS];

    init_board(board);

    for (int i = 0; i < 100; ++i) {
        system("clear");
        printf("Generation %d:\n", i);
        print_board(board);
        update_board(board);
        usleep(200000);
    }

    return 0;
}