//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculateProbability(int x, int y);

int main()
{
    srand(time(NULL));
    int totalInvasions = 0;
    int successfulInvasions = 0;
    int outerGalaxy = 0;

    printf("Welcome to the Alien Invasion Probability Calculator.\n");

    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 100;
        int y = rand() % 100;
        int invasionProbability = calculateProbability(x, y);
        printf("The probability of a successful alien invasion for planet (%d,%d) is %d%%.\n", x, y, invasionProbability);

        totalInvasions++;
        if (invasionProbability >= 50)
        {
            successfulInvasions++;
        }
        if (x > 50 && y < 50)
        {
            outerGalaxy++;
        }
    }

    printf("\nOut of %d potential invasions, there were %d successful invasions.\n", totalInvasions, successfulInvasions);
    printf("%d of the planets were located in the outer galaxy (x > 50, y < 50).\n", outerGalaxy);

    return 0;
}

int calculateProbability(int x, int y)
{
    int distanceFromEarth = (int)sqrt(pow(x - 50, 2) + pow(y - 50, 2));
    int probability = 100 - distanceFromEarth;
    if (probability < 0) probability = 0;
    if (probability > 100) probability = 100;
    return probability;
}