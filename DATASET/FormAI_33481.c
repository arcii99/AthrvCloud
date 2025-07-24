//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int board[MAX_ROWS][MAX_COLS];
int tmp_board[MAX_ROWS][MAX_COLS];

int count_neighbors(int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < MAX_ROWS && j >= 0 && j < MAX_COLS && (i != row || j != col) && board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_board() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            int neighbors = count_neighbors(i, j);
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                tmp_board[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                tmp_board[i][j] = 1;
            } else {
                tmp_board[i][j] = board[i][j];
            }
        }
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = tmp_board[i][j];
        }
    }
}

void print_board() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize board
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Run simulation
    for (int i = 0; i < 50; i++) {
        print_board();
        update_board();
        printf("\n");
    }

    return 0;
}