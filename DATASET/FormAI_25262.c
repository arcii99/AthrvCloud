//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alien_fleet_size, human_population_size;
    float strength_ratio, invasion_probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Get input from user
    printf("Please enter the size of the alien fleet: ");
    scanf("%d", &alien_fleet_size);

    printf("Please enter the size of the human population: ");
    scanf("%d", &human_population_size);

    // Generate a random strength ratio between 0.5 and 2.0
    srand(time(NULL));
    strength_ratio = (rand() % 150 + 50) / 100.0; 

    printf("\nCalculating invasion probability...\n");

    // Calculate invasion probability
    invasion_probability = (float)alien_fleet_size / (strength_ratio * human_population_size);

    if (invasion_probability < 0.01)
    {
        printf("\nThe invasion probability is extremely low.\n");
    }
    else if (invasion_probability >= 0.01 && invasion_probability <= 0.05)
    {
        printf("\nThe invasion probability is moderate.\n");
    }
    else
    {
        printf("\nThe invasion probability is high.\n");
    }

    return 0;
}