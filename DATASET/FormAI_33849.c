//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seeding the random number generator

    // Setting up the initial temperature and weather conditions
    int temperature = 25;
    int humidity = 70;
    int wind_speed = 10;
    int precipitation = 0;
    int clouds = 50;

    // Initializing the weather types as an array of strings
    char* weather_types[] = {"Sunny", "Partly cloudy", "Overcast", "Rainy", "Stormy"};

    // Randomly selecting the current weather type
    int current_weather_type_index = rand() % 5;
    char* current_weather_type = weather_types[current_weather_type_index];

    // Displaying the current weather conditions
    printf("Current weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Precipitation: %d mm/h\n", precipitation);
    printf("Cloud cover: %d percent\n", clouds);
    printf("Weather type: %s\n\n", current_weather_type);

    // Simulating the weather conditions for the next 5 hours
    for (int i = 1; i <= 5; i++) {
        printf("Hour %d:\n", i);

        // Increasing or decreasing the temperature randomly by up to 3 degrees
        int temperature_change = rand() % 7 - 3;
        temperature += temperature_change;
        printf("Temperature: %d degrees Celsius\n", temperature);

        // Increasing or decreasing the humidity randomly by up to 10 percent
        int humidity_change = rand() % 21 - 10;
        humidity += humidity_change;
        printf("Humidity: %d percent\n", humidity);

        // Increasing or decreasing the wind speed randomly by up to 5 km/h
        int wind_speed_change = rand() % 11 - 5;
        wind_speed += wind_speed_change;
        if (wind_speed < 0) {
            wind_speed = 0;
        }
        printf("Wind speed: %d km/h\n", wind_speed);

        // Increasing or decreasing the precipitation randomly by up to 2 mm/h
        int precipitation_change = rand() % 4 - 2;
        precipitation += precipitation_change;
        if (precipitation < 0) {
            precipitation = 0;
        }
        printf("Precipitation: %d mm/h\n", precipitation);

        // Increasing or decreasing the cloud cover randomly by up to 10 percent
        int clouds_change = rand() % 21 - 10;
        clouds += clouds_change;
        if (clouds > 100) {
            clouds = 100;
        } else if (clouds < 0) {
            clouds = 0;
        }
        printf("Cloud cover: %d percent\n", clouds);

        // Changing the weather type randomly every hour
        current_weather_type_index = rand() % 5;
        current_weather_type = weather_types[current_weather_type_index];
        printf("Weather type: %s\n\n", current_weather_type);
    }

    return 0;
}