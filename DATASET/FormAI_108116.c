//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    int num_years, num_sightings, prob_aliens;
    
    printf("Please enter the number of years you want to calculate the probability for: ");
    scanf("%d", &num_years);

    printf("\nPlease enter the average number of sightings of UFOs or strange activity in your area per year: ");
    scanf("%d", &num_sightings);

    if(num_years <= 0 || num_sightings <= 0) {
        printf("\nInvalid input. Number of years and sightings must be positive integers.\n");
        return 0;
    }

    prob_aliens = (rand() % (num_years * num_sightings)) + 1;

    if(prob_aliens < (num_years * num_sightings * 0.25)) {
        printf("\nProbability of an alien invasion: LOW\n");
    } else if(prob_aliens >= (num_years * num_sightings * 0.25) && prob_aliens < (num_years * num_sightings * 0.75)) {
        printf("\nProbability of an alien invasion: MEDIUM\n");
    } else {
        printf("\nProbability of an alien invasion: HIGH\n");
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator! Stay safe out there!\n");
    
    return 0;
}