//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int probability = rand() % 100 + 1;

    // Print the probability of an alien invasion
    printf("The probability of an alien invasion is %d%%\n", probability);

    // If the probability is above a certain threshold, display a warning message
    if (probability >= 75)
    {
        printf("Warning! High probability of alien invasion!\n");
    }
    else if (probability >= 50)
    {
        printf("Caution! Moderate probability of alien invasion!\n");
    }
    else
    {
        printf("No immediate threat of alien invasion.\n");
    }

    return 0;
}