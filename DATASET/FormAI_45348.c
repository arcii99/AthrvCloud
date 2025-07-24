//FormAI DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

void init_board(int board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (board[i][j] == 0) {
                printf("░░");
            } else {
                printf("▓▓");
            }
        }
        printf("\n");
    }
}

void update_board(int board[HEIGHT][WIDTH]) {
    int i, j, neighbors, new_board[HEIGHT][WIDTH];
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            neighbors = (board[(i - 1 + HEIGHT) % HEIGHT][(j - 1 + WIDTH) % WIDTH]
                      + board[(i - 1 + HEIGHT) % HEIGHT][j]
                      + board[(i - 1 + HEIGHT) % HEIGHT][(j + 1) % WIDTH]
                      + board[i][(j - 1 + WIDTH) % WIDTH]
                      + board[i][(j + 1) % WIDTH]
                      + board[(i + 1) % HEIGHT][(j - 1 + WIDTH) % WIDTH]
                      + board[(i + 1) % HEIGHT][j]
                      + board[(i + 1) % HEIGHT][(j + 1) % WIDTH]);
            if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int board[HEIGHT][WIDTH];
    init_board(board);
    while (1) {
        printf("\033[2J\033[1;1H"); // Clear terminal and move cursor to top left corner
        print_board(board);
        update_board(board);
        usleep(100000); // Wait 100ms before updating again
    }
    return 0;
}