//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int generate_random(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main()
{
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the Procedural Space Adventure Game!\n");
    printf("You are on a mission to explore new galaxies and discover new life forms.\n");

    int distance = generate_random(100, 100000); // Generate random distance between 100 and 100,000 light years
    int speed = generate_random(50, 500); // Generate random speed between 50 and 500 light years per day

    printf("Your mission is to travel %d light years at a speed of %d light years per day.\n", distance, speed);

    int days_taken = 0;
    int distance_covered = 0;
    int alien_discovery = 0;

    // Loop while the ship has not reached its destination
    while (distance_covered < distance)
    {
        distance_covered += speed; // Increase distance covered by the ship

        // Generate a random number between 1 and 20. If it is 1, the ship discovers a new alien life form
        int chance_of_alien_discovery = generate_random(1, 20);
        if (chance_of_alien_discovery == 1)
        {
            alien_discovery++; // Increase the number of alien life forms discovered
            printf("You have discovered a new alien life form!\n");
        }

        days_taken++; // Increase the number of days taken to complete the mission
    }

    printf("Congratulations! You have completed your mission in %d days.\n", days_taken);
    printf("You have discovered %d new alien life forms.\n", alien_discovery);

    return 0;
}