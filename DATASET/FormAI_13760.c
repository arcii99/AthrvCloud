//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Set seed for random number generator
    int num_of_sightings = rand() % 100 + 1; // Generate a random number of alien sightings (1-100)
    float probability_of_invasion; // Declare variable for probability of invasion

    if (num_of_sightings <= 25) { // If sightings are low
        probability_of_invasion = 0.02; // Probability of invasion is low
    }
    else if (num_of_sightings > 25 && num_of_sightings <= 50) { // If sightings are moderate
        probability_of_invasion = 0.25; // Probability of invasion is moderate
    }
    else if (num_of_sightings > 50 && num_of_sightings <= 75) { // If sightings are high
        probability_of_invasion = 0.65; // Probability of invasion is high
    }
    else { // If sightings are very high
        probability_of_invasion = 0.95; // Probability of invasion is almost certain
    }

    printf("Number of Alien Sightings: %d\n", num_of_sightings); // Print number of sightings
    printf("Probability of Alien Invasion: %.2f\n", probability_of_invasion); // Print probability of invasion

    return 0;
}