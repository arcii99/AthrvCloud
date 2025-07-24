//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that calculates the probability of an alien invasion
float calculate_prob(int num_meteorites, int num_ufo_sightings) {
    float prob;
    int total_events = num_meteorites + num_ufo_sightings;
    if (total_events == 0) {
        prob = 0.0;
    } else {
        prob = (float)num_ufo_sightings / (float)total_events;
    }
    return prob;
}

int main() {
    int num_meteorites;
    int num_ufo_sightings;
    srand(time(NULL)); // Initialize random seed
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of meteorites in the last year: ");
    scanf("%d", &num_meteorites);
    printf("Please enter the number of UFO sightings in the last year: ");
    scanf("%d", &num_ufo_sightings);
    printf("\nCalculating probability of an alien invasion...\n");
    float prob = calculate_prob(num_meteorites, num_ufo_sightings);
    printf("Probability of an alien invasion: %.2f%%\n", prob * 100);
    printf("\nRunning simulations to verify probability...\n\n");
    int num_simulations = 100000;
    int num_invasions = 0;
    for (int i = 0; i < num_simulations; i++) {
        int random_num = rand() % 100 + 1;
        if (random_num <= prob * 100) {
            num_invasions++;
        }
    }
    float invasion_prob = (float)num_invasions / (float)num_simulations;
    printf("After running %d simulations, the probability of an alien invasion was: %.2f%%\n", num_simulations, invasion_prob * 100);
    return 0;
}