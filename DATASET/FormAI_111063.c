//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>

// Gameboard is a 3x3 grid of characters. '_' indicates empty space.
char gameboard[3][3] = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
};

// Display the current state of the gameboard.
void displayGameBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", gameboard[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won the game.
int checkForWin(char player) {
    // Check rows for win
    for (int i = 0; i < 3; i++) {
        if (gameboard[i][0] == player && gameboard[i][1] == player && gameboard[i][2] == player) {
            return 1;
        }
    }
    // Check columns for win
    for (int j = 0; j < 3; j++) {
        if (gameboard[0][j] == player && gameboard[1][j] == player && gameboard[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals for win
    if (gameboard[0][0] == player && gameboard[1][1] == player && gameboard[2][2] == player) {
        return 1;
    }
    if (gameboard[2][0] == player && gameboard[1][1] == player && gameboard[0][2] == player) {
        return 1;
    }
    return 0;
}

int main() {
    int numPlayers = 2;
    int currentPlayer = 1;
    int player1Score = 0;
    int player2Score = 0;
    
    while (player1Score < 3 && player2Score < 3) { // Best of 5 games
        printf("Player %d's turn.\n", currentPlayer);
        displayGameBoard();
        
        // Get player's move
        int row, col;
        printf("Enter the row and column (separated by a space) to place your %c: ", currentPlayer == 1 ? 'X' : 'O');
        scanf("%d %d", &row, &col);
        while (gameboard[row][col] != '_') { // Make sure the space is empty
            printf("That space is already taken. Please choose another space: ");
            scanf("%d %d", &row, &col);
        }
        
        // Place player's symbol on the gameboard
        gameboard[row][col] = currentPlayer == 1 ? 'X' : 'O';
        
        // Check for win
        if (checkForWin(currentPlayer == 1 ? 'X' : 'O')) {
            printf("Player %d wins!\n", currentPlayer);
            if (currentPlayer == 1) {
                player1Score++;
            } else {
                player2Score++;
            }
            printf("Player 1: %d | Player 2: %d\n", player1Score, player2Score);
            // Reset gameboard for next round
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    gameboard[i][j] = '_';
                }
            }
        } else { // No win, switch to other player's turn
            currentPlayer = currentPlayer == 1 ? 2 : 1;
        }
    }
    
    // Game over, declare winner
    if (player1Score == 3) {
        printf("Player 1 wins the game!\n");
    } else {
        printf("Player 2 wins the game!\n");
    }
    
    return 0;
}