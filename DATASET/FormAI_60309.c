//FormAI DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    int currentTemp = 20; //starting temperature

    printf("Welcome to the Weather Simulation Program!\n");
    printf("Current temperature is: %d degrees Celsius.\n", currentTemp);

    for(int i = 1; i <= 10; i++) //loop for 10 days of simulation
    {
        int changeInTemp = (rand() % 6) - 2; //random change in temperature between -2 and 3
        currentTemp += changeInTemp; //update current temperature

        if(currentTemp > 30) //check if temperature is over 30 degrees Celsius
        {
            printf("Day %d: It's hot today! Temperature is %d degrees Celsius.\n", i, currentTemp);
        }
        else if(currentTemp < 10) //check if temperature is under 10 degrees Celsius
        {
            printf("Day %d: It's cold today! Temperature is %d degrees Celsius.\n", i, currentTemp);
        }
        else //temperature is between 10 and 30 degrees Celsius
        {
            printf("Day %d: Temperature is %d degrees Celsius.\n", i, currentTemp);
        }
    }

    printf("Thank you for trying the Weather Simulation Program!");

    return 0;
}