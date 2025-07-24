//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize variables
    int numPlanets = 0, invasionChances = 0, sum = 0, planetCount = 0;
    double planetProb = 0.0, overallProb = 0.0;

    // Get number of planets in galaxy
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &numPlanets);

    // Get invasion probability for each planet and calculate overall probability
    for (int i = 1; i <= numPlanets; i++) {
        printf("\nEnter the invasion probability (0-100) for planet #%d: ", i);
        scanf("%d", &invasionChances);
        planetProb = (double) invasionChances / 100;
        printf("Probability of invasion for planet #%d: %.2f\n", i, planetProb);
        overallProb += planetProb;
        planetCount++;
    }

    // Calculate average probability of invasion
    overallProb /= planetCount;

    // Generate random number to determine if alien invasion occurs
    int invasionRoll = rand() % 101;

    // Display overall probability and invasion result
    printf("\nOverall probability of alien invasion: %.2f%%\n", overallProb * 100);
    printf("The invasion roll was %d.\n", invasionRoll);
    if (invasionRoll <= overallProb * 100) {
        printf("Alien invasion successful!\n");
    } else {
        printf("Alien invasion unsuccessful.\n");
    }

    return 0;
}