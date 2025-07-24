//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int temperature = (rand() % 50) + 1; // generate random temperature between 1 and 50 degree Celsius
    int precipitation_chance = (rand() % 101); // generate random precipitation chance between 0 and 100 percent

    printf("Today's temperature is %d degree Celsius.\n", temperature);

    if (temperature >= 40)
    {
        printf("It is extremely hot today!\n");
    }
    else if (temperature >= 30)
    {
        printf("It is very hot today!\n");
    }
    else if (temperature >= 20)
    {
        printf("It is warm today.\n");
    }
    else if (temperature >= 10)
    {
        printf("It is cool today.\n");
    }
    else
    {
        printf("It is cold today.\n");
    }

    if (precipitation_chance >= 75)
    {
        printf("It is going to rain today with %d percent chance of precipitation.\n", precipitation_chance);
    }
    else if (precipitation_chance >= 50)
    {
        printf("It may rain today with %d percent chance of precipitation.\n", precipitation_chance);
    }
    else if (precipitation_chance >= 25)
    {
        printf("It might be cloudy today with %d percent chance of precipitation.\n", precipitation_chance);
    }
    else
    {
        printf("It will be sunny today with %d percent chance of precipitation.\n", precipitation_chance);
    }

    return 0;
}