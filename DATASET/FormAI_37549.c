//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
/*
Title: Ada Lovelace's Game of Life
Author: Ada Lovelace
Date: October 21, 1843
Description: A program that simulates John Conway's Game of Life using
             Ada's analytical engine and printing the output to the terminal.
*/

#include <stdio.h>

#define ROWS 20
#define COLS 20

void initialize_board(int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS] = {0};

    initialize_board(board);

    for (int i = 0; i < 10; i++) {
        update_board(board);

        printf("Generation %d:\n", i+1);
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == 0) {
                    printf(".");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void initialize_board(int board[ROWS][COLS]) {
    // Set up the initial configuration of the board
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;
    board[3][3] = 1;
    board[3][4] = 1;
    board[3][5] = 1;
}

void update_board(int board[ROWS][COLS]) {
    int temp_board[ROWS][COLS] = {0};

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int live_neighbors = 0;

            // Check each neighbor cell
            for (int nb_row = row-1; nb_row <= row+1; nb_row++) {
                for (int nb_col = col-1; nb_col <= col+1; nb_col++) {
                    if (nb_row != row || nb_col != col) {
                        if (nb_row >= 0 && nb_row < ROWS && nb_col >= 0 && nb_col < COLS) {
                            live_neighbors += board[nb_row][nb_col];
                        }
                    }
                }
            }

            // Apply the rules of the game
            if (board[row][col] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    temp_board[row][col] = 0;
                } else {
                    temp_board[row][col] = 1;
                }
            } else {
                if (live_neighbors == 3) {
                    temp_board[row][col] = 1;
                } else {
                    temp_board[row][col] = 0;
                }
            }
        }
    }

    // Copy the updated board to the original board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = temp_board[row][col];
        }
    }
}