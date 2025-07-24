//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 100

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]) printf("*");
            else printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    int row_up = row-1 >= 0 ? row-1 : ROWS-1;
    int row_down = row+1 <= ROWS-1 ? row+1 : 0;
    int col_left = col-1 >= 0 ? col-1 : COLS-1;
    int col_right = col+1 <= COLS-1 ? col+1 : 0;
    count += board[row_up][col_left];
    count += board[row_up][col];
    count += board[row_up][col_right];
    count += board[row][col_left];
    count += board[row][col_right];
    count += board[row_down][col_left];
    count += board[row_down][col];
    count += board[row_down][col_right];
    return count;
}

void simulate(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
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
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    printf("Starting board:\n");
    print_board(board);
    for (int i = 0; i < 50; i++) {
        simulate(board);
        printf("Iteration %d:\n", i+1);
        print_board(board);
    }
    return 0;
}