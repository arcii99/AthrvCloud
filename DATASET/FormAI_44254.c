//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed the random number generator with the current time
    
    float techLevel; // alien technology level
    float invasionSize; // size of invading alien fleet
    float invasionProb; // probability of an alien invasion
    
    int numSimulations = 10000; // number of simulations to run
    
    // prompt user for input
    printf("Enter the technology level of the alien civilization (0-10): ");
    scanf("%f", &techLevel);
    
    printf("Enter the size of the invading alien fleet (in millions): ");
    scanf("%f", &invasionSize);
    
    // calculate probability of an alien invasion
    invasionProb = techLevel * invasionSize / 100.0;
    
    // run simulations to check probability of an actual alien invasion
    int numInvasions = 0;
    for (int i = 0; i < numSimulations; i++) {
        float randomVal = (float) rand() / RAND_MAX; // generate a random number between 0 and 1
        if (randomVal <= invasionProb) {
            numInvasions++;
        }
    }
    
    // calculate percentage of simulations where there was an invasion
    float invasionPercent = (float) numInvasions / numSimulations * 100;
    
    // print out results
    printf("\n");
    printf("Probability of an alien invasion: %.2f%%\n", invasionProb);
    printf("After running %d simulations, there was an invasion in %.2f%% of them.\n", numSimulations, invasionPercent);

    return 0;
}