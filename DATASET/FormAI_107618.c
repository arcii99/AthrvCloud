//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum dimensions of the game board
#define MAX_ROWS 30
#define MAX_COLS 60

// Helper function to generate random integers between min and max
int randomInt(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

int main() {

    // Initialize the game board to all dead cells
    int board[MAX_ROWS][MAX_COLS] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Initialize a random pattern of live cells
    for (int i = 0; i < 1000; i++) {
        int row = randomInt(0, MAX_ROWS - 1);
        int col = randomInt(0, MAX_COLS - 1);
        board[row][col] = 1;
    }

    // Print out the initial game board
    printf("Initial Game Board:\n");
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            printf("%c", board[row][col] == 0 ? ' ' : '*');
        }
        printf("\n");
    }

    // Run the game for 100 generations
    for (int generation = 1; generation <= 100; generation++) {

        // Initialize a new board to store the next generation
        int newBoard[MAX_ROWS][MAX_COLS] = {0};

        // Loop through each cell on the board
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLS; col++) {

                // Count the number of live neighbor cells
                int liveNeighbors = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        int neighborRow = row + i;
                        int neighborCol = col + j;
                        if (neighborRow >= 0 && neighborRow < MAX_ROWS &&
                            neighborCol >= 0 && neighborCol < MAX_COLS &&
                            (i != 0 || j != 0) && board[neighborRow][neighborCol] == 1) {
                            liveNeighbors++;
                        }
                    }
                }

                // Apply the Game of Life rules
                if (board[row][col] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        newBoard[row][col] = 0; // Cell dies
                    } else {
                        newBoard[row][col] = 1; // Cell lives
                    }
                } else {
                    if (liveNeighbors == 3) {
                        newBoard[row][col] = 1; // Cell becomes alive
                    } else {
                        newBoard[row][col] = 0; // Cell stays dead
                    }
                }
            }
        }

        // Copy the next generation board back to the original board
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLS; col++) {
                board[row][col] = newBoard[row][col];
            }
        }

        // Print out the current generation
        printf("Generation %d:\n", generation);
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLS; col++) {
                printf("%c", board[row][col] == 0 ? ' ' : '*');
            }
            printf("\n");
        }
    }

    return 0;
}