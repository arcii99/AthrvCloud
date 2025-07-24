//FormAI DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void init_board(int board[][COLS]);
void print_board(int board[][COLS]);
int count_neighbors(int board[][COLS], int x, int y);

int main(void) {
    int board[ROWS][COLS];
    int new_board[ROWS][COLS];
    int i, j, neighbors;

    srand(time(NULL));
    init_board(board);
    print_board(board);

    while (1) {
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                neighbors = count_neighbors(board, i, j);

                if (board[i][j] == 0 && neighbors == 3) {
                    new_board[i][j] = 1;
                } else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = board[i][j];
                }
            }
        }

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                board[i][j] = new_board[i][j];
            }
        }

        system("clear");
        print_board(board);
    }

    return 0;
}

void init_board(int board[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board(int board[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[][COLS], int x, int y) {
    int i, j, count = 0;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }
            if (i < 0 || j < 0 || i >= ROWS || j >= COLS) {
                continue;
            }
            if (board[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}