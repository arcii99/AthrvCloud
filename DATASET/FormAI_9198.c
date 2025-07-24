//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void initBoard(int board[][COLS]);
void printBoard(int board[][COLS]);
void updateBoard(int board[][COLS]);

int main() {
    int board[ROWS][COLS];
    srand(time(NULL));
    initBoard(board);
    while (1) {
        system("cls");
        printBoard(board);
        updateBoard(board);
        usleep(500000);
    }
    return 0;
}

void initBoard(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

void updateBoard(int board[][COLS]) {
    int i, j, k, l, live_neighbors;
    int next_board[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            live_neighbors = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    if (i + k < 0 || i + k >= ROWS || j + l < 0 || j + l >= COLS) continue;
                    if (board[i + k][j + l]) live_neighbors++;
                }
            }
            if (board[i][j] && (live_neighbors == 2 || live_neighbors == 3)) next_board[i][j] = 1;
            else if (!board[i][j] && live_neighbors == 3) next_board[i][j] = 1;
            else next_board[i][j] = 0;
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}