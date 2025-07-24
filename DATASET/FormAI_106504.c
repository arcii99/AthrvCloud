//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int num_of_attempts = 100000; // Number of times for probability calculation
    int invasion_probability = 0; // Counter variable for invasion probabilities
    int i, j; // Loop variables
    
    // Initializing random seed
    srand(time(0));
    
    // Simulation loop for probability calculation
    for (i = 0; i < num_of_attempts; i++) {
        int alien_ships = rand() % 100; // Randomly generate number of alien ships
        
        // Nested loop to simulate each alien ship
        for (j = 0; j < alien_ships; j++) {
            int attack_probability = rand() % 100; // Randomly generate attack probability
            
            // If attack probability is greater than or equal to 50, invasion is successful
            if (attack_probability >= 50) {
                invasion_probability++; // Increment invasion counter
                break; // Exit nested loop since invasion is successful
            }
        }
    }
    
    // Calculate probability of invasion
    double invasion_percentage = ((double)invasion_probability / (double)num_of_attempts) * 100;
    
    // Display calculated probability to user
    printf("The probability of an alien invasion is: %0.2f%%\n", invasion_percentage);
    
    return 0;
}