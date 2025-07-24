//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerAttack;
    int enemyAttack;

    printf("Welcome to the Medieval Battle Arena!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("Player Health: %d\n", playerHealth);
        printf("Enemy Health: %d\n\n", enemyHealth);

        // Player's turn to attack
        printf("It's your turn to attack!\n");
        playerAttack = getRandomNumber(10, 20);
        printf("You attacked the enemy for %d damage.\n", playerAttack);
        enemyHealth -= playerAttack;

        // Check if the enemy is defeated
        if (enemyHealth <= 0) {
            printf("Congratulations! You defeated the enemy.\n");
            break;
        }

        // Enemy's turn to attack
        printf("The enemy is now attacking!\n");
        enemyAttack = getRandomNumber(5, 15);
        printf("The enemy attacked for %d damage.\n", enemyAttack);
        playerHealth -= enemyAttack;

        // Check if the player is defeated
        if (playerHealth <= 0) {
            printf("You have been defeated by the enemy.\n");
            break;
        }
    }

    printf("Game Over!\n");

    return 0;
}