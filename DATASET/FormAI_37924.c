//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numAliens, numDays;
    float probability, totalProbability = 1.0;
    srand(time(0));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of aliens that could invade Earth: ");
    scanf("%d", &numAliens);

    printf("Enter the number of days until the invasion: ");
    scanf("%d", &numDays);

    printf("\nCalculating probability...\n");

    for(int i = 1; i <= numDays; i++)
    {
        probability = (float) rand() / RAND_MAX;
        probability *= 0.10;
        totalProbability *= (1 - probability);
    }

    float alienProbability = 1.0 - totalProbability;
    float actualAliens = alienProbability * numAliens;

    printf("\nBased on our calculations, the probability of an alien invasion is %.2f%%\n", alienProbability * 100);
    printf("This means that we can expect approximately %.0f aliens to invade Earth.\n", actualAliens);

    return 0;
}