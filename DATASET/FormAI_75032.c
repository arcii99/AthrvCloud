//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int human_population, num_sightings, num_abductions;
    double alien_sighting_probability, alien_abduction_probability;

    printf("Enter the estimated human population: ");
    scanf("%d", &human_population);

    printf("Enter the number of reported alien sightings: ");
    scanf("%d", &num_sightings);

    printf("Enter the number of reported alien abductions: ");
    scanf("%d", &num_abductions);

    // Calculating the probability of an alien sighting
    alien_sighting_probability = (double)num_sightings / human_population;

    // Calculating the probability of an alien abduction
    alien_abduction_probability = (double)num_abductions / num_sightings;

    // Displaying the results
    printf("The probability of an alien invasion is: %lf%%\n", 100 * alien_sighting_probability);
    printf("The probability of being abducted by aliens is: %lf%%\n", 100 * alien_abduction_probability);

    // Generating a random number to simulate the arrival of aliens
    srand(time(NULL));
    int arrival_day = rand() % 365 + 1;
    printf("The aliens are predicted to arrive on day %d of the year.\n", arrival_day);

    return 0;
}