//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_ships, prob;
    float prob_percent;
    
    // Get number of alien ships
    printf("How many alien ships are approaching? ");
    scanf("%d", &num_ships);
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Calculate probability of invasion
    prob = rand() % 101;
    prob_percent = (float)prob / 100;
    prob_percent *= num_ships;
    
    // Output results
    printf("There is a %.2f%% chance of an alien invasion with %d ships.\n", prob_percent, num_ships);
    
    return 0;
}