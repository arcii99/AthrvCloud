//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // Seed the random number generator
    
    int numPlanets, numInvasions = 0;
    float invasionProbability, invasionChance;
    
    // Ask user for number of planets
    printf("How many planets are there in the galaxy?: ");
    scanf("%d", &numPlanets);
    
    // Ask user for invasion probability in percentage
    printf("What is the probability of an alien invasion (in percentage)?: ");
    scanf("%f", &invasionProbability);
    
    // Convert percentage to decimal
    invasionChance = invasionProbability / 100.0;
    
    // Calculate probability of at least one invasion
    for(int i = 0; i < numPlanets; i++){
        float probability = (float) rand() / RAND_MAX;
        if(probability <= invasionChance){
            numInvasions++;
        }
    }
    
    // Calculate probability of no invasions
    float noInvasionChance = 1.0;
    for(int i = 0; i < numPlanets; i++){
        noInvasionChance *= (1 - invasionChance);
    }
    
    // Print results
    printf("\n");
    printf("Probability of at least one invasion: %.2f%%\n", (float) numInvasions / numPlanets * 100);
    printf("Probability of no invasion: %.2f%%\n", noInvasionChance * 100);
    
    return 0;
}