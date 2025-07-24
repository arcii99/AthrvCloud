//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Declare game variables
    int playerHealth = 100;
    int enemyHealth = getRandomInt(50, 100);
    int playerDamage = 20;
    int enemyDamage = getRandomInt(10, 25);
    int round = 1;

    // Print game intro
    printf("Welcome to the post-apocalyptic game!\n");
    printf("You are the last survivor of a deadly virus that has wiped out most of humanity.\n");
    printf("Your goal is to defeat the enemy and survive as long as possible.\n");

    // Game loop
    while (playerHealth > 0 && enemyHealth > 0) {
        // Print round information
        printf("\nRound %d\n", round);
        printf("Player Health: %d\n", playerHealth);
        printf("Enemy Health: %d\n", enemyHealth);

        // Player attacks enemy
        printf("You attack the enemy and deal %d damage.\n", playerDamage);
        enemyHealth -= playerDamage;

        // Check if enemy is defeated
        if (enemyHealth <= 0) {
            printf("You have defeated the enemy!\n");
            break;
        }

        // Enemy attacks player
        printf("The enemy attacks you and deals %d damage.\n", enemyDamage);
        playerHealth -= enemyDamage;

        // Check if player is defeated
        if (playerHealth <= 0) {
            printf("You have been defeated by the enemy.\n");
            break;
        }

        // Increase round counter
        round++;
    }

    // Print final game status
    printf("\nFinal Game Status\n");
    printf("Player Health: %d\n", playerHealth);
    printf("Enemy Health: %d\n", enemyHealth);

    // End game
    return 0;
}