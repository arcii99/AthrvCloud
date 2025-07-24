//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializes the random number generator with a seed

    int planets = 0, invasions = 0, success = 0; // Variables to store user input and results

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &planets);
    printf("Enter the number of invasions observed: ");
    scanf("%d", &invasions);
  
    // Calculations
    double invProb = (double) invasions / planets; // Probability of an invasion on a planet
    double probAll = 1.0 - pow(1.0 - invProb, planets); // Probability of an invasion on all planets
    double probRand = (double) rand() / RAND_MAX; // Generates a random number between 0 and 1

    printf("\nCalculating...\n");
    printf("Probability of an invasion on a planet: %.2f%%\n", invProb * 100);
    printf("Probability of an invasion on all planets: %.2f%%\n", probAll * 100);

    if (probRand <= probAll) {
        success = 1;
        printf("\nAlien invasion detected! Evacuate the planet immediately!\n");
    }
    else {
        printf("\nNo alien invasion detected. The planet is safe... for now.\n");
    }

    return 0;
}