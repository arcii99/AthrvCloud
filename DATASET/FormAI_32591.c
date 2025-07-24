//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializePlanets(int* planets, int maxPlanets, int maxDistance)
{
    srand(time(NULL)); // Setup the seed for the random number generator
    for (int i = 0; i < maxPlanets; i++)
    {
        planets[i] = rand() % maxDistance + 1; // Randomly assign the planet's distance from Earth
    }
}

int main()
{
    int maxPlanets = 10; // Maximum number of planets in the galaxy
    int maxDistance = 1000; // Maximum distance of a planet from Earth in light years

    int planets[maxPlanets]; // Array to store the distances of the planets

    initializePlanets(planets, maxPlanets, maxDistance); // Initialize the planets

    int spaceshipSpeed = 10; // Speed of our spaceship in light years per day
    int currentDistance = 0; // The current distance of the spaceship from Earth

    while (1)
    {
        printf("Current distance from Earth: %d\n", currentDistance);

        for (int i = 0; i < maxPlanets; i++)
        {
            if (planets[i] == currentDistance) // If we have reached a planet
            {
                printf("You have discovered planet %d!\n", i + 1);
                // Code to explore the planet goes here
            }
        }

        if (currentDistance >= maxDistance) // If we have reached the end of the galaxy
        {
            printf("Congratulations! You have explored the entire galaxy!\n");
            break;
        }

        currentDistance += spaceshipSpeed; // Move the spaceship closer to the end of the galaxy

        // Wait for a day before continuing the loop
        printf("Spending a day in hypersleep...\n");
        sleep(1); // Wait for 1 second (assuming 1 second = 1 day)
    }

    return 0;
}