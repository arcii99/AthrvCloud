//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int initialProb, timeElapsed, alienProb;
    srand(time(NULL)); // initialize random number generator

    printf("Welcome to the Alien Invasion Probability Calculator\n\n");
    printf("Please enter the initial probability of an alien invasion (1-100): ");
    scanf("%d", &initialProb);

    printf("How much time has elapsed since the initial probability was calculated (in years)? ");
    scanf("%d", &timeElapsed);

    // calculate new probability using formula P(t) = P(0) * e^(kt)
    float k = 0.01; // k is a constant value
    alienProb = initialProb * exp(k * timeElapsed);

    // add some variability to the probability using random number generator
    int variability = rand() % 20 + 1;
    alienProb += (alienProb * variability / 100);

    // print out final probability
    printf("\nBased on the given information, the new probability of an alien invasion is %d%%.\n", alienProb);

    if (alienProb >= 50) {
        printf("\nALERT! The probability of an alien invasion is high. Please take appropriate measures.\n");
    } else {
        printf("\nThe probability of an alien invasion is low. No need to worry.\n");
    }

    return 0;
}