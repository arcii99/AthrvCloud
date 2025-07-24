//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declarations */
void game();
void printMap(int playerX, int playerY, int mapSize);
int movePlayer(char direction, int *playerX, int *playerY, int mapSize);
int checkLocation(int x, int y, int mapSize);
void generateEnemy(int *eX, int *eY, int mapSize);
int fight(int playerX, int playerY, int eX, int eY, int mapSize);

/* Main function */
int main()
{
    char choice;
    srand(time(NULL)); // Seed the random number generator

    do {
        game();
        printf("\n\nPlay again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("Thanks for playing!");

    return 0;
}

/* Game function */
void game()
{
    int mapSize = 10;
    int playerX = mapSize/2;
    int playerY = mapSize/2;

    printf("Welcome to the post-apocalyptic game!\n\n");
    printf("The world is a dangerous place, and you are trapped in it.\n");
    printf("Your goal is to survive as long as possible.\n\n");

    while(1) {
        printMap(playerX, playerY, mapSize);
        printf("Enter a direction to move (W/A/S/D): ");
        char direction;
        scanf(" %c", &direction);

        if (movePlayer(direction, &playerX, &playerY, mapSize))
        {
            printf("\nYou have encountered an enemy!\n");
            int eX, eY;
            generateEnemy(&eX, &eY, mapSize);
            if (fight(playerX, playerY, eX, eY, mapSize)) {
                printf("\nYou won the battle!\n");
            } else {
                printf("\nYou lost the battle :(\n\nGAME OVER\n");
                return;
            }
        }
    }
}

/* Function to print the map */
void printMap(int playerX, int playerY, int mapSize)
{
    int i, j;
    for (i=0; i<mapSize; i++) {
        for (j=0; j<mapSize; j++) {
            if (i==playerY && j==playerX) {
                printf("P ");
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }
}

/* Function to move the player */
int movePlayer(char direction, int *playerX, int *playerY, int mapSize)
{
    int newX, newY;

    switch(direction) {
        case 'W': // Move Up
            newX = *playerX;
            newY = *playerY - 1;
            break;
        case 'A': // Move Left
            newX = *playerX - 1;
            newY = *playerY;
            break;
        case 'S': // Move Down
            newX = *playerX;
            newY = *playerY + 1;
            break;
        case 'D': // Move Right
            newX = *playerX + 1;
            newY = *playerY;
            break;
        default:
            printf("\nInvalid direction. Try again.\n\n");
            return 0;
    }

    if (checkLocation(newX, newY, mapSize)) {
        *playerX = newX;
        *playerY = newY;
        return 1; // Player moved to new location
    } else {
        printf("\nYou hit a wall. Try again.\n\n");
        return 0; // Player did not move
    }
}

/* Function to check if new location is valid */
int checkLocation(int x, int y, int mapSize)
{
    if (x>=0 && x<mapSize && y>=0 && y<mapSize) {
        return 1; // Location is valid
    } else {
        return 0; // Location is invalid
    }
}

/* Function to generate an enemy */
void generateEnemy(int *eX, int *eY, int mapSize)
{
    *eX = rand() % mapSize;
    *eY = rand() % mapSize;
}

/* Function to initiate a fight */
int fight(int playerX, int playerY, int eX, int eY, int mapSize)
{
    int playerHealth = 100;
    int eHealth = 100;

    while(playerHealth > 0 && eHealth > 0) {
        printf("\nPlayer Health: %d\nEnemy Health: %d\n", playerHealth, eHealth);
        printf("Choose an action:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Attack
                eHealth -= rand() % 10 + 1;
                break;
            case 2: // Defend
                playerHealth += rand() % 5 + 1;
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
                continue;
        }

        int enemyAction = rand() % 2; // 0 for attack, 1 for defend

        if (enemyAction == 0) { // Enemy attacks
            playerHealth -= rand() % 10 + 1;
        } else { // Enemy defends
            eHealth += rand() % 5 + 1;
        }
    }

    if (playerHealth > 0) {
        return 1; // Player wins
    } else {
        return 0; // Enemy wins
    }
}