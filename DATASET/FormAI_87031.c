//FormAI DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 25

void initialize(int board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 2) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    int i, j;
    printf("\033[2J\033[%d;%dH", 0, 0); // clear screen and reset cursor
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (board[i][j]) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int get_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int count = 0, i, j;
    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            } else if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH) {
                continue;
            } else if (board[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];
    int i, j, neighbors;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            neighbors = get_neighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0; // cell dies
                } else {
                    new_board[i][j] = 1; // cell survives
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 1; // cell is born
                } else {
                    new_board[i][j] = 0; // cell remains dead
                }
            }
        }
    }
    // copy new board to old board
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    initialize(board);
    while (1) {
        print_board(board);
        update_board(board);
        usleep(100000); // sleep for 0.1 seconds
    }
    return 0;
}