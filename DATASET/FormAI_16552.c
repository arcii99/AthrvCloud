//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 50

// Define 2 arrays to represent current and next state of the board
int currentBoard[ROWS][COLUMNS];
int nextBoard[ROWS][COLUMNS];

// Helper function to print the current state of the board
void printBoard(int board[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j] == 1) {
                printf("0 ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Helper function to initialize the board with random values
void initializeBoard(int board[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Helper function to count the number of live neighbors for a given cell
int countLiveNeighbors(int row, int column) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=column-1; j<=column+1; j++) {
            // Skip the current cell
            if(i == row && j == column)
                continue;
            // Check if the cell is within the bounds of the board
            if(i >= 0 && i < ROWS && j >= 0 && j < COLUMNS) {
                if(currentBoard[i][j] == 1)
                    count++;
            }
        }
    }
    return count;
}

// Main function to run the game of life
int main() {
    printf("Welcome to the game of life!\n");

    // Initialize the board with random values
    initializeBoard(currentBoard);

    // Loop through generations
    for(int generation=0; generation<1000; generation++) {
        printf("Generation %d:\n", generation);
        printBoard(currentBoard);

        // Loop through each cell and compute the next state of the board
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLUMNS; j++) {
                int liveNeighbors = countLiveNeighbors(i, j);
                if(currentBoard[i][j] == 1) {
                    // Any live cell with two or three live neighbors survives
                    if(liveNeighbors == 2 || liveNeighbors == 3)
                        nextBoard[i][j] = 1;
                    // Any live cell with fewer than two live neighbors dies
                    else
                        nextBoard[i][j] = 0;
                } else {
                    // Any dead cell with exactly three live neighbors becomes a live cell
                    if(liveNeighbors == 3)
                        nextBoard[i][j] = 1;
                    // Otherwise, the cell remains dead
                    else
                        nextBoard[i][j] = 0;
                }
            }
        }

        // Copy the next state of the board to the current state
        memcpy(currentBoard, nextBoard, sizeof(currentBoard));
    }

    printf("Game over!\n");
    return 0;
}