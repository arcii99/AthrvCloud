//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

int board[ROWS][COLS];
int next_board[ROWS][COLS];

void init_board() {
    srand(time(NULL));
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }
}

int count_neighbors(int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if(i == 0 && j == 0) {
                continue;
            }
            if(neighbor_row < 0 || neighbor_row >= ROWS || neighbor_col < 0 || neighbor_col >= COLS) {
                continue;
            }
            count += board[neighbor_row][neighbor_col];
        }
    }
    return count;
}

void game_of_life() {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            int count = count_neighbors(row, col);
            if(board[row][col] == 1) {
                if(count < 2 || count > 3) {
                    next_board[row][col] = 0;
                } else {
                    next_board[row][col] = 1;
                }
            } else {
                if(count == 3) {
                    next_board[row][col] = 1;
                } else {
                    next_board[row][col] = 0;
                }
            }
        }
    }
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            board[row][col] = next_board[row][col];
        }
    }
}

void print_board() {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(board[row][col] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    init_board();
    for(int i = 0; i < 100; i++) {
        printf("\033[2J\033[1;1H"); // Clear console
        print_board();
        game_of_life();
        usleep(50000); // Sleep for 50 milliseconds
    }
    return 0;
}