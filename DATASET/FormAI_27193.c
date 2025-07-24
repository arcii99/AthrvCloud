//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for board size
#define ROWS 20
#define COLUMNS 40

// Define function to initialize the board
void initBoard(int board[ROWS][COLUMNS]) {
    int i, j;
    // Seed the random number generator
    srand(time(NULL));
    // Populate the board randomly
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Define function to print the board
void printBoard(int board[ROWS][COLUMNS]) {
    int i, j;
    // Clear the screen
    system("clear");
    // Print the board
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            printf("%s", board[i][j] ? "*" : " ");
        }
        printf("\n");
    }
}

// Define function to calculate the next generation of cells
void calculateNextGen(int board[ROWS][COLUMNS]) {
    int i, j, neighbors;
    int newBoard[ROWS][COLUMNS];
    // Calculate the new board
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            // Calculate the number of neighbors
            neighbors = 0;
            if(i > 0 && board[i-1][j]) {
                neighbors++;
            }
            if(i < ROWS-1 && board[i+1][j]) {
                neighbors++;
            }
            if(j > 0 && board[i][j-1]) {
                neighbors++;
            }
            if(j < COLUMNS-1 && board[i][j+1]) {
                neighbors++;
            }
            if(i > 0 && j > 0 && board[i-1][j-1]) {
                neighbors++;
            }
            if(i > 0 && j < COLUMNS-1 && board[i-1][j+1]) {
                neighbors++;
            }
            if(i < ROWS-1 && j > 0 && board[i+1][j-1]) {
                neighbors++;
            }
            if(i < ROWS-1 && j < COLUMNS-1 && board[i+1][j+1]) {
                neighbors++;
            }
            // Determine the new state of the cell
            if(board[i][j] && (neighbors < 2 || neighbors > 3)) {
                newBoard[i][j] = 0;
            } else if(!board[i][j] && neighbors == 3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = board[i][j];
            }
        }
    }
    // Copy the new board back to the old board
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLUMNS];
    // Initialize the board
    initBoard(board);
    // Run the game of life
    while(1) {
        // Print the board
        printBoard(board);
        // Calculate the next generation
        calculateNextGen(board);
        // Wait for a short period of time
        usleep(100000);
    }
    return 0;
}