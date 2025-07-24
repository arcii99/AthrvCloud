//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare and initialize variables for input
    int numCities, numDays;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    printf("Enter the number of days: ");
    scanf("%d", &numDays);

    // Declare and initialize variables for calculation
    float alienProb, humanLoss;
    srand(time(0)); // Set seed for random number generator
    
    // Loop through each city and calculate probability of alien invasion
    for (int i = 1; i <= numCities; i++) {
        // Generate a random number between 0 and 1 to represent probability
        alienProb = (float) rand() / RAND_MAX;
        printf("\nProbability of alien invasion in city %d: %f", i, alienProb);

        // Calculate expected human loss
        if (alienProb > 0.5)
            humanLoss = alienProb * numDays * 1000;
        else
            humanLoss = 0;
        printf("\nExpected human loss in city %d: %f", i, humanLoss);
    }
    return 0;
}