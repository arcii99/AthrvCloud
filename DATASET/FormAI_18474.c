//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp, humidity, pressure;
    srand(time(NULL));

    // Generate random values for temperature, humidity, and pressure
    // Temperature range from 10 to 30 degrees Celsius
    // Humidity range from 20 to 80 percent
    // Pressure range from 980 to 1020 hPa
    temp = rand() % 21 + 10;
    humidity = rand() % 61 + 20;
    pressure = rand() % 41 + 980;

    // Print the generated values
    printf("Temperature: %d degrees Celsius\n", temp);
    printf("Humidity: %d percent\n", humidity);
    printf("Pressure: %d hPa\n", pressure);

    // Simulate the weather conditions based on the generated values
    if (temp >= 25 && humidity >= 60 && pressure >= 1010)
    {
        printf("The weather is hot and humid with high pressure.\n");
    }
    else if (temp >= 25 && humidity >= 60 && pressure < 1010)
    {
        printf("The weather is hot and humid with low pressure.\n");
    }
    else if (temp >= 25 && humidity < 60 && pressure >= 1010)
    {
        printf("The weather is hot and dry with high pressure.\n");
    }
    else if (temp >= 25 && humidity < 60 && pressure < 1010)
    {
        printf("The weather is hot and dry with low pressure.\n");
    }
    else if (temp < 25 && humidity >= 60 && pressure >= 1010)
    {
        printf("The weather is cool and humid with high pressure.\n");
    }
    else if (temp < 25 && humidity >= 60 && pressure < 1010)
    {
        printf("The weather is cool and humid with low pressure.\n");
    }
    else if (temp < 25 && humidity < 60 && pressure >= 1010)
    {
        printf("The weather is cool and dry with high pressure.\n");
    }
    else if (temp < 25 && humidity < 60 && pressure < 1010)
    {
        printf("The weather is cool and dry with low pressure.\n");
    }

    return 0;
}