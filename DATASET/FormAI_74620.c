//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
// Ada Lovelace inspired C implementation of Conway's Game of Life

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 80

// Function to print the game board after each generation
void print_board(char board[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the board for the next generation
void update_board(char board[][COLS]) {
    char copy[ROWS][COLS];
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            int count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    count += board[i+k][j+l] == 'X';
                }
            }
            count -= board[i][j] == 'X';
            if (board[i][j] == 'X' && (count < 2 || count > 3)) {
                copy[i][j] = ' ';
            }
            else if (board[i][j] == ' ' && count == 3) {
                copy[i][j] = 'X';
            }
            else {
                copy[i][j] = board[i][j];
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = copy[i][j];
        }
    }
}

int main() {
    // Initialize game board with randomly placed cells
    char board[ROWS][COLS];
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2 ? ' ' : 'X';
        }
    }
    
    // Run the simulation for 100 generations
    for (int i = 0; i < 100; i++) {
        // Print board and update
        print_board(board);
        update_board(board);
    }

    return 0;
}