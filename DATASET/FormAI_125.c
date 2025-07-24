//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initializing the rand function with time

    int ghostPos = rand() % 10 + 1; // Generating a random position between 1 to 10 for the ghost

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself inside an old, creepy house...\n");
    printf("As you explore the house, you feel a presence following you...\n");
    printf("Suddenly, you hear a loud noise from the %dth room.\n", ghostPos);

    int playerPos, numTries = 0;

    do
    {
        printf("Enter the room number you want to explore (1-10): ");
        scanf("%d", &playerPos);

        if (playerPos < 1 || playerPos > 10) // Checking for valid input
        {
            printf("Invalid input. Please enter a number between 1 to 10.\n");
            continue;
        }

        numTries++; // Incrementing the number of tries

        if (playerPos == ghostPos) // If player encounters the ghost
        {
            printf("Ahhhh! You encountered a ghost in the %dth room and have been terrified out of your wits!\n", ghostPos);
            printf("It took you %d tries to find the ghost.\n", numTries);
            break;
        }
        else // If player does not encounter the ghost
        {
            printf("You explored room %d, but found nothing.\n", playerPos);
        }

    } while (playerPos != ghostPos);

    printf("Thank you for playing the Haunted House Simulator!\n");

    return 0;
}