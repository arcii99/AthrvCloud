//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 60

void initializeBoard(char board[][COLS]) {
    int i, j;

    // Set all cells to dead
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // Randomly set a few cells to alive
    srand(time(NULL));
    for(i = 0; i < 120; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        board[row][col] = '*';
    }
}

void printBoard(char board[][COLS]) {
    int i, j;

    // Clear the screen
    system("clear");

    // Print the board
    printf("+------------------------------------------------------------+\n");
    for(i = 0; i < ROWS; i++) {
        printf("|");
        for(j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
    printf("+------------------------------------------------------------+\n");
}

int countNeighbors(char board[][COLS], int row, int col) {
    int count = 0;
    int i, j;

    // Check the surrounding cells
    for(i = row - 1; i <= row + 1; i++) {
        for(j = col - 1; j <= col + 1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                if(board[i][j] == '*') {
                    count++;
                }
            }
        }
    }

    return count;
}

void updateBoard(char board[][COLS]) {
    int i, j;
    char newBoard[ROWS][COLS];

    // Copy the board to a new array
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            newBoard[i][j] = board[i][j];
        }
    }

    // Update each cell based on the Game of Life rules
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(board, i, j);
            if(board[i][j] == '*') {
                if(neighbors < 2 || neighbors > 3) {
                    newBoard[i][j] = ' ';
                }
            }
            else {
                if(neighbors == 3) {
                    newBoard[i][j] = '*';
                }
            }
        }
    }

    // Copy the new board back to the original board
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    char board[ROWS][COLS];
    int i;

    // Generate the initial board
    initializeBoard(board);

    // Run the simulation
    for(i = 0; i < 100; i++) {
        // Print the board
        printBoard(board);

        // Wait for a moment before updating the board
        usleep(100000);

        // Update the board
        updateBoard(board);
    }

    return 0;
}