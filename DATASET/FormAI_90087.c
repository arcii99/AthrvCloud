//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int num_of_planets, max_distance, num_of_species, num_of_ships;
    float prob_of_invasion;

    // Setting up the random seed
    srand(time(NULL));

    // Requesting user input for variables
    printf("Enter the number of planets in the system: ");
    scanf("%d", &num_of_planets);

    printf("Enter the maximum distance from the home planet: ");
    scanf("%d", &max_distance);

    printf("Enter the number of intelligent species in the system: ");
    scanf("%d", &num_of_species);

    printf("Enter the number of ships each species has: ");
    scanf("%d", &num_of_ships);

    // Calculating the probability of invasion
    prob_of_invasion = ((float)num_of_species * num_of_ships) / (num_of_planets * max_distance);

    // Generating a random number between 0 and 1 to determine if there will be an invasion
    float invasion_chance = (float)rand() / RAND_MAX;

    // Displaying the results
    printf("\nBased on the following information:\n");
    printf("Number of planets: %d\n", num_of_planets);
    printf("Maximum distance from the home planet: %d\n", max_distance);
    printf("Number of intelligent species: %d\n", num_of_species);
    printf("Number of ships each species has: %d\n\n", num_of_ships);
    
    printf("There is a %0.2f percent chance of an alien invasion.\n", prob_of_invasion*100);

    if (invasion_chance <= prob_of_invasion) {
        printf("\nALERT: Alien Invasion Imminent!\n");
    } else {
        printf("\nGOOD NEWS: No signs of alien invasion detected.\n");
    }

    return 0;
}