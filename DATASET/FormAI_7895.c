//FormAI DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define board size and generation count
#define BOARD_SIZE 20
#define GENERATION_COUNT 50

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] ? 'X' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE) {
                continue;
            }
            if (i == row && j == col) {
                continue;
            }
            if (board[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int next_board[BOARD_SIZE][BOARD_SIZE] = {0};
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors == 2 || neighbors == 3) {
                    next_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next_board[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize board
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
    printf("Initial Board:\n");
    print_board(board);
    
    // Run generation loop
    for (int gen = 0; gen < GENERATION_COUNT; gen++) {
        update_board(board);
        printf("Generation %d:\n", gen+1);
        print_board(board);
    }
    
    return 0;
}