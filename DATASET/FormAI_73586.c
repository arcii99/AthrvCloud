//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize the random number generator
    srand(time(NULL));

    // Initialize variables
    int invasionProbability = 0;
    int year = 2021;
    int alienArrivalYear = 0;

    // Prompt user for number of simulations to run
    int numSimulations;
    printf("Enter the number of simulations to run: ");
    scanf("%d", &numSimulations);

    // Run simulations
    for (int i = 0; i < numSimulations; i++) {

        // Generate a random probability of alien invasion between 0 and 100
        invasionProbability = rand() % 101;

        // Calculate the year of alien arrival based on the invasion probability
        if (invasionProbability >= 0 && invasionProbability <= 50) {
            alienArrivalYear = year + (rand() % 20) + 1; // 1-20 years from now
        } else if (invasionProbability > 50 && invasionProbability <= 85) {
            alienArrivalYear = year + (rand() % 50) + 1; // 1-50 years from now
        } else {
            alienArrivalYear = year + (rand() % 100) + 1; // 1-100 years from now
        }

        // Print the results of the simulation
        printf("Simulation #%d:\n", i + 1);
        printf("   Invasion Probability: %d%%\n", invasionProbability);
        printf("   Year of Alien Arrival: %d\n", alienArrivalYear);
    }

    return 0;
}