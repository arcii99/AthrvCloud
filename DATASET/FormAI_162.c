//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10
#define MAX_WIND_SPEED 120
#define MIN_WIND_SPEED 0
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

int main()
{
    srand(time(NULL));  // Seed random number generator with current time

    // Generate random weather conditions
    int temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    int wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;

    // Display weather conditions
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Humidity: %d%%\n", humidity);

    // Determine weather type based on conditions
    if (temperature <= 0) 
    {
        printf("Weather: Very Cold\n");
    } 
    else if (temperature <= 10) 
    {
        if (wind_speed >= 40) 
        {
            printf("Weather: Cold and Windy\n");
        } 
        else if (humidity >= 70) 
        {
            printf("Weather: Cold and Damp\n");
        } 
        else 
        {
            printf("Weather: Cold\n");
        }
    } 
    else if (temperature <= 25) 
    {
        if (humidity >= 80) 
        {
            printf("Weather: Humid\n");
        } 
        else if (wind_speed >= 80) 
        {
            printf("Weather: Windy\n");
        } 
        else 
        {
            printf("Weather: Mild\n");
        }
    } 
    else 
    {
        if (wind_speed >= 100) 
        {
            printf("Weather: Very Windy\n");
        } 
        else if (humidity >= 50) 
        {
            printf("Weather: Hot and Humid\n");
        } 
        else 
        {
            printf("Weather: Hot\n");
        }
    }

    return 0;
}