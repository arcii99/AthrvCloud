//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed based on current time
    srand(time(NULL));
    
    // Define probability of invasion
    double invasion_prob = 0.0;
    
    // Define variables for number of ships and planets
    int num_ships = 0;
    int num_planets = 0;
    
    // Ask user for number of ships and planets
    printf("Enter the number of alien ships in the fleet: ");
    scanf("%d", &num_ships);
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);
    
    // Calculate invasion probability based on number of ships and planets
    if (num_ships == 0) {
        invasion_prob = 0.0;  // No ships means no invasion
    } else if (num_planets == 0) {
        invasion_prob = 1.0;  // No planets means definite invasion
    } else {
        invasion_prob = ((double) num_ships) / ((double) num_planets);
    }
    
    // Add some randomness to the final probability
    invasion_prob *= (double) (rand() % 10) + 1;  // Random probability between 1-10
    
    // Display the final probability
    printf("The probability of an alien invasion is: %f\n", invasion_prob);
    
    return 0;
}