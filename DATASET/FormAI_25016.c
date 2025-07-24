//FormAI DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for the players
typedef struct Player {
    char name[20];
    int health;
    int score;
} Player;

// Function to print the player's status
void printStatus(Player player1, Player player2) {
    printf("%s's Health: %d\tScore: %d\n", player1.name, player1.health, player1.score);
    printf("%s's Health: %d\tScore: %d\n", player2.name, player2.health, player2.score);
}

int main() {
    // Banner
    printf("*************************************\n");
    printf("****** Sherlock Holmes' C Table ******\n");
    printf("*************************************\n\n");

    // Initialization
    printf("Welcome to Sherlock Holmes' C Table game!\n");
    printf("Please enter your names:\n");
    Player player1, player2;
    fgets(player1.name, 20, stdin);
    player1.name[strcspn(player1.name, "\n")] = 0;
    fgets(player2.name, 20, stdin);
    player2.name[strcspn(player2.name, "\n")] = 0;
    player1.health = 100;
    player2.health = 100;
    player1.score = 0;
    player2.score = 0;
    printf("%s vs %s. Let's begin!\n", player1.name, player2.name);

    // Loop
    srand((unsigned) time(NULL));
    while (player1.health > 0 && player2.health > 0) {
        int randomNum1 = rand() % 10 + 1;
        int randomNum2 = rand() % 10 + 1;
        printf("%s rolls a %d. ", player1.name, randomNum1);
        printf("%s rolls a %d. ", player2.name, randomNum2);
        if (randomNum1 > randomNum2) {
            player2.health -= randomNum1;
            player1.score += randomNum1;
            printf("%s deals %d damage to %s.\n", player1.name, randomNum1, player2.name);
        } else if (randomNum2 > randomNum1) {
            player1.health -= randomNum2;
            player2.score += randomNum2;
            printf("%s deals %d damage to %s.\n", player2.name, randomNum2, player1.name);
        } else {
            printf("The round ends in a draw.\n");
        }
        printStatus(player1, player2);
        printf("\n");
    }

    // Result
    printf("***** GAME OVER *****\n\n");
    if (player1.health <= 0) {
        printf("%s has won the game with a score of %d!\nBetter luck next time, %s.\n", player2.name, player2.score, player1.name);
    } else {
        printf("%s has won the game with a score of %d!\nBetter luck next time, %s.\n", player1.name, player1.score, player2.name);
    }

    return 0;
}