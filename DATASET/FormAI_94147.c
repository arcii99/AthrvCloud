//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Declare a struct to hold information about the player
typedef struct {
    char name[20];
    int score;
} Player;

// Error handling function to check for valid inputs
void error_check(int input) {
    if (input < 0 || input > 10) { // Check if input is within range
        printf("Invalid input! Please enter a number between 0 and 10.\n");
        exit(1);
    }
}

int main() {
    Player player1, player2;
    printf("Player 1, enter your name: ");
    scanf("%s", player1.name);
    printf("Player 2, enter your name: ");
    scanf("%s", player2.name);

    // Ask for player1's score input and perform error handling
    int p1_score;
    printf("%s, enter your score (0-10): ");
    scanf("%d", &p1_score);
    error_check(p1_score);
    player1.score = p1_score;

    // Ask for player2's score input and perform error handling
    int p2_score;
    printf("%s, enter your score (0-10): ");
    scanf("%d", &p2_score);
    error_check(p2_score);
    player2.score = p2_score;

    // Compare the scores and print the winner
    if (player1.score > player2.score) {
        printf("%s wins with a score of %d!\n", player1.name, player1.score);
    } else if (player2.score > player1.score) {
        printf("%s wins with a score of %d!\n", player2.name, player2.score);
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}