//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    
    float invasionProbability = (float) rand() / RAND_MAX; // Generate a random float between 0 and 1
    // This represents the likelihood of an alien invasion happening
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Based on our calculations, there is a %.2f%% chance of an alien invasion happening.\n",
           invasionProbability * 100); // Convert the probability to a percentage and print it
    
    return 0;
}