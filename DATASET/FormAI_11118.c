//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLANET_EARTH_POPULATION 7848000000

// Define probability of Alien Invasion in percentage
#define ALIEN_INVASION_PROBABILITY 0.0001
#define ALIEN_DETECTION_PROBABILITY 0.5

int main() {
    srand(time(NULL));  // Set random seed as current time
    
    int population, detected, invasion;
    double probability;
    
    // Get user input of Earth population
    printf("What is the population of Earth?: ");
    scanf("%d", &population);
    
    // Calculate probability of Alien Invasion
    probability = ((double) (population * ALIEN_INVASION_PROBABILITY)) / PLANET_EARTH_POPULATION;
    
    // Generate random number to simulate Alien Detection
    detected = (rand() % 2) == 0;
    
    // Calculate probability of Alien Invasion given detection probability
    if (detected) {
        invasion = probability * ALIEN_DETECTION_PROBABILITY;
    } else {
        invasion = probability;
    }
    
    // Output probability of Alien Invasion
    if (invasion >= 0.01) {
        printf("The probability of an Alien Invasion on Earth is %.2f%%. We are in grave danger!", invasion);
    } else if (invasion >= 0.001) {
        printf("The probability of an Alien Invasion on Earth is %.4f%%. We should prepare for the worst!", invasion);
    } else {
        printf("The probability of an Alien Invasion on Earth is only %.8f%%. We might still be safe...", invasion);
    }
    
    return 0;
}