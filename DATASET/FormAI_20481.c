//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float probability;
    int num_aliens;
    
    // Generate a random seed based on current time
    srand((unsigned)time(NULL));
    
    // Determine probability of alien invasion
    probability = ((rand() % 101) / 100.0); // values range from 0 to 1
    
    // Determine number of aliens
    num_aliens = rand() % 10000; // max of 10,000 aliens
    
    // Calculate likelihood of invasion based on probability
    if(probability < 0.01) { // 1% likelihood
        printf("Alien invasion is imminent!\n");
        printf("Number of aliens: %d\n", num_aliens);
    } else if(probability < 0.25) { // 24% likelihood
        printf("There is a moderate chance of alien invasion.\n");
        printf("Number of aliens: %d\n", num_aliens);
    } else { // 75% likelihood
        printf("Alien invasion is unlikely at this time.\n");
    }
    
    return 0;
}