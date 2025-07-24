//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting seed for rand() function
    srand(time(0));
    
    // Initializing variables for temperature, humidity and atmospheric pressure
    int temperature = 0;
    int humidity = 0;
    int atmospheric_pressure = 0;
    
    // Generating random values for temperature, humidity and atmospheric pressure
    temperature = rand() % 51; // Temperature ranges from 0 to 50 degrees Celsius
    humidity = rand() % 101; // Humidity ranges from 0% to 100%
    atmospheric_pressure = rand() % 1013; // Atmospheric pressure ranges from 0mb to 1012mb
    
    // Displaying the generated values
    printf("Current Temperature: %d°C\n", temperature);
    printf("Current Humidity: %d%%\n", humidity);
    printf("Current Atmospheric Pressure: %dmb\n", atmospheric_pressure);
    
    // Determining the weather conditions based on the generated values
    if (temperature > 30 && humidity > 80 && atmospheric_pressure < 1000)
    {
        printf("The current weather conditions suggest a Tropical Storm.\n");
    }
    else if (temperature > 25 && humidity > 60 && atmospheric_pressure < 1013)
    {
        printf("The current weather conditions suggest a Thunderstorm.\n");
    }
    else if (temperature < 0 && atmospheric_pressure > 1013)
    {
        printf("The current weather conditions suggest a Snowstorm.\n");
    }
    else if (temperature > 0 && temperature < 20 && humidity > 70)
    {
        printf("The current weather conditions suggest a Rainy day.\n");
    }
    else if (temperature > 20 && temperature < 30 && humidity > 50)
    {
        printf("The current weather conditions suggest a Cloudy day.\n");
    }
    else if (temperature > 10 && temperature < 20 && humidity > 40)
    {
        printf("The current weather conditions suggest a Sunny day with occasional clouds.\n");
    }
    else if (temperature > 0 && temperature < 10 && humidity < 50)
    {
        printf("The current weather conditions suggest a Chilly day.\n");
    }
    else
    {
        printf("The current weather conditions suggest a Clear day.\n");
    }
    
    return 0;
}