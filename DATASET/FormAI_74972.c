//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize variables for probability calculations
    int total_attempts = 10000;
    int alien_probability = 0;
    int invasion_probability = 0;
    int alien_invasion_probability = 0;
    
    // Perform the simulation for each attempt
    for (int i = 0; i < total_attempts; i++) {
        
        // Generate random numbers for alien and invasion probability
        alien_probability = rand() % 101; // Probability of Aliens (1%-100%)
        invasion_probability = rand() % 101; // Probability of Invasion (1%-100%)
        
        // Calculate probability of Alien Invasion
        alien_invasion_probability = alien_probability * invasion_probability / 100;
        
        // Print the probabilities
        printf("Attempt %d: Probability of Aliens = %d%%, Probability of Invasion = %d%%, Probability of Alien Invasion = %d%%\n", i+1, alien_probability, invasion_probability, alien_invasion_probability);
    }
    
    // Exit the program
    return 0;
}