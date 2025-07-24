//FormAI DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50

void init_board(int board[ROWS][COLS]) {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % 10;
            board[i][j] = r < 2 ? 1 : 0;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j] ? '#' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int r = row + i;
            int c = col + j;
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
            if (board[r][c]) count++;
        }
    }

    return count;
}

void play_game(int board[ROWS][COLS]) {
    for (int gen = 0; gen < GENERATIONS; gen++) {
        int new_board[ROWS][COLS] = {0};

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int neighbors = count_neighbors(board, i, j);

                if (board[i][j]) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_board[i][j] = 0;
                    } else {
                        new_board[i][j] = 1;
                    }
                } else {
                    if (neighbors == 3) {
                        new_board[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = new_board[i][j];
            }
        }

        print_board(board);
    }
}

int main() {
    int board[ROWS][COLS] = {0};

    init_board(board);
    print_board(board);

    play_game(board);

    return 0;
}