//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int numDays = 365; // number of days to simulate
    int numAliens = 100; // number of aliens in the initial invasion
    double invasionChance = 0.05; // probability of an alien invasion on any given day
    int totalInvasions = 0; // total number of invasions throughout the simulation

    for (int i = 0; i < numDays; i++) {
        for (int j = 0; j < numAliens; j++) {
            double randNum = ((double) rand() / RAND_MAX); // generate a random number between 0 and 1
            
            if (randNum <= invasionChance) {
                totalInvasions++;
                printf("Day %d: Alien Invasion!\n", i + 1);
                break; // only one invasion can occur per day
            }
        }
    }

    double invasionProbability = (double) totalInvasions / numDays; // calculate invasion probability
    printf("\nInvasion Probability: %.2f%%\n", invasionProbability * 100);

    return 0;
}