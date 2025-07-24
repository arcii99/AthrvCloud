//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <time.h>

int main()
{
    int numCars = 0, maxCars = 50, speed = 0;
    srand(time(0));

    printf("Welcome to Traffic Flow Simulation!\n");
    printf("----------------------------------\n");

    while (numCars < maxCars)
    {
        int carSpeed = (rand() % 70) + 30;
        if (carSpeed <= 40)
        {
            printf("Car is driving too slow! Speed up...\n");
            speed = 50;
        }
        else if (carSpeed > 60)
        {
            printf("Car is driving too fast! Slow down...\n");
            speed = 40;
        }
        else
        {
            speed = carSpeed;
        }

        if (speed > 45)
        {
            printf("Car is not following traffic rules! Issuing ticket...\n");
        }

        printf("Car %d is driving at %d mph\n", numCars+1, speed);
        numCars++;

        if (numCars == maxCars)
        {
            printf("Maximum number of cars reached. Exiting simulation...\n");
        }
        else
        {
            printf("Press any key to add another car...");
            getchar();
            printf("\n");
        }
    }
    return 0;
}