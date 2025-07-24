//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Set the board size and the number of iterations to run
#define BOARD_SIZE 25
#define ITERATIONS 500

// Symbols for the different states of a cell
#define EMPTY '.'
#define FILLED 'X'

// The board and array copy 
char board[BOARD_SIZE][BOARD_SIZE];
char copy[BOARD_SIZE][BOARD_SIZE];

// Function to reset the board to empty
void resetBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = EMPTY;
        }
    }
}

// Function to simulate a single iteration of the percolation algorithm
void simulate() {
    // Copy the current state of the board to the array
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            copy[y][x] = board[y][x];
        }
    }

    // Iterate over each cell in the board
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            // If the cell is empty and any of its neighbours are filled, fill the cell
            if (board[y][x] == EMPTY) {
                if ((y > 0 && board[y-1][x] == FILLED) ||
                    (y < BOARD_SIZE - 1 && board[y+1][x] == FILLED) ||
                    (x > 0 && board[y][x-1] == FILLED) ||
                    (x < BOARD_SIZE - 1 && board[y][x+1] == FILLED)) {
                    copy[y][x] = FILLED;
                }
            }
        }
    }

    // Copy the updated state from the array back to the board
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = copy[y][x];
        }
    }
}

// Function to print the board to the console
void printBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%c ", board[y][x]);
        }
        printf("\n");
    }
}

int main() {
    // Set the random seed based on the current time
    srand(time(NULL));

    // Reset the board to empty
    resetBoard();

    // Add some initial filled cells to the top row
    for (int x = 0; x < BOARD_SIZE; x++) {
        if (rand() % 2 == 1) {
            board[0][x] = FILLED;
        }
    }

    // Simulate the percolation algorithm for the specified number of iterations
    for (int i = 0; i < ITERATIONS; i++) {
        simulate();
    }

    // Print the final state of the board
    printBoard();

    return 0;
}