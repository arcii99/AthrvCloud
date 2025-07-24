//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Set the game board dimensions
    int numRows = 6;
    int numCols = 7;
    
    // Create the game board (2D array)
    int board[numRows][numCols];
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            board[i][j] = 0;
        }
    }

    // Display the initial empty game board
    printf("Initial Game Board:\n");
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Set the player tokens
    int player1Token = 1;
    int player2Token = 2;

    // Keep track of the current player
    int currentPlayer = player1Token;

    // Start the game loop
    int isGameOver = 0;
    while(!isGameOver) {
        // Prompt the current player for their move
        printf("Player %d, enter your move (column number from 1-7): ", currentPlayer);
        int chosenColumn;
        scanf("%d", &chosenColumn);
        chosenColumn--; // adjust for 0-based indexing

        // Check if the chosen column is valid
        if(chosenColumn < 0 || chosenColumn >= numCols) {
            printf("Invalid column number. Please choose a number from 1-7.\n");
            continue;
        }

        // Check if the chosen column is full
        if(board[0][chosenColumn] != 0) {
            printf("Column is full. Try again.\n");
            continue;
        }

        // Drop the token into the chosen column
        for(int i=numRows-1; i>=0; i--) {
            if(board[i][chosenColumn] == 0) {
                board[i][chosenColumn] = currentPlayer;
                break;
            }
        }

        // Display the updated game board
        printf("\nUpdated Game Board:\n");
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<numCols; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Check for a winning move
        // Check columns
        for(int j=0; j<numCols; j++) {
            for(int i=0; i<numRows-3; i++) {
                if(board[i][j] == currentPlayer && 
                   board[i+1][j] == currentPlayer &&
                   board[i+2][j] == currentPlayer &&
                   board[i+3][j] == currentPlayer) {
                       printf("Player %d wins!\n", currentPlayer);
                       isGameOver = 1;
                       break;
                }
            }
        }

        // Check rows
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<numCols-3; j++) {
                if(board[i][j] == currentPlayer && 
                   board[i][j+1] == currentPlayer &&
                   board[i][j+2] == currentPlayer &&
                   board[i][j+3] == currentPlayer) {
                       printf("Player %d wins!\n", currentPlayer);
                       isGameOver = 1;
                       break;
                }
            }
        }

        // Check diagonals (left-to-right)
        for(int i=0; i<numRows-3; i++) {
            for(int j=0; j<numCols-3; j++) {
                if(board[i][j] == currentPlayer && 
                   board[i+1][j+1] == currentPlayer &&
                   board[i+2][j+2] == currentPlayer &&
                   board[i+3][j+3] == currentPlayer) {
                       printf("Player %d wins!\n", currentPlayer);
                       isGameOver = 1;
                       break;
                }
            }
        }

        // Check diagonals (right-to-left)
        for(int i=0; i<numRows-3; i++) {
            for(int j=3; j<numCols; j++) {
                if(board[i][j] == currentPlayer && 
                   board[i+1][j-1] == currentPlayer &&
                   board[i+2][j-2] == currentPlayer &&
                   board[i+3][j-3] == currentPlayer) {
                       printf("Player %d wins!\n", currentPlayer);
                       isGameOver = 1;
                       break;
                }
            }
        }

        // Check for a tie game
        int isTieGame = 1;
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<numCols; j++) {
                if(board[i][j] == 0) {
                    isTieGame = 0; // there is a free space, so it's not a tie game
                    break;
                }
            }
            if(!isTieGame) {
                break;
            }
        }
        if(isTieGame) {
            printf("Tie game!\n");
            isGameOver = 1;
        }

        // Switch the current player
        if(currentPlayer == player1Token) {
            currentPlayer = player2Token;
        } else {
            currentPlayer = player1Token;
        }
    }

    return 0;
}