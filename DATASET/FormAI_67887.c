//FormAI DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 30
#define GENERATION_LIMIT 1000

void init_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    /* Randomly generates the initial board state */
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int val = rand() % 2;
            board[i][j] = val;
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    /* Prints the current board state */
    printf("-------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

int count_neighbors(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    /* Counts the number of live neighbors of a given cell */
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int row = (x + i + BOARD_SIZE) % BOARD_SIZE;
            int col = (y + j + BOARD_SIZE) % BOARD_SIZE;
            count += board[row][col];
        }
    }
    return count;
}

void next_generation(int board[BOARD_SIZE][BOARD_SIZE]) {
    /* Generates the next generation of the board */
    int new_board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1 && neighbors < 2) {
                new_board[i][j] = 0;
            } else if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 1 && neighbors > 3) {
                new_board[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    /* Copy the new board state back to the original board */
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int generation = 0;
    init_board(board);
    print_board(board);
    while (generation < GENERATION_LIMIT) {
        next_generation(board);
        print_board(board);
        generation++;
    }
    return 0;
}