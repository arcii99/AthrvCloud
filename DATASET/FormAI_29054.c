//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalPlanets, invadedPlanets = 0;
    float probability;

    // Seed the random number generator
    srand(time(NULL));

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");

    // Ask the user for the total number of planets in the universe
    printf("Enter the total number of planets in the universe: ");
    scanf("%d", &totalPlanets);

    // Calculate the probability of any one planet being invaded
    probability = (float)rand() / RAND_MAX;

    // Loop through each planet in the universe
    for (int i = 1; i <= totalPlanets; i++) {
        // If this planet is invaded, increment the invadedPlanet counter
        if (probability >= 0.5) {
            invadedPlanets++;
        }

        // Recalculate the probability of invasion for the next planet
        probability = (float)rand() / RAND_MAX;
    }

    // Calculate the percentage of planets that were invaded
    float invasionPercentage = (float)invadedPlanets / totalPlanets * 100;

    printf("\n\nBased on current data, there is a %.2f%% chance of an alien invasion\n", invasionPercentage);

    return 0;
}