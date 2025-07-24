//FormAI DATASET v1.0 Category: Weather simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed for random number generator
    int temperature = rand() % 60 - 20; // Generates a random temperature between -20°C and 40°C
    int humidity = rand() % 100; // Generates a random humidity percentage from 0% to 100%
    char *weather_description[] = {"clear", "sunny", "cloudy", "rainy", "thunderstorms", "snowy"}; // An array of possible weather conditions
    int weather_index = rand() % 6; // Randomly selects an index from the weather descriptions array
    char *chosen_weather = weather_description[weather_index]; // Assigns the chosen weather condition string to chosen_weather variable

    printf("Current weather conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Weather: %s\n", chosen_weather);

    // Simulate weather changes
    if (temperature >= 30 && humidity >= 70 && weather_index <= 2) // If temperature is hot and humid and weather is clear, sunny, or cloudy, change to rainy
    {
        chosen_weather = "rainy";
        printf("\nWeather changed to: %s\n", chosen_weather);
    }
    else if (temperature < 0 && weather_index == 5) // If temperature is below freezing and weather is snowy, change to sunny
    {
        chosen_weather = "sunny";
        printf("\nWeather changed to: %s\n", chosen_weather);
    }
    else if (temperature >= 10 && temperature <= 20 && weather_index == 3) // If temperature is mild and weather is rainy, change to cloudy
    {
        chosen_weather = "cloudy";
        printf("\nWeather changed to: %s\n", chosen_weather);
    }
    else if (temperature >= 25 && weather_index == 2) // If temperature is hot and weather is cloudy, change to sunny
    {
        chosen_weather = "sunny";
        printf("\nWeather changed to: %s\n", chosen_weather);
    }
    else if (temperature < 10 && weather_index <= 2) // If temperature is cold and weather is clear, sunny, or cloudy, change to snowy
    {
        chosen_weather = "snowy";
        printf("\nWeather changed to: %s\n", chosen_weather);
    }
    else if (temperature > 0 && temperature < 10 && weather_index == 5) // If temperature is above freezing and weather is snowy, change to cloudy
    {
        chosen_weather = "cloudy";
        printf("\nWeather changed to: %s\n", chosen_weather);
    }
    else // Else, weather remains the same
    {
        printf("\nWeather remains %s\n", chosen_weather);
    }

    return 0;
}