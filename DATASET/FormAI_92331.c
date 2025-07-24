//FormAI DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define GENERATIONS 50

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("-----------------\n");
}

int count_neighbors(int board[SIZE][SIZE], int row, int col) {
    int count = 0;

    // Check all 8 neighbors of the current cell
    if (board[(row - 1 + SIZE) % SIZE][(col - 1 + SIZE) % SIZE] == 1) {
        count++;
    }
    if (board[(row - 1 + SIZE) % SIZE][col] == 1) {
        count++;
    }
    if (board[(row - 1 + SIZE) % SIZE][(col + 1) % SIZE] == 1) {
        count++;
    }
    if (board[row][(col - 1 + SIZE) % SIZE] == 1) {
        count++;
    }
    if (board[row][(col + 1) % SIZE] == 1) {
        count++;
    }
    if (board[(row + 1) % SIZE][(col - 1 + SIZE) % SIZE] == 1) {
        count++;
    }
    if (board[(row + 1) % SIZE][col] == 1) {
        count++;
    }
    if (board[(row + 1) % SIZE][(col + 1) % SIZE] == 1) {
        count++;
    }

    return count;
}

void update_board(int board[SIZE][SIZE]) {
    int next_board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = count_neighbors(board, i, j);

            // Apply the rules of the Game of Life
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                next_board[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                next_board[i][j] = 1;
            } else {
                next_board[i][j] = board[i][j];
            }
        }
    }

    // Copy the new board over the old board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int board[SIZE][SIZE];

    // Initialize the board randomly
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Run the simulation for a number of generations
    for (int gen = 0; gen < GENERATIONS; gen++) {
        printf("Generation %d:\n", gen + 1);
        print_board(board);
        update_board(board);
    }

    return 0;
}