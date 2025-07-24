//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    // Generate random numbers to simulate the probability of an alien invasion
    float probability = (float)rand() / RAND_MAX;
    float power_level = (float)rand() / RAND_MAX;
    float intelligence = (float)rand() / RAND_MAX;
    float distance = (float)rand() / RAND_MAX;
    
    // Calculate the overall invasion probability
    float invasion_prob = probability * power_level * intelligence * (1 - distance);
    
    // Print out the individual factors for the user to see
    printf("Probability of alien life: %.2f\n", probability);
    printf("Alien power level: %.2f\n", power_level);
    printf("Alien intelligence: %.2f\n", intelligence);
    printf("Distance from Earth: %.2f\n\n", distance);
    
    // Print out the overall probability
    printf("Probability of an alien invasion: %.2f\n\n", invasion_prob);
    
    // Interpret the probability and provide a warning if necessary
    if (invasion_prob >= 0.8) {
        printf("WARNING: There is a very high probability of an alien invasion! Take action immediately.\n");
    } else if (invasion_prob >= 0.5) {
        printf("CAUTION: There is a moderate probability of an alien invasion. Watch for signs of activity.\n");
    } else {
        printf("NEGATIVE: The probability of an alien invasion is low. Continue monitoring the situation.\n");
    }
    
    return 0;
}