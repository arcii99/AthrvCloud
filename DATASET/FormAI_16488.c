//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int aliens_seen, ships_seen, observations, alien_prob, ship_prob;
    float invasion_prob;
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("\n===== ALIEN INVASION PROBABILITY CALCULATOR =====\n");

    printf("\nEnter the number of alien sightings: ");
    scanf("%d", &aliens_seen);

    printf("Enter the number of spaceship sightings: ");
    scanf("%d", &ships_seen);

    printf("Enter the number of total observations made: ");
    scanf("%d", &observations);

    // Calculate the probabilities of seeing aliens and spaceships
    alien_prob = (aliens_seen * 100) / observations;
    ship_prob = (ships_seen * 100) / observations;

    // Calculate the probability of an alien invasion
    invasion_prob = (float) (alien_prob + ship_prob) / 2;

    // Add some randomness to the invasion probability
    invasion_prob += rand() % 20 - 10;

    // Ensure that the invasion probability is between 0 and 100
    if (invasion_prob < 0) invasion_prob = 0;
    if (invasion_prob > 100) invasion_prob = 100;

    // Display the invasion probability
    printf("\nTHE ALIEN INVASION PROBABILITY IS: %.2f%%\n", invasion_prob);

    return 0;
}