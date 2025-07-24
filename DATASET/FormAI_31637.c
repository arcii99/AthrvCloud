//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // set initial probability to 50%
    double probability = 0.5;

    // prompt user for number of simulations
    int numSimulations;
    printf("How many simulations would you like to run? ");
    scanf("%d", &numSimulations);

    // run the simulations
    int numSuccesses = 0;
    for (int i = 0; i < numSimulations; i++) {
        // generate a random number between 0 and 1
        double random = (double) rand() / RAND_MAX;

        // if the random number is less than the probability, count it as a success
        if (random < probability) {
            numSuccesses++;
        }
    }

    // calculate the success rate
    double successRate = (double) numSuccesses / numSimulations * 100;

    printf("After %d simulations with a %f probability of invasion, the success rate was %f%%.\n",
           numSimulations, probability, successRate);

    return 0;
}