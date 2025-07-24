//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to calculate probability of alien invasion.
float calculateProbability(float technologyLevel, float militaryStrength, float populationDensity) {
    float probability = (technologyLevel + militaryStrength) / populationDensity;
    return probability;
}

int main() {
    float technologyLevel; // Technology level of a civilization.
    float militaryStrength; // The military strength of a civilization.
    float populationDensity; // The population density of a civilization.
    float alienInvasionProbability; // Probability of alien invasion.

    srand(time(NULL)); // Initialize random number generator.

    // Generate random values for technology level, military strength and population density.
    technologyLevel = (float) rand() / (float) RAND_MAX * 10;
    militaryStrength = (float) rand() / (float) RAND_MAX * 10;
    populationDensity = (float) rand() / (float) RAND_MAX * 100;

    // Calculate probability of alien invasion.
    alienInvasionProbability = calculateProbability(technologyLevel, militaryStrength, populationDensity);

    // Print the results.
    printf("Alien Invasion Probability Calculator\n");
    printf("=====================================\n");
    printf("Technology Level: %.2f\n", technologyLevel);
    printf("Military Strength: %.2f\n", militaryStrength);
    printf("Population Density: %.2f\n", populationDensity);
    printf("Alien Invasion Probability: %.2f%%\n", alienInvasionProbability * 100);

    return 0;
}