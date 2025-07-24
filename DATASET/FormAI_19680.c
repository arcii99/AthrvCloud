//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to initialize the game board
void initialize(int board[][COLS]) {
    int i, j;

    // Initialize the board to all dead (0)
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Set up some initial living cells
    board[3][4] = 1;
    board[4][5] = 1;
    board[5][3] = 1;
    board[5][4] = 1;
    board[5][5] = 1;
}

// Function to print the game board
void printBoard(int board[][COLS]) {
    int i, j;

    // Print the board
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to count the number of living neighbors
int countNeighbors(int board[][COLS], int row, int col) {
    int count = 0;
    int i, j;

    // Check each of the 8 surrounding cells
    for(i = -1; i <= 1; i++) {
        for(j = -1; j <= 1; j++) {
            if(!(i == 0 && j == 0)) {
                if(board[row+i][col+j] == 1) {
                    count++;
                }
            }
        }
    }

    return count;
}

// Function to update the game board
void update(int board[][COLS]) {
    int newBoard[ROWS][COLS];
    int i, j;
    int count;

    // Copy the old board to the new board
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            newBoard[i][j] = board[i][j];
        }
    }

    // Update each cell
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            count = countNeighbors(board, i, j);

            if(board[i][j] == 1) {
                // Living cell
                if(count < 2 || count > 3) {
                    // Cell dies due to underpopulation or overpopulation
                    newBoard[i][j] = 0;
                }
            } else {
                // Dead cell
                if(count == 3) {
                    // Cell becomes alive due to reproduction
                    newBoard[i][j] = 1;
                }
            }
        }
    }

    // Copy the new board back to the old board
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

// Main function
int main() {
    int board[ROWS][COLS];

    // Initialize the board
    initialize(board);

    // Loop through generations
    for(int i = 0; i < 10; i++) {
        // Print the board
        printBoard(board);

        // Update the board
        update(board);
    }

    return 0;
}