//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PROBABILITY_MULTIPLIER 10000 // To obtain more accurate probability values

int main()
{
    srand(time(NULL)); // Seed for random number generator
    
    int totalInvasions = 0;
    int successfulInvasions = 0;
    
    int numTrials;
    printf("Enter the number of invasion trials to run: ");
    scanf("%d", &numTrials);
    
    for (int i = 0; i < numTrials; i++)
    {
        int invasionProbability = rand() % PROBABILITY_MULTIPLIER;
        if (invasionProbability > 5000) // 50% chance of invasion
        {
            totalInvasions++;
            int successProbability = rand() % PROBABILITY_MULTIPLIER;
            if (successProbability > 7000) // 70% chance of success
            {
                successfulInvasions++;
            }
        }
    }
    
    float invasionPercentage = (float) totalInvasions / numTrials * 100;
    float successPercentage = (float) successfulInvasions / totalInvasions * 100;
    
    printf("Based on %d trials:\n", numTrials);
    printf("There was a %.2f%% chance of alien invasion.\n", invasionPercentage);
    if (totalInvasions > 0)
    {
        printf("Of those invasions, there was a %.2f%% chance of success.\n", successPercentage);
    }
    else
    {
        printf("No invasions occurred.\n");
    }
    
    return 0;
}