//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main(void) {

    // Create 2D array to represent the Bingo board
    int board[ROWS][COLS];

    // Initialize array with 0 values
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Seed random number generator
    srand(time(NULL));

    // Generate random numbers to fill the board
    for(int i = 0; i < ROWS; i++) {
        // Generate 5 random numbers for each row
        for(int j = 0; j < COLS; j++) {
            // Generate random number between 1 and 75
            int num = (rand() % 75) + 1;
            // Check if number already exists on the board
            int exists = 0;
            for(int k = 0; k < j; k++) {
                if(board[i][k] == num) {
                    exists = 1;
                    break;
                }
            }
            if(exists) {
                // If number already exists on board, generate a new one
                j--;
                continue;
            }
            // Add number to board
            board[i][j] = num;
        }
    }

    // Print out the Bingo board
    printf("B  I  N  G  O\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                // Print free space
                printf("   ");
            } else {
                // Print number
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }

    // Generate random numbers until someone wins
    int gameOver = 0;
    while(!gameOver) {
        // Generate random number between 1 and 75
        int num = (rand() % 75) + 1;
        printf("Number called: %d\n", num);
        // Check if number exists on board
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == num) {
                    // Mark number as called
                    board[i][j] = -1;
                    // Check for a win
                    int win = 0;
                    // Check rows for a win
                    for(int k = 0; k < ROWS; k++) {
                        if(board[k][0] == -1 && board[k][1] == -1 && board[k][2] == -1 && board[k][3] == -1 && board[k][4] == -1) {
                            // Row win
                            win = 1;
                            break;
                        }
                    }
                    if(win) {
                        printf("Row Bingo!\n");
                        gameOver = 1;
                        break;
                    }
                    // Check columns for a win
                    for(int k = 0; k < COLS; k++) {
                        if(board[0][k] == -1 && board[1][k] == -1 && board[2][k] == -1 && board[3][k] == -1 && board[4][k] == -1) {
                            // Column win
                            win = 1;
                            break;
                        }
                    }
                    if(win) {
                        printf("Column Bingo!\n");
                        gameOver = 1;
                        break;
                    }
                    // Check diagonals for a win
                    if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
                        // Diagonal win top-left to bottom-right
                        win = 1;
                    } else if(board[4][0] == -1 && board[3][1] == -1 && board[2][2] == -1 && board[1][3] == -1 && board[0][4] == -1) {
                        // Diagonal win bottom-left to top-right
                        win = 1;
                    }
                    if(win) {
                        printf("Diagonal Bingo!\n");
                        gameOver = 1;
                        break;
                    }
                }
                if(gameOver) {
                    break;
                }
            }
        }
    }

    return 0;
}