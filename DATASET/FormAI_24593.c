//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_PROBABILITY 0.25        // Probability of Alien Invasion
#define NO_ALIEN_PROBABILITY 1 - ALIEN_PROBABILITY   // Probability of No Alien Invasion

int main() {
    int years = 100;            // Number of Years for which to calculate the probability
    double current_prob = ALIEN_PROBABILITY;   // Starting Probability of Alien Invasion
    double alien_yearly_prob = 0.05;           // Probability of Alien Invasion per year

    srand(time(NULL));          // Random Seed

    printf("Year\tSurvival Probability\n");
    printf("--------------------------------\n");

    for (int i = 0; i < years; i++) {
        double rand_num = (double) rand() / RAND_MAX;   // Generate Random Number between 0 and 1

        if (rand_num <= current_prob) {         // Alien Invasion
            printf("%d\t0%%\n", i+1);
            break;
        }
        else {                                 // No Alien Invasion
            printf("%d\t%.2lf%%\n", i+1, 100 * current_prob);
            current_prob += alien_yearly_prob * NO_ALIEN_PROBABILITY * (1 - current_prob);  // Update Probability for Next Year
        }
    }

    return 0;
}