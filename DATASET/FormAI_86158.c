//FormAI DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game board dimensions
#define ROWS 20
#define COLS 60

// Function to print out the game board
void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of live neighbors for a given cell
int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col) && board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to update the game board for one iteration
void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Initialize the game board
    int board[ROWS][COLS] = {0};
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Run the game for 100 iterations
    for (int i = 0; i < 100; i++) {
        printf("Iteration %d:\n", i);
        print_board(board);
        update_board(board);
    }

    return 0;
}