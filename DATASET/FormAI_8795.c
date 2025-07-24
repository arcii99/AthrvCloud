//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed random number generator with current time

    int numPlanets,minProb,maxProb; // variables to store input values
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);
    printf("Enter the minimum probability of invasion (0-100): ");
    scanf("%d", &minProb);
    printf("Enter the maximum probability of invasion (0-100): ");
    scanf("%d", &maxProb);

    int invasionProb, successfulInvasions = 0, unsuccessfulInvasions = 0; 
    // variables to store calculated values
    for(int i = 1; i <= numPlanets; i++){
        invasionProb = rand()%(maxProb - minProb + 1) + minProb; // calculate probability for each planet
        if(invasionProb < 50){ // if probability is less than 50, invasion is unsuccessful
            printf("Planet %d: No Invasion (Probability = %d%%)\n", i, invasionProb);
            unsuccessfulInvasions++;
        }
        else{ // if probability is greater than or equal to 50, invasion is successful
            printf("Planet %d: Invasion Successful (Probability = %d%%)\n", i, invasionProb);
            successfulInvasions++;
        }
    }

    printf("Total Planets: %d\n", numPlanets);
    printf("Successful Invasions: %d\n", successfulInvasions);
    printf("Unsuccessful Invasions: %d\n", unsuccessfulInvasions);

    double successRate = ((double)successfulInvasions/(double)numPlanets)*100; 
    // calculate success rate as a percentage
    printf("Invasion Success Rate: %0.2lf%%\n", successRate);

    return 0;
}