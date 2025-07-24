//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between a minimum and maximum value */
int generateRandomNumber(int minValue, int maxValue)
{
    srand(time(0)); // Seed the random number generator with the current time
    return (rand() % (maxValue - minValue + 1)) + minValue;
}

int main()
{
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerAttack;
    int enemyAttack;

    printf("Welcome to Medieval Combat!\n");

    while (playerHealth > 0 && enemyHealth > 0)
    {
        printf("\nYour health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);

        // Player's turn
        printf("\nIt's your turn to attack!\n");
        playerAttack = generateRandomNumber(10, 20); // Player can attack for between 10 and 20 damage
        printf("You attack the enemy for %d damage!\n", playerAttack);
        enemyHealth -= playerAttack;

        // Check if the enemy is still alive after the player's attack
        if (enemyHealth <= 0)
        {
            printf("\nCongratulations! You defeated the enemy!\n");
            break;
        }

        // Enemy's turn
        printf("\nIt's the enemy's turn to attack!\n");
        enemyAttack = generateRandomNumber(5, 15); // Enemy can attack for between 5 and 15 damage
        printf("The enemy attacks you for %d damage!\n", enemyAttack);
        playerHealth -= enemyAttack;

        // Check if the player is still alive after the enemy's attack
        if (playerHealth <= 0)
        {
            printf("\nGame over! The enemy defeated you.\n");
            break;
        }
    }

    return 0;
}