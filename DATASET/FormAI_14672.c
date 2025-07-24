//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 0 and 100
    int probability = rand() % 101;

    // Print the probability of an alien invasion
    printf("There is a %d%% chance of an alien invasion.\n", probability);

    if (probability >= 80) {
        printf("Oh no! That's a high chance of an invasion. You should probably start preparing.\n");
    } else if (probability >= 50) {
        printf("Hmm, that's a moderate chance of an invasion. Keep an eye out for any unusual activity.\n");
    } else {
        printf("Phew, that's a low chance of an invasion. Looks like we're safe... for now.\n");
    }

    return 0;
}