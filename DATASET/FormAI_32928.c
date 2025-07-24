//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define GENERATIONS 50

int count_alive_neighbors(int x, int y, int* board) {
    int alive = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_x = x + i;
            int neighbor_y = y + j;
            if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= WIDTH || neighbor_y >= HEIGHT || (i == 0 && j == 0)) {
                continue;
            }
            if (board[neighbor_y * WIDTH + neighbor_x]) {
                alive++;
            }
        }
    }
    return alive;
}

void print_board(int* board) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i * WIDTH + j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int board[WIDTH * HEIGHT] = { 0 };

    // Seed the random number generator
    srand(time(NULL));

    // Randomize the initial state of the board
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        board[i] = rand() % 2;
    }

    // Run the game of life for the specified number of generations
    for (int gen = 0; gen < GENERATIONS; gen++) {
        system("clear"); // Clear the console output on Unix systems 
                         // (replace with "cls" for Windows systems)
        print_board(board);
        int new_board[WIDTH * HEIGHT] = { 0 };
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int alive_neighbors = count_alive_neighbors(j, i, board);
                if (board[i * WIDTH + j] == 1) {
                    if (alive_neighbors < 2 || alive_neighbors > 3) {
                        new_board[i * WIDTH + j] = 0;
                    }
                    else {
                        new_board[i * WIDTH + j] = 1;
                    }
                }
                else {
                    if (alive_neighbors == 3) {
                        new_board[i * WIDTH + j] = 1;
                    }
                    else {
                        new_board[i * WIDTH + j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < WIDTH * HEIGHT; i++) {
            board[i] = new_board[i];
        }
        usleep(100000); // Pause for 100 milliseconds between generations
    }

    return 0;
}