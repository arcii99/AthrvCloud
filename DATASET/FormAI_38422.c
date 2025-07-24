//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Map of the game world
    char map[3][5] =
    {
        { 'F', 'F', 'F', 'F', 'F' },
        { 'F', 'P', 'F', 'T', 'F' },
        { 'F', 'F', 'F', 'F', 'F' }
    };

    // Player's initial position
    int playerX = 1;
    int playerY = 1;

    // Welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Your mission is to find the treasure chest and bring it back to the starting point.\n");
    printf("You can use the following commands:\n");
    printf("- north\n");
    printf("- east\n");
    printf("- south\n");
    printf("- west\n");

    // Main game loop
    while (1)
    {
        // Print the current map with the player's position
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i == playerY && j == playerX)
                    printf("X ");
                else
                    printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        // Check if the player has reached the treasure chest
        if (playerX == 3 && playerY == 1)
        {
            printf("Congratulations! You have found the treasure chest!\n");
            break;
        }

        // Get the player's input
        char input[10];
        printf("> ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = 0;

        // Move the player according to the input
        if (strcmp(input, "north") == 0)
        {
            if (playerY > 0 && map[playerY - 1][playerX] != 'F')
                playerY--;
            else
                printf("You cannot move north.\n");
        }
        else if (strcmp(input, "east") == 0)
        {
            if (playerX < 4 && map[playerY][playerX + 1] != 'F')
                playerX++;
            else
                printf("You cannot move east.\n");
        }
        else if (strcmp(input, "south") == 0)
        {
            if (playerY < 2 && map[playerY + 1][playerX] != 'F')
                playerY++;
            else
                printf("You cannot move south.\n");
        }
        else if (strcmp(input, "west") == 0)
        {
            if (playerX > 0 && map[playerY][playerX - 1] != 'F')
                playerX--;
            else
                printf("You cannot move west.\n");
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}