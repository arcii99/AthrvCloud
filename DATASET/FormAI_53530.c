//FormAI DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
#define ROWS 30
#define COLUMNS 30

// Function to initialize the game board randomly
void initializeBoard(int board[ROWS][COLUMNS]) {
    srand(time(NULL)); // Seed the random number generator
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLUMNS; col++) {
            board[row][col] = rand() % 2;
        }
    }
}

// Function to print the current state of the game board
void printBoard(int board[ROWS][COLUMNS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLUMNS; col++) {
            if (board[row][col] == 0)
                putchar('.');
            else
                putchar('*');
        }
        putchar('\n');
    }
    putchar('\n');
}

// Function to count the number of alive neighbors for a cell
int countNeighbors(int board[ROWS][COLUMNS], int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) { // Check the 8 surrounding cells
            if (i < 0 || j < 0 || i >= ROWS || j >= COLUMNS) // Ignore cells that are outside the board
                continue;
            if (i == row && j == col) // Ignore the current cell
                continue;
            if (board[i][j] == 1)
                count++;
        }
    }
    return count;
}

// Function to update the game board based on the current state and rules
void updateBoard(int currentBoard[ROWS][COLUMNS], int newBoard[ROWS][COLUMNS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLUMNS; col++) {
            int neighbors = countNeighbors(currentBoard, row, col);
            if (currentBoard[row][col] == 1) { // If the current cell is alive
                if (neighbors < 2 || neighbors > 3) // The cell dies if it has less than 2 or more than 3 neighbors
                    newBoard[row][col] = 0;
                else // The cell survives if it has 2 or 3 neighbors
                    newBoard[row][col] = 1;
            }
            else { // If the current cell is dead
                if (neighbors == 3) // The cell becomes alive if it has exactly 3 neighbors
                    newBoard[row][col] = 1;
                else
                    newBoard[row][col] = 0;
            }
        }
    }
}

int main() {
    // Allocate memory for the game board
    int currentBoard[ROWS][COLUMNS];
    int newBoard[ROWS][COLUMNS];

    // Initialize the game board randomly
    initializeBoard(currentBoard);

    // Start the game
    int generation = 1;
    while (1) {
        // Print the current state of the game board
        printf("Generation %d:\n", generation);
        printBoard(currentBoard);

        // Update the game board
        updateBoard(currentBoard, newBoard);

        // Check if the game is over
        int row, col;
        int same = 1; // Assume the boards are the same until proven otherwise
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLUMNS; col++) {
                if (currentBoard[row][col] != newBoard[row][col]) {
                    same = 0;
                    break;
                }
            }
            if (!same)
                break;
        }
        if (same) {
            printf("Game over: the board has reached a stable state.\n");
            break;
        }

        // Copy the new board to the current board
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLUMNS; col++) {
                currentBoard[row][col] = newBoard[row][col];
            }
        }

        // Increment the generation counter
        generation++;
    }

    return 0;
}