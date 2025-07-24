//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 30

void print_board(bool board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                printf(" O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int count_neighbors(bool board[N][N], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (is_valid(nx, ny) && board[nx][ny]) {
                count++;
            }
        }
    }
    return count;
}

void update_board(bool board[N][N]) {
    bool next_board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int count = count_neighbors(board, i, j);
            if (board[i][j]) {
                if (count < 2 || count > 3) {
                    next_board[i][j] = false;
                } else {
                    next_board[i][j] = true;
                }
            } else {
                if (count == 3) {
                    next_board[i][j] = true;
                } else {
                    next_board[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

int main() {
    bool board[N][N] = { false };
    board[15][15] = true;
    board[15][16] = true;
    board[15][17] = true;
    board[14][17] = true;
    board[13][16] = true;
    while (true) {
        printf("\033[2J\033[1;1H");
        print_board(board);
        update_board(board);
        usleep(100000);
    }
    return 0;
}