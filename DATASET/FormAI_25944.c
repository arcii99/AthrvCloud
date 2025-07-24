//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate probability for each scenario
    float prob_sc1 = (float)rand() / (float)RAND_MAX;
    float prob_sc2 = (float)rand() / (float)RAND_MAX;
    float prob_sc3 = (float)rand() / (float)RAND_MAX;
    float prob_sc4 = (float)rand() / (float)RAND_MAX;

    // Calculate overall probability of alien invasion
    float overall_prob = (prob_sc1 + prob_sc2 + prob_sc3 + prob_sc4) / 4.0;

    // Print probability for each scenario
    printf("Scenario 1 Probability: %f\n", prob_sc1);
    printf("Scenario 2 Probability: %f\n", prob_sc2);
    printf("Scenario 3 Probability: %f\n", prob_sc3);
    printf("Scenario 4 Probability: %f\n", prob_sc4);

    // Print overall probability of alien invasion
    printf("Overall Probability of Alien Invasion: %f\n", overall_prob);

    // Determine if invasion is likely or not
    if (overall_prob > 0.5) {
        printf("ALIEN INVASION IS LIKELY!\n");
    }
    else {
        printf("ALIEN INVASION IS UNLIKELY!\n");
    }

    return 0;
}