//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seeding the random number generator
    int numOfCars = rand() % 100 + 1; // generating a random number between 1 and 100
    int maxTime = 60; // maximum time allowed to cross the road
    int redLightTime = 30; // time the red light is on
    int greenLightTime = 20; // time the green light is on
    int yellowLightTime = 10; // time the yellow light is on
    int totalTime = 0; // total time taken by all the cars to cross the road
    int redCounter = 0;
    int greenCounter = 0;
    int yellowCounter = 0;

    printf("Number of cars waiting at the traffic light: %d\n", numOfCars);

    // traffic light controller loop
    while (numOfCars > 0)
    {
        printf("Red light is on\n");
        for (int i = 0; i < redLightTime; i++)
        {
            printf("%d seconds left\n", redLightTime - i);
            sleep(1);
        }
        redCounter++;
        printf("\n");

        int timeLeft = maxTime - redLightTime; // calculating the remaining time
        int carsCrossed = rand() % numOfCars + 1; // randomly selecting the number of cars that can cross the road
        numOfCars -= carsCrossed; // updating the number of cars remaining
        totalTime += timeLeft; // updating the total time taken by all the cars to cross the road

        if (carsCrossed == 0 && numOfCars > 0)
        {
            printf("No cars crossed the road.\n");
        }
        else if (carsCrossed == 1)
        {
            printf("%d car crossed the road in %d seconds.\n", carsCrossed, timeLeft);
        }
        else
        {
            printf("%d cars crossed the road in %d seconds.\n", carsCrossed, timeLeft);
        }

        if (numOfCars > 0)
        {
            printf("Yellow light is on\n");
            for (int i = 0; i < yellowLightTime; i++)
            {
                printf("%d seconds left\n", yellowLightTime - i);
                sleep(1);
            }
            yellowCounter++;
            printf("\n");

            printf("Green light is on\n");
            for (int i = 0; i < greenLightTime; i++)
            {
                printf("%d seconds left\n", greenLightTime - i);
                sleep(1);
            }
            greenCounter++;
            printf("\n");
        }
    }

    printf("All cars have crossed the road.\n");
    printf("Number of times the red light was on: %d\n", redCounter);
    printf("Number of times the yellow light was on: %d\n", yellowCounter);
    printf("Number of times the green light was on: %d\n", greenCounter);
    printf("Total time taken by all the cars to cross the road: %d seconds\n", totalTime);

    return 0;
}