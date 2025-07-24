//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializes random number generator with current time
    float alien_prob = rand() % 101 / 100.0; // Generates a random probability value between 0 and 1
    int population = rand() % 1000001; // Generates a random population value between 0 and 1,000,000

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Based on our calculations, there is a %.2f%% chance of an alien invasion.\n", alien_prob * 100);
    printf("Given a population of %d, the estimated number of casualties would be %d.\n", population, (int)(alien_prob * population));

    return 0;
}