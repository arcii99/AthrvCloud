//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alienInvasionProbability(int, int);

int main()
{
    int numDays, prob, invasionChance;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of days you want to assess: ");
    scanf("%d", &numDays);

    printf("Enter the probability percentage of an alien invasion happening (0-100): ");
    scanf("%d", &prob);

    invasionChance = alienInvasionProbability(numDays, prob);

    printf("After assessing the situation for %d day(s), there is a %d%% chance of an alien invasion!\n", numDays, invasionChance);

    return 0;
}

/* Calculates the probability of an alien invasion occurring */
int alienInvasionProbability(int numDays, int prob)
{
    srand(time(NULL)); // Seed the random number generator

    int i, totalProb = 0, invasionChance;

    for (i = 0; i < numDays; i++)
    {
        int randNum = rand() % 101; // Generate a random number from 0-100

        if (randNum <= prob)
        {
            totalProb++;
        }
    }

    invasionChance = (totalProb * 100) / numDays;

    return invasionChance;
}