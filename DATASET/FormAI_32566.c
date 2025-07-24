//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the probability of an alien invasion.
float alien_invasion_probability(int population, int num_of_telescopes, int num_of_satellites) {

    float probability;

    // Probability calculation formula
    probability = (num_of_telescopes * 0.25 + num_of_satellites * 0.5) / population;

    return probability;
}

int main() {

    int population, num_of_telescopes, num_of_satellites;
    float probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // User input for population, number of telescopes and number of satellites
    printf("Enter the population of your city (in millions): ");
    scanf("%d", &population);

    printf("Enter the number of telescopes in your city: ");
    scanf("%d", &num_of_telescopes);

    printf("Enter the number of satellites orbiting your city: ");
    scanf("%d", &num_of_satellites);

    // Probability calculation function call
    probability = alien_invasion_probability(population, num_of_telescopes, num_of_satellites);

    // Output of invasion probability
    printf("\nBased on the population, number of telescopes and satellites, the probability of an alien invasion is: %f\n", probability);

    printf("\nThank you for using the Alien Invasion Probability Calculator!");

    return 0;
}