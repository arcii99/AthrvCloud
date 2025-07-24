//FormAI DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerCount, p, i, j; // Declare variables
    printf("Welcome to the C Table Game!\n");
    printf("How many players would you like? (2-5): ");
    scanf("%d", &playerCount); // User inputs number of players
    while (playerCount < 2 || playerCount > 5) { // Ensure valid input
        printf("Invalid input. Please enter a number between 2 and 5: ");
        scanf("%d", &playerCount);
    }
    printf("\nGreat! Let's begin.\n");
    int playerHands[playerCount][6]; // Create table to hold player hands
    for (p = 0; p < playerCount; p++) { // For each player
        printf("\nPlayer %d's turn.\n", p+1);
        for (i = 0; i < 6; i++) { // Draw 6 cards
            playerHands[p][i] = rand() % 101; // Assign random integer between 0 and 100 to player's hand
            printf("You drew a %d.\n", playerHands[p][i]);
        }
        int score = 0;
        for (j = 0; j < 6; j++) { // Calculate player's score
            if (playerHands[p][j] % 2 == 0) { // If card is even
                score += playerHands[p][j]; // Add card value to score
            } else { // If card is odd
                score -= playerHands[p][j]; // Subtract card value from score
            }
        }
        printf("Your score is %d.\n", score);
    }
    printf("\nGame over!\n"); // Print game over message
    return 0; // End program
}