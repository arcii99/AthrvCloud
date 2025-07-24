//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int probability = rand() % 101; // Generate a probability between 0 and 100
    printf("The probability of an alien invasion is %d percent.\n", probability);
    if (probability >= 70) { // If the probability is 70 or greater, there is a high chance of invasion
        printf("It's time to start preparing for an alien invasion!\n");
    } else { // If the probability is less than 70, there is a low chance of invasion
        printf("We can rest easy knowing the probability of an alien invasion is low.\n");
    }
    return 0;
}