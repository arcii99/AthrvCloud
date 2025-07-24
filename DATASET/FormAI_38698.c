//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    printf("Welcome to the C Alien Invasion Probability Calculator!\n");

    // Gather user input
    int num_planets, num_aliens, num_years;
    printf("Please enter the number of planets in the universe: ");
    scanf("%d", &num_planets);
    printf("Please enter the average number of aliens per planet: ");
    scanf("%d", &num_aliens);
    printf("Please enter the number of years to simulate: ");
    scanf("%d", &num_years);

    // Calculate the probability of at least one planet being invaded
    double invasion_prob = 1 - pow((1 - num_aliens/(double)num_planets), num_years);

    // Print the results
    printf("After %d years, there is a %.2f%% chance of at least one planet being invaded.\n", num_years, invasion_prob*100);

    // Simulate a single invasion event and report the success or failure
    int random_planet = rand() % num_planets + 1;
    int invasion_success = (rand() % num_aliens + 1 <= 1) ? 1 : 0;
    printf("Simulating a single invasion event on planet %d...\n", random_planet);
    if (invasion_success) {
        printf("The invasion was successful! All hail our new alien overlords.\n");
    } else {
        printf("The invasion was unsuccessful. Better luck next time, aliens.\n");
    }

    return 0;
}