//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define constants for game settings
#define MAX_ENEMIES 10
#define MAX_ENEMY_HEALTH 50
#define MAX_PLAYER_HEALTH 100
#define DAMAGE_PER_HIT 10

//Function prototypes
void printTitleScreen();
void generateEnemies(int numEnemies, int *enemyHealth);
int playerTurn(int *enemyHealth, int numEnemies);
int enemyTurn(int *playerHealth, int numEnemies, int *enemyHealth);

//Main function
int main()
{
    //Initialize random seed
    srand(time(NULL));

    //Print title screen
    printTitleScreen();

    //Generate enemies
    int enemyHealth[MAX_ENEMIES];
    generateEnemies(MAX_ENEMIES, enemyHealth);

    //Initialize player health
    int playerHealth = MAX_PLAYER_HEALTH;

    //Start game loop
    int numEnemies = MAX_ENEMIES;
    while (numEnemies > 0 && playerHealth > 0)
    {
        //Print status
        printf("\n\nPlayer health: %d\n", playerHealth);
        printf("Number of enemies: %d\n", numEnemies);

        //Player turn
        int damageDealt = playerTurn(enemyHealth, numEnemies);
        printf("\nYou dealt %d damage!\n", damageDealt);

        //Check for defeated enemies
        int i;
        for (i = 0; i < numEnemies; i++)
        {
            if (enemyHealth[i] <= 0)
            {
                printf("\nEnemy %d defeated!\n", i+1);
                numEnemies--;
            }
        }

        //Enemy turn
        int damageTaken = enemyTurn(&playerHealth, numEnemies, enemyHealth);
        printf("\nThe enemies dealt %d damage!\n", damageTaken);
    }

    //Game over
    if (playerHealth <= 0)
    {
        printf("\n\nGame over! You were defeated by the enemies.\n");
    }
    else
    {
        printf("\n\nCongratulations! You have defeated all the enemies.\n");
    }

    return 0;
}

//Function for printing the title screen
void printTitleScreen()
{
    printf("\n");
    printf("    _____                        _______ _            \n");
    printf("   / ____|                      |__   __| |           \n");
    printf("  | |  __ _ __ ___  ___  ___      | |  | |__   __ _ \n");
    printf("  | | |_ | '__/ _ \\/ __|/ _ \\     | |  | '_ \\ / _` |\n");
    printf("  | |__| | | | (_) \\__ \\  __/     | |  | | | | (_| |\n");
    printf("   \\_____|_|  \\___/|___/\\___|     |_|  |_| |_|\\__,_|\n");
    printf("\n\n");
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the only survivor of a crashed spaceship,\n");
    printf("and you must defeat all the enemies in order to escape.\n\n");
}

//Function for generating enemies
void generateEnemies(int numEnemies, int *enemyHealth)
{
    printf("Generating enemies...\n");

    int i;
    for (i = 0; i < numEnemies; i++)
    {
        enemyHealth[i] = rand() % MAX_ENEMY_HEALTH + 1;
        printf("Enemy %d: %d health\n", i+1, enemyHealth[i]);
    }
}

//Function for the player's turn
int playerTurn(int *enemyHealth, int numEnemies)
{
    int damageDealt = DAMAGE_PER_HIT;

    printf("\nYour turn! Which enemy do you want to attack?\n");

    int choice;
    do
    {
        printf("Enter a number between 1 and %d: ", numEnemies);
        scanf("%d", &choice);
    }
    while (choice < 1 || choice > numEnemies);

    enemyHealth[choice-1] -= damageDealt;

    return damageDealt;
}

//Function for the enemy's turn
int enemyTurn(int *playerHealth, int numEnemies, int *enemyHealth)
{
    int damageTaken = 0;

    int i;
    for (i = 0; i < numEnemies; i++)
    {
        if (enemyHealth[i] > 0)
        {
            int damage = rand() % MAX_ENEMY_HEALTH/2 + 1;
            damageTaken += damage;
            *playerHealth -= damage;
        }
    }

    return damageTaken;
}