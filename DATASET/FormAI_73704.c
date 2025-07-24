//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define MAX 10 // Maximum size of bags
#define INF 999 // Infinity

int size, totalTime, totalTimeInc, delayTime; 
int carg[MAX], csize[MAX], ctime[MAX];

int transitTime[MAX][MAX], delayBy[MAX][MAX], ctransTime[MAX][MAX];
int enroute[MAX][MAX], delayTo[MAX][MAX], carrival[MAX][MAX], cload[MAX][MAX];

void printTimeInc(int arrival[MAX][MAX], int depart[MAX][MAX], int t[MAX][MAX])
{
    int i, j;

    printf("\n%-7s %-7s %-7s", "From", "To", "Time");
    printf("\n----------------------------------");

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (t[i][j] != INF) 
            {
                printf("\n%-7d %-7d %-7d", arrival[i][j], depart[i][j], t[i][j]);
            }
        }
    }
}

void calculateTransitTime()
{
    int i, j;

    printf("\nEnter the transit times (Enter -1 if no connection):");

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (i == j) 
            {
                transitTime[i][j] = 0;
            }
            else 
            {
                printf("\n%d to %d: ", i + 1, j + 1);
                scanf("%d", &transitTime[i][j]);

                if (transitTime[i][j] == -1) 
                {
                    transitTime[i][j] = INF;
                }
            }
        }
    }
}

void calculateDelayBy()
{
    int i, j;

    printf("\nEnter the delay hours (Enter -1 if no connection):");

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (i == j) 
            {
                delayBy[i][j] = 0;
            }
            else 
            {
                printf("\n%s to %s: ", carg[i], carg[j]);
                scanf("%d", &delayBy[i][j]);

                if (delayBy[i][j] == -1) 
                {
                    delayBy[i][j] = INF;
                }
            }
        }
    }
}

void calculateEnroute()
{
    int i, j;

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            enroute[i][j] = transitTime[i][j];
        }
    }
}

void calculateDelayTo()
{
    int i, j;

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            delayTo[i][j] = delayBy[i][j];
        }
    }
}

void calculateTotalTime()
{
    int i, j;

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (i == j) 
            {
                ctransTime[i][j] = 0;
                carrival[i][j] = 0;
                cload[i][j] = csize[i];
                continue;
            }

            if (enroute[i][j] + delayTo[i][j] <= ctime[i]) 
            {
                ctransTime[i][j] = enroute[i][j];
                delayTime = 0;
            } 
            else 
            {
                ctransTime[i][j] = enroute[i][j] + delayTo[i][j] - ctime[i];
                delayTime = ctransTime[i][j];
            }

            carrival[i][j] = ctime[i] + enroute[i][j] + delayTo[i][j]; 
            cload[i][j] = csize[i];

            if (cload[i][j] > carg[j]) 
            {
                cload[i][j] = carg[j];
            }

            carg[i] = carg[i] - cload[i][j];
        }
    }

    totalTime = 0;

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (i == j) 
            {
                continue;
            }

            totalTime += ctransTime[i][j] + delayTime;
        }
    }

    totalTimeInc = totalTime;
}

int main() 
{
    int i, j;

    printf("\nEnter the number of cities: ");
    scanf("%d", &size);

    printf("\nEnter the name of cities:");

    for (i = 0; i < size; i++) 
    {
        scanf("%s", carg[i]);
    }

    printf("\nEnter the cargo at each city:");

    for (i = 0; i < size; i++) 
    {
        scanf("%d", &carg[i]);
        csize[i] = carg[i];
    }

    printf("\nEnter the starting time(s):");

    for (i = 0; i < size; i++) 
    {
        scanf("%d", &ctime[i]);
    }

    calculateTransitTime();
    calculateDelayBy();

    calculateEnroute();
    calculateDelayTo();
    calculateTotalTime();

    printf("\nTotal time taken without incremental loading: %d", totalTimeInc);

    for (i = 0; i < size; i++) 
    {
        for (j = 0; j < size; j++) 
        {
            if (i == j) 
            {
                continue;
            }

            printf("\n-------------------------------");
            printf("\nIncremental loading from %s to %s", carg[i], carg[j]);
            printf("\n-------------------------------");

            while (carg[i] > 0 && carg[j] < MAX) 
            {
                carg[i]--;
                carg[j]++;
                calculateTotalTime();

                if (totalTime < totalTimeInc) 
                {
                    printf("\nCargo transferred: %d", 1);
                    totalTimeInc = totalTime;
                } 
                else 
                {
                    carg[i]++;
                    carg[j]--;
                    break;
                }
            }

            calculateTotalTime();
            printf("\nTotal time taken: %d\n", totalTimeInc);
            printTimeInc(carrival, carrival, ctransTime);
            printf("\n----------------------------------");
        }
    }

    return 0;
}