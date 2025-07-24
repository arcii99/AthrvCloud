//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>

int main() {
    // Define variables
    int num_alien_species;
    float nearest_alien_planet_distance;
    int defense_system_strength;
    float invasion_probability;

    // Get user inputs
    printf("Enter the number of known alien species: ");
    scanf("%d", &num_alien_species);

    printf("Enter the distance to the nearest alien planet (in light years): ");
    scanf("%f", &nearest_alien_planet_distance);

    printf("Enter the strength of Earth's defense systems (1-10): ");
    scanf("%d", &defense_system_strength);

    // Calculate invasion probability
    invasion_probability = (num_alien_species / nearest_alien_planet_distance) * defense_system_strength;

    // Output results
    printf("The probability of an alien invasion is: %f%%", invasion_probability);

    return 0;
}