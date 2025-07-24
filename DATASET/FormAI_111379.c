//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    float probability = 0.0;
    int techLevel, resources, population, militaryStrength;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Please enter the tech level of your society (1-10): ");
    scanf("%d", &techLevel);

    printf("Please enter the amount of resources your society has (in millions of dollars): ");
    scanf("%d", &resources);

    printf("Please enter the population of your society (in millions): ");
    scanf("%d", &population);

    printf("Please enter the military strength of your society (1-10): ");
    scanf("%d", &militaryStrength);

    // calculate probability based on inputs
    probability = (float)(techLevel + (resources/100) + (population/10) + militaryStrength) / 40;

    printf("\n\nThe probability of an alien invasion is: %.2f%%\n", probability * 100);

    return 0;
}