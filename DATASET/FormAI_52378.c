//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int invasionProbability, alienStrength, humanStrength;

    // Set the seed for the random number generator
    srand(time(0));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the strength of the aliens (1-10): ");
    scanf("%d", &alienStrength);
    printf("Please enter the strength of the humans (1-10): ");
    scanf("%d", &humanStrength);

    // Calculate the invasion probability
    invasionProbability = (alienStrength * 10) / humanStrength;

    // Add some randomness to the outcome
    invasionProbability += rand() % 20 - 10;

    printf("\n\nBased on the strength of the aliens and humans, the probability of an alien invasion is %d%%\n", invasionProbability);

    return 0;
}