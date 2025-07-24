//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    float alienProb;
    int numDays, numAttacks, totalAttacks = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the probability of an alien invasion in the next 24 hours (0.0 - 1.0): ");
    scanf("%f", &alienProb);

    srand(time(0));

    printf("\nCalculating...\n\n");

    for (numDays = 1; numDays <= 365; numDays++) {
        numAttacks = 0;
        for (int i = 0; i < 24; i++) {
            float r = (float)rand() / RAND_MAX;
            if (r < alienProb) {
                numAttacks++;
            }
        }
        if (numAttacks > 0) {
            printf("Day %d: %d alien attacks!\n", numDays, numAttacks);
        } else {
            printf("Day %d: No alien attacks detected.\n", numDays);
        }
        totalAttacks += numAttacks;
    }

    printf("\nIn the past year, there were a total of %d alien attacks.\n", totalAttacks);

    float avgAttacks = (float)totalAttacks / 365;
    if (avgAttacks > 0) {
        printf("The average number of attacks per day was %.2f.\n", avgAttacks);
        printf("Using this data, we can calculate the probability of another alien invasion in the next 24 hours:\n");

        float nextProb = (avgAttacks / 24);
        printf("The probability of an alien invasion in the next 24 hours is %.4f.\n", nextProb);
    } else {
        printf("No alien attacks detected in the past year. The probability of an alien invasion in the next 24 hours is %.4f.\n", alienProb);
    }

    return 0;
}