//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    int i, n, invasion, area, invasionProbability;
    char areaName[30];

    printf("Enter the number of areas to analyze: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        printf("\nEnter the name of area %d: ", i);
        scanf("%s", areaName);
        printf("Enter the population of %s: ", areaName);
        scanf("%d", &area);

        invasion = rand() % 100; // generate random invasion value between 0 and 99
        invasionProbability = (invasion * area) / 1000; // calculate invasion probability
        printf("\nThe probability of an alien invasion in %s is %d%%.\n", areaName, invasionProbability);    
    }

    return 0;
}