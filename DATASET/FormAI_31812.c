//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Set up the random seed
    srand(time(NULL));

    // Initialize player and enemy health
    int playerHealth = 100;
    int enemyHealth = 100;

    // Initialize player attack and defense
    int playerAttack = rollDice();
    int playerDefense = rollDice() + 2;

    // Initialize enemy attack and defense
    int enemyAttack = rollDice();
    int enemyDefense = rollDice() + 1;

    // Main game loop
    while (playerHealth > 0 && enemyHealth > 0) {
        // Player's turn
        printf("Player's turn:\n");
        printf("Player attacks with a strength of %d\n", playerAttack);
        printf("Enemy defends with a strength of %d\n", enemyDefense);
        int damage = playerAttack - enemyDefense;
        if (damage < 0) {
            damage = 0;
        }
        printf("Player deals %d damage to the enemy\n", damage);
        enemyHealth -= damage;
        if (enemyHealth <= 0) {
            printf("Player wins!\n");
            break;
        }

        // Enemy's turn
        printf("\nEnemy's turn:\n");
        printf("Enemy attacks with a strength of %d\n", enemyAttack);
        printf("Player defends with a strength of %d\n", playerDefense);
        damage = enemyAttack - playerDefense;
        if (damage < 0) {
            damage = 0;
        }
        printf("Enemy deals %d damage to the player\n", damage);
        playerHealth -= damage;
        if (playerHealth <= 0) {
            printf("Enemy wins!\n");
            break;
        }

        // Print out the current stats
        printf("\nPlayer health: %d\n", playerHealth);
        printf("Enemy health: %d\n\n", enemyHealth);

        // Roll new attack and defense for both the player and the enemy
        playerAttack = rollDice() + 1;
        playerDefense = rollDice() + 3;
        enemyAttack = rollDice() + 1;
        enemyDefense = rollDice() + 2;
    }

    // Game over
    printf("Game over\n");

    return 0;
}