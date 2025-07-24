//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_of_sightings, num_of_countries;
    float avg_sightings_per_country, alien_invasion_probability;
    
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the number of reported alien sightings: ");
    scanf("%d", &num_of_sightings);
    printf("Please enter the number of countries reporting sightings: ");
    scanf("%d", &num_of_countries);
    
    avg_sightings_per_country = (float) num_of_sightings / num_of_countries;
    
    if(avg_sightings_per_country <= 1.0) {
        alien_invasion_probability = 0.01;
    }
    else if(avg_sightings_per_country > 1.0 && avg_sightings_per_country <= 3.0) {
        alien_invasion_probability = 0.25;
    }
    else if(avg_sightings_per_country > 3.0 && avg_sightings_per_country <= 5.0) {
        alien_invasion_probability = 0.50;
    }
    else if(avg_sightings_per_country > 5.0) {
        alien_invasion_probability = 0.75;
    }
    
    printf("\nBased on the reported data, the probability of an alien invasion is %0.2f\n", alien_invasion_probability);
    
    return 0;
}