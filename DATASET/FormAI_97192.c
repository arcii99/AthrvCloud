//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize player positions to 1
    int player1Pos = 1;
    int player2Pos = 1;
    
    // Initialize game board
    int board[100];
    for (int i = 0; i < 100; i++) {
        board[i] = 0;
    }
    
    // Set up board traps
    board[5] = -1;
    board[15] = -2;
    board[25] = -3;
    board[35] = -4;
    board[45] = -5;
    board[55] = -6;
    board[65] = -7;
    board[75] = -8;
    board[85] = -9;
    board[95] = -10;
    
    // Initialize game flag
    int gameEnd = 0;
    
    // Start game loop
    while (!gameEnd) {
        // Player 1 turn
        int roll = rollDice();
        printf("Player 1 rolled a %d\n", roll);
        player1Pos += roll;
        
        // Check for out of bounds
        if (player1Pos > 100) {
            player1Pos = 100 - (player1Pos - 100);
        }
        
        // Check for traps
        if (board[player1Pos - 1] != 0) {
            printf("Player 1 landed on a trap and slid down to position %d\n", player1Pos + board[player1Pos - 1]);
            player1Pos += board[player1Pos - 1];
        }
        
        // Check for win
        if (player1Pos == 100) {
            printf("Player 1 has won the game!\n");
            gameEnd = 1;
            break;
        }
        
        // Player 2 turn
        roll = rollDice();
        printf("Player 2 rolled a %d\n", roll);
        player2Pos += roll;
        
        // Check for out of bounds
        if (player2Pos > 100) {
            player2Pos = 100 - (player2Pos - 100);
        }
        
        // Check for traps
        if (board[player2Pos - 1] != 0) {
            printf("Player 2 landed on a trap and slid down to position %d\n", player2Pos + board[player2Pos - 1]);
            player2Pos += board[player2Pos - 1];
        }
        
        // Check for win
        if (player2Pos == 100) {
            printf("Player 2 has won the game!\n");
            gameEnd = 1;
            break;
        }
    }
    
    return 0;
}