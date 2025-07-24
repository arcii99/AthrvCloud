//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_BAGS 100
#define MAX_WEIGHT 50

int main()
{
    int bagWeights[NUM_OF_BAGS];
    int i;
    int totalWeight = 0;
    srand(time(NULL));

    for(i=0;i<NUM_OF_BAGS;i++)
    {
        bagWeights[i] = rand()%MAX_WEIGHT+1;
        totalWeight += bagWeights[i];
    }

    printf("Total weight of bags: %d\n",totalWeight);

    int numOfEmployees = totalWeight/100 + 1;
    printf("Number of required employees: %d\n",numOfEmployees);

    return 0;
}