//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(0));

    // Welcome message
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Get user input
    int population, defense_budget, alien_technology;
    printf("Enter the population of your city: ");
    scanf("%d", &population);
    printf("Enter your annual defense budget (in millions): ");
    scanf("%d", &defense_budget);
    printf("Enter the level of alien technology (1-10): ");
    scanf("%d", &alien_technology);

    // Calculate probability
    float probability = (float) population / (float) (defense_budget * (11 - alien_technology));

    // Display result
    printf("\n\nThe probability of an alien invasion is: %f%%\n", probability * 100);

    // Generate random event
    int random = rand() % 101;
    if (random < probability * 100)
    {
        printf("\n\nWARNING! Alien invasion detected!\n");
    }
    else
    {
        printf("\n\nNo alien invasion detected. Everything seems to be okay.\n");
    }

    return 0;
}