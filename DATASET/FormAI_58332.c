//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Initializing necessary variables
    int numTrials = 10000; // Number of simulations to run
    int numInvasions = 0; // Number of simulations where an invasion occurred
    float invasionProb; // Probability of an alien invasion

    printf("Welcome to Alien Invasion Probability Calculator\n\n");

    printf("Enter the likelihood of a UFO sighting in your area (0.0-1.0): ");
    float ufoProb;
    scanf("%f", &ufoProb);

    printf("Enter the likelihood of a UFO sighting being an actual alien ship (0.0-1.0): ");
    float alienProb;
    scanf("%f", &alienProb);

    printf("Calculating probability of an alien invasion...\n\n");

    // Simulation loop
    for (int i = 0; i < numTrials; i++) {
        float ufoRand = (float) rand() / RAND_MAX; // Random number for UFO sighting
        float alienRand = (float) rand() / RAND_MAX; // Random number for alien ship

        if (ufoRand < ufoProb && alienRand < alienProb) {
            numInvasions++;
        }
    }

    invasionProb = (float) numInvasions / numTrials;
    printf("The probability of an alien invasion is: %f", invasionProb);

    return 0;
}