//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Happy Traffic Flow Simulation!\n");

    srand(time(NULL)); // seed the random number generator

    int numCars = 10 + rand() % 20; // generate a random number of cars between 10 and 30

    int flowRate = 3 + rand() % 5; // generate a random flow rate between 3 and 7 cars per second

    int numLanes = 1 + rand() % 3; // generate a random number of lanes between 1 and 3

    printf("Today we have %d cars on the road, with a flow rate of %d cars per second and %d lanes.\n", numCars,
           flowRate, numLanes);

    int timeElapsed = 0; // keep track of the time elapsed

    int numPassed = 0; // keep track of the number of cars that have passed

    while (numPassed < numCars)
    {
        int numOnRoad = numCars - numPassed; // calculate the number of cars still on the road

        int numToPass = flowRate * numLanes; // calculate the number of cars that can pass this second

        if (numToPass > numOnRoad) // make sure we don't try to pass more cars than are on the road
        {
            numToPass = numOnRoad;
        }

        numPassed += numToPass; // add the number of cars that passed to the total

        printf("After %d seconds, %d cars have passed.\n", timeElapsed, numPassed);

        timeElapsed++; // increment the time elapsed
    }

    printf("All cars have successfully made it through the traffic flow!\n");

    return 0;
}