//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int alienProbability = (rand() % 100) + 1; // Generating a random number between 1 and 100
    int invasionProbability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Enter the threat level (1-10): ");
    int threatLevel;
    scanf("%d", &threatLevel);

    printf("Enter the probability of a government conspiracy (0-100): ");
    int govConspiracyProbability;
    scanf("%d", &govConspiracyProbability);

    printf("Enter the percentage of the population who believe in aliens (0-100): ");
    int beliefPercentage;
    scanf("%d", &beliefPercentage);

    invasionProbability = (threatLevel * 10) + (govConspiracyProbability / 2) + (beliefPercentage / 2) + (alienProbability / 2);

    if (invasionProbability > 100) {
        invasionProbability = 100;
    }

    printf("\n\nCalculating invasion probability...\n\n");
    printf("Based on your input, the probability of an alien invasion is %d%%.\n", invasionProbability);

    return 0;
}