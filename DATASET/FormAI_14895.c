//FormAI DATASET v1.0 Category: Table Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1-6
int rollDice() {
    int randNum = rand() % 6 + 1;
    return randNum;
}

// Function to play the game
void playGame() {
    int player1Pos = 0; // Starting position of player 1
    int player2Pos = 0; // Starting position of player 2
    int turn = 1; // Start with player 1's turn
    int diceRoll = 0;
    
    // Loop until a player reaches the final position of 100
    while (player1Pos < 100 && player2Pos < 100) {
        printf("Player %d's turn\n", turn);
        printf("Press enter to roll dice...");
        getchar(); // Wait for user to press enter
        diceRoll = rollDice(); // Generate a random dice roll
        
        printf("You rolled a %d\n", diceRoll);
        
        // Update position of current player
        if (turn == 1) {
            player1Pos += diceRoll;
        } else {
            player2Pos += diceRoll;
        }
        
        // Check if player landed on a ladder
        if (player1Pos == 8) {
            player1Pos = 15;
            printf("Player 1 climbed a ladder! Now at position 15\n");
        } else if (player1Pos == 33) {
            player1Pos = 42;
            printf("Player 1 climbed a ladder! Now at position 42\n");
        } else if (player1Pos == 49) {
            player1Pos = 58;
            printf("Player 1 climbed a ladder! Now at position 58\n");
        } else if (player1Pos == 68) {
            player1Pos = 85;
            printf("Player 1 climbed a ladder! Now at position 85\n");
        } else if (player1Pos == 77) {
            player1Pos = 97;
            printf("Player 1 climbed a ladder! Now at position 97\n");
        } else if (player1Pos == 96) {
            player1Pos = 65;
            printf("Player 1 landed on a snake! Now at position 65\n");
        } else if (player1Pos == 87) {
            player1Pos = 49;
            printf("Player 1 landed on a snake! Now at position 49\n");
        } else if (player1Pos == 62) {
            player1Pos = 22;
            printf("Player 1 landed on a snake! Now at position 22\n");
        } else if (player1Pos == 56) {
            player1Pos = 8;
            printf("Player 1 landed on a snake! Now at position 8\n");
        } else if (player1Pos == 99) {
            printf("\nPlayer 1 wins!\n");
            return;
        }
        
        // Check if player landed on a ladder
        if (player2Pos == 8) {
            player2Pos = 15;
            printf("Player 2 climbed a ladder! Now at position 15\n");
        } else if (player2Pos == 33) {
            player2Pos = 42;
            printf("Player 2 climbed a ladder! Now at position 42\n");
        } else if (player2Pos == 49) {
            player2Pos = 58;
            printf("Player 2 climbed a ladder! Now at position 58\n");
        } else if (player2Pos == 68) {
            player2Pos = 85;
            printf("Player 2 climbed a ladder! Now at position 85\n");
        } else if (player2Pos == 77) {
            player2Pos = 97;
            printf("Player 2 climbed a ladder! Now at position 97\n");
        } else if (player2Pos == 96) {
            player2Pos = 65;
            printf("Player 2 landed on a snake! Now at position 65\n");
        } else if (player2Pos == 87) {
            player2Pos = 49;
            printf("Player 2 landed on a snake! Now at position 49\n");
        } else if (player2Pos == 62) {
            player2Pos = 22;
            printf("Player 2 landed on a snake! Now at position 22\n");
        } else if (player2Pos == 56) {
            player2Pos = 8;
            printf("Player 2 landed on a snake! Now at position 8\n");
        } else if (player2Pos == 99) {
            printf("\nPlayer 2 wins!\n");
            return;
        }
        
        printf("Player 1 is at position %d\n", player1Pos);
        printf("Player 2 is at position %d\n", player2Pos);
        
        // Switch turn to other player
        if (turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    printf("\nWelcome to the Ladder and Snake game!\n\n");
    printf("You will play as two players and race to the finish line of 100.\n");
    printf("If you land on a ladder, you will automatically climb up to a higher position.\n");
    printf("If you land on a snake, you will slide down to a lower position.\n\n");
    printf("Press enter to start game...");
    getchar(); // Wait for user to press enter
    
    playGame();
    
    return 0;
}