//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed random number generator with current time
    int alienProb = rand() % 101; // Generate a random number from 0 to 100
    float humanProb = 100 - alienProb; // Calculate human probability
    
    printf("Alien Invasion Probability Calculator\n");
    printf("-------------------------------------\n");
    printf("The probability of an alien invasion is: %d%%\n", alienProb);
    printf("The probability of no alien invasion is: %.2f%%\n", humanProb);
    printf("-------------------------------------\n");
    
    // Determine if the world is at risk of an alien invasion
    if (alienProb >= 50) {
        printf("WARNING: The world is at risk of an alien invasion. Take precautions!\n");
    } else {
        printf("Good news! The world is not at risk of an alien invasion... for now.\n");
    }
    
    return 0;
}