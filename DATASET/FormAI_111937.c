//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL));
    int randNum = (rand() % 100) + 1;
    return randNum;
}

int main(void) {
    int numAttempts = 0; // Number of attempts to make contact with aliens
    int invasionProbability = 0; // Probability of alien invasion
    int alienPopulation = generateRandomNumber(); // Random alien population between 1 and 100
    int communicationDifficulty = generateRandomNumber(); // Random communication difficulty between 1 and 100
    int invasionLikelihood = generateRandomNumber(); // Random invasion likelihood between 1 and 100
    
    // Output the random values for alien population, communication difficulty, and invasion likelihood
    printf("Alien Population: %d\n", alienPopulation);
    printf("Communication Difficulty: %d\n", communicationDifficulty);
    printf("Invasion Likelihood: %d\n", invasionLikelihood);
    
    // Calculate the probability of alien invasion based on the three random values
    invasionProbability = (alienPopulation * communicationDifficulty * invasionLikelihood) / 10000;
    
    // Output the probability of alien invasion
    printf("Probability of Alien Invasion: %d%%\n", invasionProbability);
    
    // Make contact attempts until a successful communication occurs
    while (1) {
        numAttempts++;
        int contactSuccess = generateRandomNumber(); // Random chance of successful communication
        
        // Check if communication was successful
        if (contactSuccess <= communicationDifficulty) {
            printf("Communication successful after %d attempts!\n", numAttempts);
            break;
        } else {
            printf("Attempt %d failed. Trying again...\n", numAttempts);
        }
    }
    
    // Check if alien invasion will occur based on the probability calculation and a random chance
    int invasionChance = generateRandomNumber(); // Random chance of alien invasion
    if (invasionProbability > invasionChance) {
        printf("ALERT! Alien invasion imminent!\n");
    } else {
        printf("All clear. No sign of alien invasion.\n");
    }
    
    return 0;
}