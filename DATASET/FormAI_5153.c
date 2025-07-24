//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This calculator will give you the probability of an alien invasion happening in your area.\n");

    // Asking for user input
    int population, num_of_sightings;
    printf("Enter the population of your area: ");
    scanf("%d", &population);
    printf("Enter the number of recent sightings: ");
    scanf("%d", &num_of_sightings);

    // Randomly generating values for factors affecting invasion probability
    srand(time(NULL));
    int military_strength = rand() % 101;
    int government_preparedness = rand() % 101;
    int alien_hostility = rand() % 101;

    // Calculating probability
    float probability = ((float)num_of_sightings/population) * (0.4 * military_strength + 0.3 * government_preparedness + 0.3 * (100 - alien_hostility));

    // Displaying results
    printf("\n\n*** Results ***\n");
    printf("Military Strength: %d%%\n", military_strength);
    printf("Government Preparedness: %d%%\n", government_preparedness);
    printf("Alien Hostility: %d%%\n", alien_hostility);
    printf("Probability of an Alien Invasion in Your Area: %f%%\n", probability);

    return 0;
}