//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

void initialize_board(int board[][COLS]);

void print_board(int board[][COLS]);

int get_cell(int board[][COLS], int row, int col);

void set_cell(int board[][COLS], int row, int col, int val);

int count_neighbors(int board[][COLS], int row, int col);

void update_board(int board[][COLS]);

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    while (1) {
        print_board(board);
        update_board(board);
        sleep(1);
    }
}

void initialize_board(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 3 == 0) {
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
            printf("%c", get_cell(board, i, j) ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int get_cell(int board[][COLS], int row, int col) {
    return board[row][(col + COLS) % COLS];
}

void set_cell(int board[][COLS], int row, int col, int val) {
    board[row][(col + COLS) % COLS] = val;
}

int count_neighbors(int board[][COLS], int row, int col) {
    int i, j;
    int count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (get_cell(board, row + i, col + j)) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            int cell = get_cell(board, i, j);
            if (cell == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    set_cell(new_board, i, j, 0);
                } else {
                    set_cell(new_board, i, j, 1);
                }
            } else {
                if (neighbors == 3) {
                    set_cell(new_board, i, j, 1);
                } else {
                    set_cell(new_board, i, j, 0);
                }
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}