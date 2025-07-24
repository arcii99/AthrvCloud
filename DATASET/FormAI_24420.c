//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function Prototypes
int rollDice();
int calculateShieldLevel(int level);
void displayOpeningMessage();
void displayEndingMessage(int finalScore);
void playGame();

int main()
{
    displayOpeningMessage();
    playGame();
    return 0;
}

// Function to roll a six-sided die and return the result
int rollDice()
{
    return (rand() % 6) + 1;
}

// Function to calculate shield level based on player level
int calculateShieldLevel(int level)
{
    return level * 5;
}

// Function to display opening message
void displayOpeningMessage()
{
    printf("Welcome to Procedural Space Adventure!\n");
    printf("In this game, you will embark on a journey through the galaxy, facing various challenges and obstacles along the way.\n");
    printf("Your goal is to reach the end of the game with the highest score possible.\n\n");
    printf("Press enter to start the game...\n");
    getchar();
}

// Function to display ending message and final score
void displayEndingMessage(int finalScore)
{
    printf("\nCongratulations, you have completed the game!\n");
    printf("Final Score: %d\n", finalScore);
}

// Function to play the game
void playGame()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize game variables
    int level = 1;
    int score = 0;
    int shieldLevel = calculateShieldLevel(level);

    printf("\nYou have entered level %d...\n", level);

    // Loop through game levels
    while (level <= 5)
    {
        // Prompt the player to roll the dice
        printf("Press enter to roll the dice...\n");
        getchar();

        // Roll the dice and display the result
        int rollResult = rollDice();
        printf("You rolled a %d!\n", rollResult);

        // Check if player can proceed or needs to fight space pirates
        if (rollResult < 4)
        {
            // Player encounters space pirates
            printf("\nOh no! You have encountered space pirates!\n");
            printf("The battle begins...\n\n");

            // Calculate enemy stats
            int enemyLevel = level + 1;
            int enemyShieldLevel = calculateShieldLevel(enemyLevel);
            int enemyAttackPower = enemyLevel * (rand() % 5 + 1);

            // Battle loop
            while (enemyShieldLevel > 0 && shieldLevel > 0)
            {
                // Player attack phase
                int attackPower = level * (rand() % 5 + 1);
                printf("You attack with a power of %d...\n", attackPower);
                enemyShieldLevel -= attackPower;
                printf("Enemy shield level: %d\n", enemyShieldLevel);

                // Check if enemy is defeated
                if (enemyShieldLevel <= 0)
                {
                    printf("\nCongratulations, you have defeated the space pirates!\n");
                    printf("Press enter to continue to the next level...\n");
                    getchar();
                    score += enemyLevel * 10;
                    level++;
                    shieldLevel = calculateShieldLevel(level);
                    printf("\nYou have entered level %d...\n", level);
                    break;
                }

                // Enemy attack phase
                printf("The enemy attacks with a power of %d...\n", enemyAttackPower);
                shieldLevel -= enemyAttackPower;
                printf("Your shield level: %d\n", shieldLevel);

                // Check if player is defeated
                if (shieldLevel <= 0)
                {
                    printf("\nOh no, you have been defeated by the space pirates...\n");
                    displayEndingMessage(score);
                    exit(0);
                }
            }
        }
        else
        {
            // Player can proceed safely
            printf("\nYou proceed safely to the next level...\n");
            score += level * 5;
            level++;
            shieldLevel = calculateShieldLevel(level);
            printf("Press enter to continue to level %d...\n", level);
            getchar();
            printf("\nYou have entered level %d...\n", level);
        }
    }

    // Player completes game successfully
    displayEndingMessage(score);
}