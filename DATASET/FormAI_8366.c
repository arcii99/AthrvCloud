//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up the random seed
    srand(time(0));

    // Welcome message
    printf("Welcome to the Procedural Space Adventure!\n");

    // Select a random planet
    int planet = rand() % 10 + 1;

    // Set up the planet data
    char* planetName;
    int distance, creatures;
    switch (planet)
    {
        case 1:
            planetName = "Eris";
            distance = 9000;
            creatures = 3;
            break;
        case 2:
            planetName = "Vega";
            distance = 4500;
            creatures = 5;
            break;
        case 3:
            planetName = "Andromeda";
            distance = 6000;
            creatures = 2;
            break;
        case 4:
            planetName = "Sirius";
            distance = 1000;
            creatures = 10;
            break;
        case 5:
            planetName = "Mars";
            distance = 3000;
            creatures = 8;
            break;
        case 6:
            planetName = "Jupiter";
            distance = 5000;
            creatures = 4;
            break;
        case 7:
            planetName = "Neptune";
            distance = 8000;
            creatures = 1;
            break;
        case 8:
            planetName = "Uranus";
            distance = 7000;
            creatures = 2;
            break;
        case 9:
            planetName = "Pluto";
            distance = 9500;
            creatures = 3;
            break;
        case 10:
            planetName = "Saturn";
            distance = 4000;
            creatures = 6;
            break;
    }

    // Display planet information
    printf("You are about to embark on a journey to the planet %s.\n", planetName);
    printf("The planet is located %d light years away.\n", distance);
    printf("There are %d different types of creatures on this planet.\n", creatures);

    // Start the mission
    printf("Launching mission...\n");

    // Travel animation
    printf("Traveling");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(500000);
    }
    printf("\n");

    // Arrival message
    printf("You have arrived at the planet %s!\n", planetName);

    // Encounter creatures
    int encounter = rand() % creatures + 1;
    printf("You encounter a new creature on the planet!\n");
    printf("It is creature number %d.\n", encounter);

    // End message
    printf("Mission complete! Returning to Earth...\n");
    printf("Traveling");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(500000);
    }
    printf("\n");
    printf("Welcome back to Earth!\n");

    return 0;
}