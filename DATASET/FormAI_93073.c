//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the following parameters to calculate the probability of an alien invasion:\n");

    int num_of_planets, num_of_aliens, tech_level;
    float distance_from_earth;

    printf("Enter the number of planets in the alien race's home star system: ");
    scanf("%d", &num_of_planets);
    printf("Enter the number of aliens in the alien race: ");
    scanf("%d", &num_of_aliens);
    printf("Enter the alien race's technological level (1-10 with 10 being the most advanced): ");
    scanf("%d", &tech_level);
    printf("Enter the distance from the alien race's home star system to Earth (in light years): ");
    scanf("%f", &distance_from_earth);

    // Calculate the probability of an alien invasion
    float probability = 0.0;
    srand(time(NULL)); // Initialize random number generator

    int d1 = rand() % num_of_planets + 1; // Random number from 1 to num_of_planets
    int d2 = rand() % num_of_aliens + 1; // Random number from 1 to num_of_aliens
    int d3 = rand() % tech_level + 1; // Random number from 1 to tech_level
    float d4 = (rand() % 100 + 1) / 100.0; // Random number from 0.01 to 1.00

    probability = (float)d1 / (float)num_of_planets; // Probability based on number of planets
    probability *= (float)d2 / (float)num_of_aliens; // Probability based on number of aliens
    probability *= (float)d3 / (float)tech_level; // Probability based on technological level
    probability *= (1 / distance_from_earth * 100); // Probability based on distance from Earth

    printf("\nThe probability of an alien invasion is: %.2f%%\n", probability * 100);

    return 0;
}