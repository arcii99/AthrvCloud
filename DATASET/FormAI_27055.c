//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Set the starting probability to 0
    float prob = 0.0f;
    
    // Set the number of iterations to run
    int iterations = 1000000;
    
    // Set the base probability
    float base_prob = 0.0001f;
    
    // Set the probability increment
    float prob_inc = 0.00001f;
    
    // Set the factor for how much each iteration adds to the probability
    float prob_factor = 0.5f;
    
    // Loop through the iterations
    for (int i = 0; i < iterations; i++) {
        // Roll the dice
        float rand_num = ((float) rand() / (float) RAND_MAX);
        
        // If the random number is less than or equal to the current probability, an invasion takes place
        if (rand_num <= prob) {
            printf("Alien invasion detected!\n");
            
            // Reset the probability to the base value
            prob = base_prob;
        } else {
            // Increment the probability for the next iteration
            prob += prob_inc * prob_factor;
        }
    }
    
    return 0;
}