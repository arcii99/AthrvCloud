//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10 // Maximum number of bags that can be processed at one time

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int num_bags = 0; // Start with zero bags
    int time_elapsed = 0; // Start with zero time elapsed
    
    while (time_elapsed < 60) { // Simulate one minute
        
        // Generate a random number between 0 and 1
        double random_num = (double)rand() / RAND_MAX;
        
        if (random_num < 0.3 && num_bags < MAX_BAGS) {
            // With a 30% chance, add a bag to the system
            num_bags++;
            printf("Added a bag! Total: %d\n", num_bags);
        }
        
        if (num_bags > 0) {
            // If there are bags in the system, process one
            num_bags--;
            printf("Processed a bag! Total: %d\n", num_bags);
        }
        
        time_elapsed++; // Increment the time elapsed
        
    }
    
    return 0;
}