//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize the variables
    float temp, temp_min, temp_max;
    int humidity, wind_speed, wind_direction;
    char weather_conditions[15];
    
    //set the seed for random number generation
    srand(time(NULL));
    
    //generate random weather data
    temp = (float)(rand() % 40) - 10; //temperature between -10 and 30 degrees Celsius
    humidity = rand() % 101; //humidity between 0% and 100%
    wind_speed = rand() % 101; //wind speed between 0 and 100 km/h
    wind_direction = rand() % 360; //wind direction between 0 and 359 degrees
    switch(rand() % 4) //randomly select a weather condition
    {
        case 0:
            sprintf(weather_conditions, "Sunny");
            temp_min = temp + 10;
            temp_max = temp + 20;
            break;
        case 1:
            sprintf(weather_conditions, "Cloudy");
            temp_min = temp - 5;
            temp_max = temp + 5;
            break;
        case 2:
            sprintf(weather_conditions, "Raining");
            temp_min = temp - 5;
            temp_max = temp;
            break;
        case 3:
            sprintf(weather_conditions, "Snowing");
            temp_min = temp - 15;
            temp_max = temp - 5;
            break;
    }
    
    //print the weather data
    printf("Temperature: %.1f degrees Celsius\n", temp);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Wind direction: %d degrees\n", wind_direction);
    printf("Weather conditions: %s\n", weather_conditions);
    printf("Minimum temperature: %.1f degrees Celsius\n", temp_min);
    printf("Maximum temperature: %.1f degrees Celsius\n", temp_max);
    
    return 0;
}