//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to Alien Invasion Probability Calculator\n\n");

    srand(time(NULL)); // Seed the random number generator

    int invasion_probability = rand() % 100 + 1; // Generate a random probability

    printf("The current probability of an alien invasion is %d%%\n\n", invasion_probability);

    if (invasion_probability >= 50)
    {
        printf("Oh no! The probability of an alien invasion is greater than or equal to 50%%.\n");
        printf("Please take appropriate actions to protect yourself and your loved ones.\n");
    }
    else
    {
        printf("Phew! The probability of an alien invasion is less than 50%%.\n");
        printf("You can relax knowing that an invasion is unlikely to occur.\n");
    }

    return 0;
}