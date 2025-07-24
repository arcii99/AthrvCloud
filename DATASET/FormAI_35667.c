//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Prompt user for number of planets in the galaxy
    int num_planets;
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);

    // Generate a random number between 1 and num_planets to choose the planet to invade
    int invade_planet = rand() % num_planets + 1;
    printf("The alien civilization plans to invade planet %d.\n", invade_planet);

    // Prompt user for number of inhabited planets in the galaxy
    int num_inhabited_planets;
    printf("Enter the number of inhabited planets in the galaxy: ");
    scanf("%d", &num_inhabited_planets);

    // Calculate the probability of invading an inhabited planet
    double invade_prob = (double)num_inhabited_planets / (double)num_planets;
    printf("The probability of invading an inhabited planet is %.2f.\n", invade_prob);

    // Generate a random number between 0 and 1 to determine if invasion is successful
    double invasion_success = (double)rand() / RAND_MAX;
    if (invasion_success <= invade_prob) {
        printf("The alien invasion was successful! They have conquered planet %d.\n", invade_planet);
    } else {
        printf("The alien invasion failed. They were unable to conquer planet %d.\n", invade_planet);
    }

    return 0;
}