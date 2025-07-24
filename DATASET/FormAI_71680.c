//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed random number generator with current time
    
    int alienCount = rand() % 1000 + 1; // Generate a random alien count between 1 and 1000
    float invasionChance = (float)alienCount / 1000.0; // Calculate the invasion chance as a percentage
    
    printf("Calculating probability of alien invasion...\n");
    printf("Estimated number of aliens: %d\n", alienCount);
    printf("Chance of invasion: %.2f%%\n", invasionChance * 100);
    
    if (invasionChance < 0.5) { // If invasion chance is less than 50%
        printf("Low probability of invasion. Earth is likely safe.\n");
    } else if (invasionChance < 0.8) { // If invasion chance is between 50% and 80%
        printf("Moderate probability of invasion. Earth should prepare for a possible invasion.\n");
    } else { // If invasion chance is greater than 80%
        printf("High probability of invasion. Earth is in imminent danger. Evacuation is highly recommended.\n");
    }
    
    return 0;
}