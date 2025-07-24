//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

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

void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];

    // Iterate over the board and create the new board based on the game rules
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbours = 0;

            // Check the surrounding cells for living cells
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue; // Skip the current cell
                    int row = (i + k + ROWS) % ROWS; // Toroidal boundary conditions
                    int col = (j + l + COLS) % COLS;
                    if (board[row][col] == 1) neighbours++;
                }
            }

            if (board[i][j] == 1) {
                // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
                // Any live cell with two or three live neighbours lives on to the next generation.
                // Any live cell with more than three live neighbours dies, as if by overpopulation.
                if (neighbours < 2 || neighbours > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
                if (neighbours == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }

    // Copy the new board back to the original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];

    // Initialize the board randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Run the game for 50 iterations
    for (int i = 0; i < 50; i++) {
        print_board(board);
        update_board(board);
    }
    
    return 0;
}