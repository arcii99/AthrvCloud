//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int allianceStrength, alienStrength, invasionProbability;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Get the strength of the human alliance
    printf("Please enter the strength of the human alliance (out of 100): ");
    scanf("%d", &allianceStrength);

    // Get the strength of the alien invasion force
    printf("Please enter the strength of the alien invasion force (out of 100): ");
    scanf("%d", &alienStrength);

    // Calculate the probability of invasion
    invasionProbability = (100 - allianceStrength) + alienStrength / 2;
    printf("The probability of an alien invasion is %d%%\n", invasionProbability);

    // Check if invasion is likely
    if (invasionProbability >= 50) {
        printf("An alien invasion is likely. Please take necessary precautions!\n");
    } else {
        printf("An alien invasion is unlikely. Carry on with your daily routine!\n");
    }

    return 0;
}