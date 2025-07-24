//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int population = 1000000;
    int military = 75000;
    int alien_ships = 10;
    int alien_crew_per_ship = 25;
    float invasion_probability;
    srand(time(NULL));
 
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Current population: %d\n", population);
    printf("Current military personnel: %d\n", military);
    printf("Number of alien ships: %d\n", alien_ships);
    printf("Number of aliens per ship: %d\n", alien_crew_per_ship);
    
    //Calculate the probability of invasion using a random number generator
    invasion_probability = (float)rand() / RAND_MAX;
    
    printf("\nThe probability of alien invasion is: %.2f%%\n", invasion_probability*100);
    if(invasion_probability > 0.75) {
        printf("\nWarning! High probability of alien invasion!\n");
    } else if(invasion_probability > 0.50 && invasion_probability <= 0.75) {
        printf("\nThe probability of alien invasion is moderate.\nPrepare for possible invasion.\n");
    } else {
        printf("\nThe probability of alien invasion is low.\nNo immediate action required.\n");
    }
    
    printf("\nCalculating potential casualties...\n");
    float invasion_casualties = (population * invasion_probability) / 2;
    float alien_casualties = (military * invasion_probability * 2) + (alien_ships * alien_crew_per_ship * invasion_probability);
 
    printf("\nEstimated human casualties: %.0f\n", invasion_casualties);
    printf("Estimated alien casualties: %.0f\n", alien_casualties);
 
    return 0;
}