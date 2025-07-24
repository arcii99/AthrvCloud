//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SLEEP_TIME 500

void print_board(int board[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (board[row][col] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // skip current cell
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if (neighbor_row < 0 || neighbor_row >= ROWS) continue;
            if (neighbor_col < 0 || neighbor_col >= COLS) continue;
            if (board[neighbor_row][neighbor_col] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS];
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(board, row, col);
            if (board[row][col] == 1) { // alive cell
                if (neighbors < 2 || neighbors > 3) {
                    new_board[row][col] = 0; // dies
                } else {
                    new_board[row][col] = 1; // lives
                }
            } else { // dead cell
                if (neighbors == 3) {
                    new_board[row][col] = 1; // comes to life
                } else {
                    new_board[row][col] = 0; // stays dead
                }
            }
        }
    }
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = new_board[row][col];
        }
    }
}

int main() {
    int board[ROWS][COLS];

    // initialize random board
    srand(time(NULL));
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }

    // run game of life
    while (1) {
        print_board(board);
        update_board(board);
        usleep(SLEEP_TIME * 1000);
    }

    return 0;
}