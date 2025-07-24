//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
// Alien Invasion Probability Calculator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Initialize random number generator
    srand(time(NULL));

    // Ask user for input
    int num_planets;
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);

    // Calculate probability of alien invasion
    double invasion_prob = rand() % 101 * ((double)num_planets / 100);
    printf("Based on our calculations, there is a %.2f%% chance of an alien invasion.\n", invasion_prob);

    // Print results
    if (invasion_prob < 10) {
        printf("Don't worry, the chance of an alien invasion is very low.\n");
    } else if (invasion_prob < 50) {
        printf("There is a moderate chance of an alien invasion, so be prepared!\n");
    } else {
        printf("An alien invasion is very likely! Take immediate action to protect the planet.\n");
    }

    return 0;
}