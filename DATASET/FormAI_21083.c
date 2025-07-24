//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice(void){
    srand(time(NULL));  // Initialize random seed
    return (rand() % 6) + 1;  // Return a random number between 1 and 6
}

int main(){
    int player1 = 0;  // Current position of player 1
    int player2 = 0;  // Current position of player 2

    // Game loop
    while (1){
        // Player 1's turn
        printf("Player 1's turn. Press enter to roll the dice...\n");
        getchar();  // Wait for the player to press enter
        int roll = rollDice();  // Roll the dice
        printf("Player 1 rolled a %d!\n", roll);
        player1 += roll;  // Move the player
        printf("Player 1 is now at position %d.\n", player1);

        // Check if player 1 has won
        if (player1 >= 50){
            printf("Congratulations! Player 1 has won!\n");
            break;  // Exit the game loop
        }

        // Player 2's turn
        printf("Player 2's turn. Press enter to roll the dice...\n");
        getchar();  // Wait for the player to press enter
        roll = rollDice();  // Roll the dice
        printf("Player 2 rolled a %d!\n", roll);
        player2 += roll;  // Move the player
        printf("Player 2 is now at position %d.\n", player2);

        // Check if player 2 has won
        if (player2 >= 50){
            printf("Congratulations! Player 2 has won!\n");
            break;  // Exit the game loop
        }
    }

    return 0;
}