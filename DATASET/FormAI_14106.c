//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ALIEN_PROBABILITY 0.01

int main()
{
    srand(time(0));
    float probability = (float)rand()/RAND_MAX;
    int total_population = 100000;
    int infected_population = 0;
    int defense_turrets = 10;
    int alien_ships = 50;

    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("Initializing systems...\n");
    printf("System succesfully initialized!\n");
    printf("\n");

    printf("Current population: %d\n", total_population);
    printf("Current number of defense turrets: %d\n", defense_turrets);
    printf("Current number of alien ships: %d\n", alien_ships);
    printf("\n");

    if (probability < ALIEN_PROBABILITY)
    {
        printf("***ALERT***\n");
        printf("Alien invasion detected!\n");

        infected_population = (int)(probability * total_population);

        printf("Number of infected people: %d\n", infected_population);

        if (infected_population > defense_turrets * 100)
        {
            printf("***WARNING***\n");
            printf("The defense turrets are not sufficient to stop the alien invasion!\n");
        }
        else
        {
            int alien_casualties = (int)(infected_population / 10); // 10% of infected aliens are killed in combat

            if (alien_casualties > alien_ships * 10)
            {
                printf("***WARNING***\n");
                printf("The number of alien ships is not sufficient to handle the resistance!\n");
            }
            else
            {
                printf("***ALERT***\n");
                printf("The alien invasion has been contained!\n");
            }
        }
    }
    else
    {
        printf("***SAFE***\n");
        printf("No signs of alien invasion detected.\n");
    }

    return 0;
}