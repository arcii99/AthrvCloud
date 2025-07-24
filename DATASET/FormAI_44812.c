//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define ROWS 20
#define COLS 20

void init_board(bool board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }
}

void print_board(bool board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col] ? 'X' : '-');
        }
        printf("\n");
    }
}

bool is_alive(bool board[][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    return board[row][col];
}

int count_neighbors(bool board[][COLS], int row, int col) {
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if ((r != row || c != col) && is_alive(board, r, c)) {
                count++;
            }
        }
    }
    return count;
}

void update_board(bool board[][COLS]) {
    bool new_board[ROWS][COLS] = { false };
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(board, row, col);
            if (is_alive(board, row, col)) {
                if (neighbors == 2 || neighbors == 3) {
                    new_board[row][col] = true;
                }
            } else {
                if (neighbors == 3) {
                    new_board[row][col] = true;
                }
            }
        }
    }
    memcpy(board, new_board, sizeof(bool) * ROWS * COLS);
}

int main() {
    bool board[ROWS][COLS] = { false };
    init_board(board);
    while (true) {
        print_board(board);
        update_board(board);
        getchar();
    }
    return 0;
}