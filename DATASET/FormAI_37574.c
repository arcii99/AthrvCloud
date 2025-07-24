//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set random seed based on current time
    int num_simulations = 10000; // number of simulations to run
    int num_invasions = 0; // number of times an invasion occurred
    double invasion_prob = 0; // probability of an invasion
    int invasion_threshold = 10; // alien civilization's invasion threshold

    for (int i = 0; i < num_simulations; i++) {
        int tech_level = rand() % 11; // generate random tech level between 0-10
        if (tech_level >= invasion_threshold) {
            num_invasions++; // an invasion has occurred
        }
    }

    invasion_prob = (double)num_invasions / num_simulations; // calculate invasion probability
    printf("Based on %d simulations, the probability of an alien invasion is: %.2f%%\n", num_simulations, invasion_prob * 100);

    return 0;
}