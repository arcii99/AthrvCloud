//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Initialize variable to store the number of alien invasions
    int alienInvasions = 0;
    
    // Ask the user for the number of simulations to run
    printf("How many simulations do you want to run? ");
    int numSimulations;
    scanf("%d", &numSimulations);
    
    // Run the simulations
    for (int i = 0; i < numSimulations; i++) {
        // Generate a random number between 0 and 99
        int invasionProbability = rand() % 100;
        
        // Check if the probability is greater than or equal to 50
        if (invasionProbability >= 50) {
            printf("Alien invasion detected!\n");
            alienInvasions++;
        }
    }
    
    // Calculate the percentage of simulations with alien invasions
    float invasionPercentage = (float)alienInvasions / numSimulations * 100;
    
    // Print the results
    printf("\nSimulation Results:\n");
    printf("Number of simulations: %d\n", numSimulations);
    printf("Alien invasions detected: %d\n", alienInvasions);
    printf("Probability of alien invasion: %.2f%%", invasionPercentage);
    
    return 0;
}