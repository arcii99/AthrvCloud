//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    printf("Welcome to the Alien Invasion Probability Calculator\n\n");
    
    int population;
    printf("Enter the population of your city: ");
    scanf("%d", &population);
    
    int militaryStrength;
    printf("Enter the military strength of your city: ");
    scanf("%d", &militaryStrength);
    
    float alienStrength = ((float)rand()/(float)(RAND_MAX)) * 100; // Generate a random number between 0 and 100 for alien strength
    printf("\nAlien strength: %f%%\n", alienStrength);
    
    float invasionProbability = (alienStrength * 0.7) + (population * 0.1) + (militaryStrength * 0.2); // Calculate invasion probability
    printf("Invasion probability: %f%%\n", invasionProbability);
    
    if (invasionProbability > 50) {
        printf("WARNING: High probability of alien invasion!\n");
    } else {
        printf("No immediate threat of alien invasion.\n");
    }
    
    return 0;
}