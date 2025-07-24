//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototype declarations
int fightEnemy(int playerHealth, int playerDamage, int enemyHealth, int enemyDamage);
int generateRandomNumber(int min, int max);

int main()
{
    srand(time(NULL)); // seed for random number generator
    int playerHealth = 100;
    int playerDamage = 10;
    int enemyHealth = generateRandomNumber(50, 100);
    int enemyDamage = generateRandomNumber(5, 15);
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer trying to explore a dangerous dungeon.\n");
    printf("You have %d health points and can deal %d damage.\n", playerHealth, playerDamage);
    printf("An enemy has appeared! You have to fight it!\n");
    printf("The enemy has %d health points and can deal %d damage.\n", enemyHealth, enemyDamage);
    
    int result = fightEnemy(playerHealth, playerDamage, enemyHealth, enemyDamage);
    if(result == 1) {
        printf("Congratulations! You have won the game!\n");
    } else {
        printf("Game over! You have lost the game!\n");
    }

    return 0;
}

// function to simulate combat between player and enemy
int fightEnemy(int playerHealth, int playerDamage, int enemyHealth, int enemyDamage)
{
    while(playerHealth > 0 && enemyHealth > 0) {
        // player attacks
        int playerAttackDamage = generateRandomNumber(playerDamage - 5, playerDamage + 5);
        enemyHealth -= playerAttackDamage;
        printf("You hit the enemy for %d damage.\n", playerAttackDamage);
        if(enemyHealth <= 0) {
            return 1; // player wins
        }
        
        // enemy attacks
        int enemyAttackDamage = generateRandomNumber(enemyDamage - 5, enemyDamage + 5);
        playerHealth -= enemyAttackDamage;
        printf("The enemy hits you for %d damage.\n", enemyAttackDamage);
        if(playerHealth <= 0) {
            return -1; // player loses
        }
    }
    
    return 0; // no winner
}

// function to generate random numbers within a range
int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}