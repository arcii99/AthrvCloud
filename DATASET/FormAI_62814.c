//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int population = 0;
    int defense = 0;
    int invasion_probability = 0;

    printf("Welcome to the Alien Invasion Probability Calculator\n\n");

    printf("Enter the current population size (in thousands): ");
    scanf("%d", &population);

    printf("Enter the level of defense readiness (1-10): ");
    scanf("%d", &defense);

    // calculate invasion probability
    invasion_probability = (rand() % population) * defense;

    // output results
    printf("\n\nBased on current population size and level of defense readiness,\n");
    printf("the probability of a successful alien invasion is %d%%\n", invasion_probability);

    if (invasion_probability > 50) {
        printf("WARNING: A successful invasion is likely.\n");
    } else {
        printf("No need to worry about alien invasion at the moment.\n");
    }

    return 0;
}