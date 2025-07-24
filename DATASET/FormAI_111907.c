//FormAI DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

void initialize_board(int board[WIDTH][HEIGHT]) {
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int x, int y, int board[WIDTH][HEIGHT]) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int neighbor_x = x + i;
            int neighbor_y = y + j;
            if (neighbor_x < 0) {
                neighbor_x = WIDTH - 1;
            } else if (neighbor_x >= WIDTH) {
                neighbor_x = 0;
            }
            if (neighbor_y < 0) {
                neighbor_y = HEIGHT - 1;
            } else if (neighbor_y >= HEIGHT) {
                neighbor_y = 0;
            }
            if (board[neighbor_x][neighbor_y] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[WIDTH][HEIGHT]) {
    int new_board[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int neighbors = count_neighbors(i, j, board);
            if (board[i][j] == 1) {
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
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[WIDTH][HEIGHT];
    initialize_board(board);
    while (1) {
        print_board(board);
        update_board(board);
        printf("\033[2J\033[1;1H"); // clear screen
        fflush(stdout);
    }
    return 0;
}