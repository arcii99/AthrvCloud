//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL)); // Seed the random number generator

    int fuel = 100; // Initialize fuel to 100%
    int distance = 0; // Initialize distance to 0 light years
    int alien_encounters = 0; // Initialize alien encounters to 0
    int repairs_needed = 0; // Initialize repairs needed to 0
    int repairs_made = 0; // Initialize repairs made to 0

    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("Your mission is to travel as far as possible into unknown space.\n");
    printf("You have a ship that requires fuel to travel.\n");
    printf("Throughout your journey, you may encounter alien species and need to make repairs.\n");
    printf("Good luck!\n\n");

    while (fuel > 0) // Continue travelling as long as there is fuel
    {
        int distance_travelled = (rand() % 10) + 1; // Travel between 1-10 light years randomly

        printf("You travelled %d light years.\n", distance_travelled);

        fuel -= distance_travelled; // Reduce fuel by the distance traveled

        if (fuel <= 0) // If fuel goes negative, set it to 0 to avoid errors
        {
            fuel = 0;
        }

        distance += distance_travelled; // Increase distance travelled

        if ((rand() % 100) < 25) // 25% chance of encountering an alien species
        {
            printf("You have encountered an alien species!\n");
            alien_encounters++;

            if ((rand() % 100) < 50) // 50% chance that the alien species is friendly
            {
                printf("The alien species is friendly.\n");
            }
            else // 50% chance that the alien species is hostile
            {
                printf("The alien species is hostile! Prepare for battle!\n");
            }
        }

        if ((rand() % 100) < 15) // 15% chance of needing repairs
        {
            printf("Your ship needs repairs.\n");
            repairs_needed++;

            if ((rand() % 100) < 50) // 50% chance of being able to make the repairs
            {
                printf("You were able to make the repairs.\n");
                repairs_made++;
            }
            else // 50% chance of not being able to make the repairs
            {
                printf("You were not able to make the repairs. Your ship has taken damage.\n");
            }
        }

        printf("Your ship has %d%% fuel remaining.\n", fuel);
        printf("You have travelled %d light years.\n", distance);
        printf("You have encountered %d alien species.\n", alien_encounters);
        printf("Your ship needed repairs %d times and you were able to make repairs %d times.\n\n", repairs_needed, repairs_made);
    }

    printf("Your ship has run out of fuel. Game over!\n");
    printf("You traveled a total of %d light years and encountered %d alien species.\n", distance, alien_encounters);
    printf("Your ship needed repairs %d times and you were able to make repairs %d times.\n", repairs_needed, repairs_made);

    return 0;
}