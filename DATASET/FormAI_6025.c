//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
/* Alien Invasion Probability Calculator 
 * By [Your Name]
 * Inspired by Donald Knuth
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 0 and 1
double rand_double() {
    return (double) rand() / RAND_MAX;
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int num_simulations = 100000; // Number of simulations to run
    int num_aliens = 1000; // Number of aliens in the invasion force
    double invasion_success_rate = 0.25; // Probability of successful invasion on a given planet
    double probability = 0; // Initialize probability of successful invasion across all planets
    double p; // Temporary variable for probability of successful invasion on a single planet
    
    // Outer loop: run multiple simulations
    for (int i = 0; i < num_simulations; i++) {
        int planets = 0; // Initialize number of planets successfully invaded in this simulation
        
        // Inner loop: invade multiple planets in a single simulation
        for (int j = 0; j < num_aliens; j++) {
            p = rand_double(); // Generate random probability of successful invasion on this planet
            if (p < invasion_success_rate) {
                planets++; // Increment number of successfully invaded planets
            }
        }
        
        // Update overall probability of successful invasion
        probability += (double) planets / num_aliens;
    }
    probability /= num_simulations; // Calculate average probability over all simulations
    
    // Output results
    printf("After %d simulations with %d aliens and a %.2f%% chance of successful invasion on a given planet:\n", num_simulations, num_aliens, invasion_success_rate * 100);
    printf("The probability of a successful invasion across all planets is %.5f\n", probability);
    
    return 0;
}