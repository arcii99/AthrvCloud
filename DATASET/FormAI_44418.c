//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int planet_mass = rand() % 100000 + 1;
    int planet_temp = rand() % 200 + 1;
    int planet_oxygen = rand() % 100 + 1;
    int alien_intelligence = rand() % 100 + 1;
    int alien_technology = rand() % 100 + 1;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please provide the following information about your planet:\n");
    printf("Planet mass (in kg): %d\n", planet_mass);
    printf("Planet temperature (in degrees Celsius): %d\n", planet_temp);
    printf("Planet oxygen level (in percent): %d\n\n", planet_oxygen);

    printf("Now enter the intelligence level and technology level of the aliens:\n");
    printf("Alien intelligence (out of 100): %d\n", alien_intelligence);
    printf("Alien technology (out of 100): %d\n\n", alien_technology);

    int invasion_probability = (planet_mass * (100 - planet_temp) * planet_oxygen) / ((alien_intelligence/10) * (alien_technology/10));

    if (invasion_probability > 100) {
        printf("The probability of an alien invasion is %.2f%%!", 100.00);
    } else {
        printf("The probability of an alien invasion is %.2f%%!", (float)invasion_probability);
    }

    return 0;
}