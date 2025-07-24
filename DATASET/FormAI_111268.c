//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25
#define MAX_ITERATIONS 100
#define SEED 12345

int board[HEIGHT][WIDTH];
int next[HEIGHT][WIDTH];

void initialize_board() {
    srand(SEED);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int row = (x + i + HEIGHT) % HEIGHT;
            int col = (y + j + WIDTH) % WIDTH;
            if (board[row][col] == 1) {
                count++;
            }
        }
    }
    if (board[x][y] == 1) {
        count--;
    }
    return count;
}

void update_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(i, j);
            if (board[i][j] == 1 && neighbors < 2) {
                next[i][j] = 0;
            } else if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                next[i][j] = 1;
            } else if (board[i][j] == 1 && neighbors > 3) {
                next[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                next[i][j] = 1;
            } else {
                next[i][j] = board[i][j];
            }
        }
    }
    memcpy(board, next, sizeof(board));
}

int main() {
    initialize_board();
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        print_board();
        update_board();
        printf("Iteration: %d\n", i + 1);
        printf("Press ENTER to continue.\n");
        getchar();
    }
    return 0;
}