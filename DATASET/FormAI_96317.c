//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up variables and RNG seed
    int playerPos = 0;
    int ghosts = 0;
    int isHaunted = 0;
    const int GHOST_CHANCE = 30;
    const int MAX_GHOSTS = 5;
    srand(time(0));

    // Display introduction message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently at position %d.\n", playerPos);

    // Game loop
    while (!isHaunted)
    {
        // Roll for ghost encounter
        int ghostRoll = rand() % 100 + 1;
        if (ghostRoll <= GHOST_CHANCE && ghosts < MAX_GHOSTS)
        {
            ghosts++;
            printf("You encountered a ghost! There are now %d ghosts in the house.\n", ghosts);
        }

        // Player movement
        int moveRoll = rand() % 4 + 1;
        if (moveRoll == 1)
        {
            playerPos++;
            printf("You took a step forward and are now at position %d.\n", playerPos);

            // Check for haunted room
            if (playerPos == 13)
            {
                isHaunted = 1;
                printf("You entered Room 13... and it's haunted!\n");
            }
        }
        else if (moveRoll == 2)
        {
            playerPos--;
            printf("You took a step backwards and are now at position %d.\n", playerPos);

            // Check for haunted room
            if (playerPos == 13)
            {
                isHaunted = 1;
                printf("You entered Room 13... and it's haunted!\n");
            }
        }
        else
        {
            printf("You stayed in the same position.\n");
        }

        // Check for ghost swarm
        if (ghosts == MAX_GHOSTS)
        {
            isHaunted = 1;
            printf("A swarm of ghosts has formed and is haunting the house! You lose.\n");
        }
    }

    // Game over message
    printf("Thanks for playing the Haunted House Simulator!\n");
    return 0;
}