//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROBABILITY 100

int main() {
    srand(time(0)); // Seeds the random number generator with the current time

    int probability = rand() % MAX_PROBABILITY; // Generates a random probability between 0 and 100
    bool invasion = probability >= 50; // Determines if an invasion will occur based on the probability

    printf("Alien Invasion Probability: %d%%\n", probability);

    if (invasion) {
        printf("Alien invasion detected!!!\n");
    } else {
        printf("No alien invasion detected.\n");
    }

    return 0;
}