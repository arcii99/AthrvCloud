//FormAI DATASET v1.0 Category: Weather simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    float temperature = (float)(rand() % 100 - 20); // Generate a random temperature value from -20 to 79 degrees Celsius
    float humidity = (float)(rand() % 101); // Generate a random humidity value from 0 to 100 percent

    printf("Today's temperature is %.2f degrees Celsius.\n", temperature);
    printf("Today's humidity is %.2f percent.\n", humidity);

    if (temperature < 0)
    {
        printf("It's freezing cold outside! Make sure to bundle up before heading out.\n");
    }
    else if (temperature < 10)
    {
        printf("It's pretty chilly out today. Don't forget to wear your jacket.\n");
    }
    else if (temperature < 20)
    {
        printf("The temperature is moderate today! Enjoy the weather.\n");
    }
    else if (temperature < 30)
    {
        printf("It's getting a bit warm today. Consider wearing something lighter.\n");
    }
    else
    {
        printf("It's scorching hot outside! Stay cool and hydrated.\n");
    }

    if (humidity < 30)
    {
        printf("The air is dry today. Don't forget to drink plenty of water.\n");
    }
    else if (humidity < 60)
    {
        printf("The humidity is just right today. Enjoy the weather!\n");
    }
    else
    {
        printf("It's quite humid outside today. Make sure to stay cool and hydrated.\n");
    }

    return 0;
}