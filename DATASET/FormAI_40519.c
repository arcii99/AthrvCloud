//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    int total_attempts = 1000000;   // total number of attempts
    int total_invasions = 0;        // total number of invasions
    double probability;             // probability of an invasion

    srand(time(NULL));  // seed the random number generator

    for (i = 0; i < total_attempts; i++)
    {
        // simulate an invasion attempt
        int alien_strength = rand() % 101;   // a number between 0 and 100
        int defense_strength = rand() % 101;

        if (alien_strength > defense_strength)   // invasion successful
            total_invasions++;
    }

    probability = (double) total_invasions / total_attempts * 100;

    printf("Based on %d simulation attempts:\n", total_attempts);
    printf("The probability of an alien invasion is %0.2f%%.\n", probability);

    return 0;
}