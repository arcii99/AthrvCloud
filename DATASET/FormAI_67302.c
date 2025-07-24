//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30
#define GENERATIONS 100

/* Macro to handle getting the cell at wraparound edges */
#define CELL(x, y) board[(y + HEIGHT) % HEIGHT][(x + WIDTH) % WIDTH]

void initialize_board(int board[][WIDTH], int initial_state[][2], int num_cells) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = 0;
        }
    }
    for (i = 0; i < num_cells; i++) {
        CELL(initial_state[i][0], initial_state[i][1]) = 1;
    }
}

int count_neighbors(int board[][WIDTH], int x, int y) {
    int i, j, count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            count += CELL(x + j, y + i);
        }
    }
    return count;
}

void print_board(int board[][WIDTH], int generation) {
    int i, j;
    printf("Generation #%d\n", generation);
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(board[i][j] ? 'X' : '.');
        }
        putchar('\n');
    }
}

void copy_board(int dest[][WIDTH], int src[][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int main(void) {
    int board[HEIGHT][WIDTH];
    int temp_board[HEIGHT][WIDTH];
    int initial_state[][2] = {{2, 2}, {2, 3}, {2, 4}};
    int num_cells = sizeof(initial_state) / sizeof(initial_state[0]);
    int generation;

    initialize_board(board, initial_state, num_cells);

    for (generation = 0; generation <= GENERATIONS; generation++) {
        print_board(board, generation);
        copy_board(temp_board, board);
        int i, j;
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                int neighbors = count_neighbors(board, j, i);
                if (board[i][j] && (neighbors < 2 || neighbors > 3)) {
                    temp_board[i][j] = 0;
                } else if (!board[i][j] && neighbors == 3) {
                    temp_board[i][j] = 1;
                }
            }
        }
        copy_board(board, temp_board);
    }

    return 0;
}