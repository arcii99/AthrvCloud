//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numPlanets, numInvasions, numSuccessfulInvasions=0;
    double invasionProb, successRate;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);
    printf("Enter the number of invasion attempts: ");
    scanf("%d", &numInvasions);

    srand(time(NULL)); // initialize random seed
  
    for(int i=0; i<numInvasions; i++){ // loop through each invasion attempt
        invasionProb = rand()/(double)RAND_MAX; // generate a random invasion probability
        if(invasionProb < 0.6){ // check if the invasion is successful
            numSuccessfulInvasions++;
        }
    }

    successRate = numSuccessfulInvasions/(double)numInvasions; // calculate success rate as a ratio

    printf("\nOut of %d invasion attempts on %d planets, %d successful invasions were carried out.\n", numInvasions, numPlanets, numSuccessfulInvasions);
    printf("That gives a success rate of %.2f%%.\n", successRate*100);

    if(successRate >= 0.75){ // determine if the invasion is probable
        printf("There is a high probability of a successful alien invasion.\n");
    }
    else{
        printf("There is a low probability of a successful alien invasion.\n");
    }
    
    return 0;
}