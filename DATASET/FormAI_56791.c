//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random traffic flow
int random_flow(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // Initializing variables
    int cars[24], i, j, flow;

    // Setting seed for random number generator
    srand(time(0));

    // Generating traffic flow for each hour of the day
    for (i = 0; i < 24; i++)
    {
        flow = random_flow(50, 100); // Random flow between 50 to 100 cars per hour
        cars[i] = flow;
    }

    // Displaying traffic flow for each hour of the day
    printf("Traffic Flow Simulation\n\n");
    printf("Hour\tCars\n");
    printf("-----------------\n");
    for (i = 0; i < 24; i++)
    {
        printf("%d\t%d\n", i, cars[i]);
    }

    // Calculating average traffic flow for the day
    int total_cars = 0;
    for (i = 0; i < 24; i++)
    {
        total_cars += cars[i];
    }
    float avg_flow = (float)total_cars / 24;

    // Displaying average traffic flow for the day
    printf("\nAverage Traffic Flow: %.2f cars per hour\n\n", avg_flow);

    // Checking if traffic flow is high or low for each hour of the day
    printf("Traffic Condition:\n\n");
    for (i = 0; i < 24; i++)
    {
        if (cars[i] >= 80)
        {
            printf("Traffic is High at Hour %d\n", i);
        }
        else if (cars[i] <= 60)
        {
            printf("Traffic is Low at Hour %d\n", i);
        }
        else
        {
            printf("Traffic is Moderate at Hour %d\n", i);
        }
    }

    return 0;
}