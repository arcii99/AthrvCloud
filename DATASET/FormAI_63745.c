//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board dimensions
#define ROWS 10
#define COLS 10

// Define symbols for cell states
#define DEAD '-'
#define ALIVE 'O'

// Define global game board
char board[ROWS][COLS];

// Initialize the game board
void init_board() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = DEAD;
        }
    }
}

// Print the game board
void print_board() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Update the game board based on the rules of the Game of Life
void update_board() {
    int i, j;
    char new_board[ROWS][COLS];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int num_neighbors = 0;
            int row, col;

            // Count the number of live neighbors
            for (row = i - 1; row <= i + 1; row++) {
                for (col = j - 1; col <= j + 1; col++) {
                    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                        if (board[row][col] == ALIVE) {
                            num_neighbors++;
                        }
                    }
                }
            }

            // Subtract the current cell if it is alive
            if (board[i][j] == ALIVE) {
                num_neighbors--;
            }

            // Apply the rules of the Game of Life
            if (board[i][j] == ALIVE && (num_neighbors < 2 || num_neighbors > 3)) {
                new_board[i][j] = DEAD;
            } else if (board[i][j] == DEAD && num_neighbors == 3) {
                new_board[i][j] = ALIVE;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }

    // Copy the new board to the old board
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// Generate a random starting configuration for the game board
void random_start() {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = ALIVE;
            }
        }
    }
}

// Main function to run the game of life
int main() {
    init_board();
    random_start();

    while (1) {
        print_board();
        update_board();
        system("clear");
    }

    return 0;
}