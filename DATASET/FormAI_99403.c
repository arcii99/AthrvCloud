//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int population, military_power;
    float technology_level, alien_aggression, invasion_probability;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Get user input
    printf("Enter the population of the planet: ");
    scanf("%d", &population);
    printf("Enter the military power of the planet: ");
    scanf("%d", &military_power);
    printf("Enter the technology level of the planet (out of 10): ");
    scanf("%f", &technology_level);
    
    // Calculate alien aggression based on population and technology level
    alien_aggression = population * technology_level / 1000;
    
    // Assign a random invasion probability based on military power and alien aggression
    if (military_power > alien_aggression) {
        invasion_probability = (float) rand() / RAND_MAX;
    } else {
        invasion_probability = (float) rand() / RAND_MAX + 0.5;
    }
    
    // Print the results
    printf("Alien aggression level: %.2f\n", alien_aggression);
    printf("Invasion probability: %.2f\n", invasion_probability);
    
    return 0;
}