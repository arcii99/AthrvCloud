//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to simulate a random attack from the enemy
int randomAttack()
{
    int damage = rand() % 20 + 5; //Randomly generates a number between 5 and 25 as damage
    printf("\nThe enemy attacks and deals %d damage.\n", damage);
    return damage;
}

int main()
{
    srand(time(NULL)); //Seed the random number generator

    //Game Introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer who has entered a dangerous dungeon.\n");
    printf("Your goal is to find the treasure and get out alive.\n\n");

    //Player Stats
    int playerHealth = 100;
    int playerDamage = rand() % 10 + 5; //Randomly generates a number between 5 and 15 as damage
    printf("Your starting health is %d.\n", playerHealth);
    printf("Your weapon deals %d damage.\n\n", playerDamage);

    //Enemy Stats
    int enemyHealth = 50;
    printf("You encounter an enemy with %d health!\n", enemyHealth);

    //Game Loop
    while (playerHealth > 0 && enemyHealth > 0) //Loop while neither the player nor the enemy have died
    {
        //Player Turn
        printf("It is your turn to attack! Press Enter to continue.\n");
        getchar(); //Waits for the user to press Enter
        int playerAttack = rand() % 10 + 5; //Randomly generates a number between 5 and 15 as damage
        printf("\nYou attack and deal %d damage.\n", playerAttack);
        enemyHealth -= playerAttack;

        //Check if the enemy is still alive
        if (enemyHealth <= 0)
        {
            printf("\nCongratulations adventurer, you have defeated the enemy!\n");
            printf("Press Enter to continue your quest.\n");
            getchar();
            break; //Exit the loop if the enemy is dead
        }

        //Enemy Turn
        int enemyAttack = randomAttack(); //Simulate a random attack from the enemy
        playerHealth -= enemyAttack;

        //Check if the player is still alive
        if (playerHealth <= 0)
        {
            printf("\nGame over adventurer, you have been defeated!\n");
            printf("Press Enter to exit the game.\n");
            getchar();
            return 0; //Exit the program if the player is dead
        }

        //Print Stats
        printf("\nYour health is now %d.\n", playerHealth);
        printf("The enemy's health is now %d.\n", enemyHealth);
    }

    //Game Over
    printf("\nYou have reached the end of the dungeon and found the treasure! Congratulations!\n");
    printf("Press Enter to exit the game.\n");
    getchar();
    return 0;
}