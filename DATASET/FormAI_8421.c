//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initialize_board(int board[ROWS][COLS]) {
    // Initialize board with random values
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

int get_neighbor_count(int board[ROWS][COLS], int row, int col) {
    // Get neighbor count at given row and col
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if ((i >= 0 && i < ROWS) && (j >= 0 && j < COLS) && !(i == row && j == col)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    // Update the board based on neighbor count
    int next_board[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = get_neighbor_count(board, i, j);
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    next_board[i][j] = 0;
                } else {
                    next_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next_board[i][j] = 1;
                }
            }
        }
    }
    // Copy the next board to the original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    // Print the board
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    initialize_board(board);
    for (int i = 0; i < 10; i++) {
        print_board(board);
        update_board(board);
    }
    return 0;
}