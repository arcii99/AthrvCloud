//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int rollDice();
void printBoard(int player1, int player2, int currentPlayer);
int movePlayer(int player, int roll);
int checkWin(int player);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int player1 = 0, player2 = 0; // Tracks player positions
    int currentPlayer = 1; // 1 represents player 1, 2 represents player 2
    int roll = 0; // Stores the current roll of the dice
    
    // Loop until a player wins
    while (checkWin(player1) == 0 && checkWin(player2) == 0) {
        // Clear the console
        system("clear");
        
        // Print the board
        printBoard(player1, player2, currentPlayer);
        
        // Roll the dice
        roll = rollDice();
        printf("Player %d rolled a %d.\n", currentPlayer, roll);
        
        // Move the player
        if (currentPlayer == 1) {
            player1 = movePlayer(player1, roll);
        } else {
            player2 = movePlayer(player2, roll);
        }
        
        // Switch to the next player
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
        
        // Wait for 1 second before continuing
        sleep(1);
    }
    
    // Announce the winner
    if (checkWin(player1) == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
    
    return 0;
}

// Rolls a six-sided dice and returns the result
int rollDice() {
    return (rand() % 6) + 1;
}

// Prints the game board to the console
void printBoard(int player1, int player2, int currentPlayer) {
    printf("Current player: %d\n", currentPlayer);
    
    // Print the board
    printf("+");
    for (int i = 0; i < 30; i++) {
        printf("-");
    }
    printf("+\n");
    
    for (int i = 10; i >= 1; i--) {
        printf("|");
        for (int j = 1; j <= 30; j++) {
            if (i == player1 && j == 15) {
                printf("1");
            } else if (i == player2 && j == 15) {
                printf("2");
            } else if (i == 1 && j == 15) {
                printf("S");
            } else if (i == 10 && j == 15) {
                printf("F");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    
    printf("+");
    for (int i = 0; i < 30; i++) {
        printf("-");
    }
    printf("+\n");
}

// Moves the player the specified number of spaces and returns the new position
int movePlayer(int player, int roll) {
    player += roll;
    
    // Check if the player reached the finish line
    if (player >= 10) {
        player = 10;
    }
    
    return player;
}

// Returns 1 if the player reached the finish line, 0 otherwise
int checkWin(int player) {
    if (player == 10) {
        return 1;
    } else {
        return 0;
    }
}