//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global variables
int num_planets = 0;
int num_habitable_planets = 0;
int num_known_alien_species = 0;
int num_aggressive_species = 0;
float invasion_probability = 0.0f;

int main() {
    // seed the random number generator
    srand(time(NULL));

    // get user input
    printf("Enter the number of planets in the universe: ");
    scanf("%d", &num_planets);
    printf("Enter the number of habitable planets in the universe: ");
    scanf("%d", &num_habitable_planets);
    printf("Enter the number of known alien species: ");
    scanf("%d", &num_known_alien_species);
    printf("Enter the number of known aggressive alien species: ");
    scanf("%d", &num_aggressive_species);

    // calculate invasion probability
    float habitable_planet_ratio = (float) num_habitable_planets / (float) num_planets;
    float aggressive_species_ratio = (float) num_aggressive_species / (float) num_known_alien_species;
    invasion_probability = habitable_planet_ratio * aggressive_species_ratio;

    // add some randomness to the result
    float randomness = (float) rand() / (float) RAND_MAX;
    invasion_probability += randomness;

    // print the result
    printf("Based on the input, the probability of an alien invasion is %.2f%%\n", invasion_probability * 100.0f);

    return 0;
}