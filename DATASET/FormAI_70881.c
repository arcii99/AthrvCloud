//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int rollDice();
void printBoard(int player1, int player2, int currentPlayer);
int movePlayer(int playerPosition, int diceRoll);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the player positions and current player
    int player1 = 0;
    int player2 = 0;
    int currentPlayer = 1;
    
    // Print the starting board
    printBoard(player1, player2, currentPlayer);
    
    // Game loop
    while (player1 < 100 && player2 < 100) {
        // Roll the dice and move the player
        int diceRoll = rollDice();
        if (currentPlayer == 1) {
            player1 = movePlayer(player1, diceRoll);
        } else {
            player2 = movePlayer(player2, diceRoll);
        }
        
        // Switch to the other player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        
        // Print the updated board
        printBoard(player1, player2, currentPlayer);
    }
    
    // Determine the winner and print the end message
    if (player1 >= 100) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
    
    return 0;
}

int rollDice() {
    // Generate a random number between 1 and 6
    return rand() % 6 + 1;
}

void printBoard(int player1, int player2, int currentPlayer) {
    // Clear the screen
    system("cls");
    
    // Print the board
    printf("------------------------------------------------------\n");
    for (int row = 10; row > 0; row--) {
        for (int col = 1; col <= 10; col++) {
            int position = row * 10;
            if (col % 2 == 0) {
                position += 10 - col + 1;
            } else {
                position += col - 1;
            }
            if (position == player1 && position == player2) {
                printf("| P1/P2 ");
            } else if (position == player1) {
                printf("|   P1   ");
            } else if (position == player2) {
                printf("|   P2   ");
            } else {
                printf("|        ");
            }
        }
        printf("|\n");
        printf("|        |        |        |        |        |        |\n");
        printf("|--------+--------+--------+--------+--------+--------|\n");
    }
    printf("------------------------------------------------------\n");
    
    // Print the current player
    printf("Current player: %d\n\n", currentPlayer);
}

int movePlayer(int playerPosition, int diceRoll) {
    playerPosition += diceRoll;
    
    // Check for special squares
    if (playerPosition == 6) {
        playerPosition = 17;
    } else if (playerPosition == 12) {
        playerPosition = 25;
    } else if (playerPosition == 21) {
        playerPosition = 3;
    } else if (playerPosition == 31) {
        playerPosition = 19;
    } else if (playerPosition == 44) {
        playerPosition = 8;
    } else if (playerPosition == 62) {
        playerPosition = 42;
    } else if (playerPosition == 71) {
        playerPosition = 50;
    } else if (playerPosition == 82) {
        playerPosition = 58;
    } else if (playerPosition == 88) {
        playerPosition = 92;
    } else if (playerPosition == 99) {
        playerPosition = 65;
    } else if (playerPosition > 100) {
        playerPosition = 100 - (playerPosition - 100);
    }
    
    return playerPosition;
}