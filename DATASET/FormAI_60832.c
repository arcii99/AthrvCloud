//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variable and set seed for random number generator
    int invasion_probability = 0;
    time_t t;
    srand((unsigned) time(&t));

    // Generate a random number between 0 and 100
    int random_num = rand() % 101;

    // Determine the probability of an alien invasion based on the random number
    if (random_num >= 0 && random_num <= 10)
    {
        invasion_probability = 0;
    }
    else if (random_num >= 11 && random_num <= 30)
    {
        invasion_probability = 25;
    }
    else if (random_num >= 31 && random_num <= 60)
    {
        invasion_probability = 50;
    }
    else if (random_num >= 61 && random_num <= 90)
    {
        invasion_probability = 75;
    }
    else
    {
        invasion_probability = 100;
    }

    // Print the probability of an alien invasion
    printf("Based on our calculations, there is a %d%% chance of an alien invasion.\n", invasion_probability);

    return 0;
}