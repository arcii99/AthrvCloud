//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void show_board(int board[ROWS][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void next_life_iteration(int cur_board[ROWS][COLS]) {
    int new_board[ROWS][COLS] = {0};
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int neighbors_count = 0;
            for (int k=-1; k<=1; k++) {
                for (int l=-1; l<=1; l++) {
                    if (k != 0 || l != 0) {
                        int row = (i + k + ROWS) % ROWS;
                        int col = (j + l + COLS) % COLS;
                        neighbors_count += cur_board[row][col];
                    }
                }
            }
            if (cur_board[i][j] == 1) {
                if (neighbors_count == 2 || neighbors_count == 3) {
                    new_board[i][j] = 1;
                }
            } else {
                if (neighbors_count == 3) {
                    new_board[i][j] = 1;
                }
            }
        }
    }
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            cur_board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {0};
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    printf("Welcome to the Game of Life!\n");
    printf("Press Ctrl+C at any time to quit.\n\n");
    while (1) {
        show_board(board);
        next_life_iteration(board);
        printf("\033[2J\033[H");
    }
    return 0;
}