//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set the seed for random number generation
    srand(time(0));
    
    // Configure variables for the probability calculator
    float distance, alien_tech_level, military_strength;
    printf("Enter the distance from the alien planet to Earth (in light years): ");
    scanf("%f", &distance);
    printf("Enter the alien civilization's technological level (0-10): ");
    scanf("%f", &alien_tech_level);
    printf("Enter Earth's military strength (0-10): ");
    scanf("%f", &military_strength);

    // Calculate the probability of an alien invasion
    float probability = ((alien_tech_level * 10) / (distance * distance)) * (military_strength / 10);

    // Output the probability to the user
    printf("The probability of an alien invasion is %f percent.", probability * 100);

    return 0;
}