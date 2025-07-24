//FormAI DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_weather_data(int num_days, int high_temp_range, int low_temp_range, int humidity_range, int wind_speed_range);

int main()
{
    int num_days = 7;
    int high_temp_range = 35;
    int low_temp_range = -10;
    int humidity_range = 100;
    int wind_speed_range = 50;

    generate_weather_data(num_days, high_temp_range, low_temp_range, humidity_range, wind_speed_range);
    
    return 0;
}

void generate_weather_data(int num_days, int high_temp_range, int low_temp_range, int humidity_range, int wind_speed_range)
{
    srand(time(NULL)); // initialize random number generator
    
    printf("Weather forecast for the next %d days:\n\n", num_days);
    
    // loop through each day
    for (int i = 1; i <= num_days; i++)
    {
        // generate random temperature, humidity, and wind speed values
        int high_temp = rand() % high_temp_range;
        int low_temp = rand() % low_temp_range;
        int humidity = rand() % humidity_range;
        int wind_speed = rand() % wind_speed_range;
        
        // calculate average temperature
        int avg_temp = (high_temp + low_temp) / 2;
        
        // display weather data
        printf("Day %d:\n", i);
        printf("High temperature: %dC\n", high_temp);
        printf("Low temperature: %dC\n", low_temp);
        printf("Average temperature: %dC\n", avg_temp);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind speed: %dkph\n\n", wind_speed);
    }
}