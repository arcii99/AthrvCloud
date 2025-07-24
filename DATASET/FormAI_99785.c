//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int intelligence, technology, resources, armySize;
    float invasionProbability;
    
    // ask user for input values
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the intelligence level of the aliens (0 to 100): ");
    scanf("%d", &intelligence);
    printf("Please enter the technology level of the aliens (0 to 100): ");
    scanf("%d", &technology);
    printf("Please enter the available resources of the aliens (0 to 100): ");
    scanf("%d", &resources);
    printf("Please enter the size of the alien army (0 to 100): ");
    scanf("%d", &armySize);
    
    // calculate the invasion probability
    invasionProbability = (intelligence * 0.4 + technology * 0.3 + resources * 0.2 + armySize * 0.1) / 100;
    
    // display the result to the user
    printf("\nBased on the information provided, the probability of an alien invasion is %.2f%%\n", invasionProbability * 100);
    
    return 0;
}