//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the C Alien Invasion Probability Calculator!\n");

    int numInvasions = 0;
    int numSimulations = 0;
    float invasionProbability = 0;

    // Get user input
    printf("How many times would you like to simulate an alien invasion? ");
    scanf("%d", &numSimulations);

    printf("What is the probability of an alien invasion occurring (0-1)? ");
    scanf("%f", &invasionProbability);

    // Seed the random number generator with the current time
    srand(time(0));

    // Simulate the invasions
    for(int i = 0; i < numSimulations; i++){
        float randNum = (float)rand() / RAND_MAX;
        if(randNum <= invasionProbability){
            numInvasions++;
        }
    }

    // Calculate and output the results
    float percentInvasions = (float)numInvasions / numSimulations * 100;
    printf("\nOut of %d simulations, there were %d invasions.\n", numSimulations, numInvasions);
    printf("That's a %.2f%% chance of an alien invasion occurring.\n", percentInvasions);

    return 0;
}