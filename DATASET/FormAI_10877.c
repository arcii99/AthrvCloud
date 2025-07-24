//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    const int NUM_SIMULATIONS = 100000;
    int count = 0;
    
    srand(time(0)); // initialize random seed
    
    // simulate 100,000 alien invasions and count how many result in success
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        int alien_ships = rand() % 100 + 1; // randomly generate number of alien ships (between 1 and 100)
        int defense_droids = rand() % 50 + 1; // randomly generate number of defense droids (between 1 and 50)
        int success_chance = (defense_droids * 10) / alien_ships; // calculate success chance
        
        if (success_chance >= 7) { // if success chance is 70% or higher, the invasion is successful
            count++;
        }
    }
    
    float invasion_probability = (float)count / NUM_SIMULATIONS; // calculate probability of invasion success
    
    // print results
    printf("Out of %d simulated alien invasions, %d resulted in a successful invasion.\n", NUM_SIMULATIONS, count);
    printf("The probability of a successful invasion is: %.2f\n", invasion_probability);
    
    return 0;
}