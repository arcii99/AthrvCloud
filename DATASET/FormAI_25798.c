//FormAI DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed for random number generator

    int temperature = 0;
    int humidity = 0;
    int windSpeed = 0;
    int chancesOfRain = 0;
    int weatherType = 0;

    printf("Welcome to the weather simulator!\n\n");

    // Generate the temperature (between -20 and 40 degrees Celsius)
    temperature = (rand() % 61) - 20;
    printf("Temperature: %d degrees Celsius\n", temperature);

    // Generate the humidity (between 0 and 100%)
    humidity = rand() % 101;
    printf("Humidity: %d%%\n", humidity);

    // Generate the wind speed (between 0 and 50 km/h)
    windSpeed = rand() % 51;
    printf("Wind speed: %d km/h\n", windSpeed);

    // Generate the chances of rain (between 0 and 100%)
    chancesOfRain = rand() % 101;
    printf("Chances of rain: %d%%\n\n", chancesOfRain);

    // Determine the weather type based on the generated data
    if (temperature <= 0) // Below freezing
    {
        weatherType = 1;
    }
    else if (temperature > 0 && temperature <= 10) // Cold
    {
        if (humidity < 80)
        {
            weatherType = 2;
        }
        else
        {
            weatherType = 3;
        }
    }
    else if (temperature > 10 && temperature <= 25) // Moderate
    {
        if (windSpeed < 20)
        {
            weatherType = 4;
        }
        else if (windSpeed >= 20 && windSpeed < 35)
        {
            weatherType = 5;
        }
        else
        {
            weatherType = 6;
        }
    }
    else // Hot
    {
        if (humidity < 60)
        {
            weatherType = 7;
        }
        else if (humidity >= 60 && humidity < 80)
        {
            weatherType = 8;
        }
        else
        {
            weatherType = 9;
        }
    }

    // Display the weather type
    switch (weatherType)
    {
        case 1:
            printf("The weather is below freezing.\n");
            break;
        case 2:
            printf("The weather is cold and dry.\n");
            break;
        case 3:
            printf("The weather is cold and humid.\n");
            break;
        case 4:
            printf("The weather is moderate and calm.\n");
            break;
        case 5:
            printf("The weather is moderate and windy.\n");
            break;
        case 6:
            printf("The weather is moderate and stormy.\n");
            break;
        case 7:
            printf("The weather is hot and dry.\n");
            break;
        case 8:
            printf("The weather is hot and humid.\n");
            break;
        case 9:
            printf("The weather is hot and rainy.\n");
            break;
        default:
            printf("An error occurred while determining the weather type.\n");
            break;
    }

    return 0;
}