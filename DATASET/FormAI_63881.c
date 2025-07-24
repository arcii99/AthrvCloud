//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator
    int temperature = (rand() % (40 + 1 - (-10))) + (-10); // temperature range from -10 to 40 degrees Celsius
    int humidity = rand() % 101; // humidity range from 0% to 100%
    int wind_speed = rand() % 51; // wind speed range from 0 to 50 km/h
    int cloud_coverage = rand() % 101; // cloud coverage range from 0% to 100%
    
    printf("Current weather conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Cloud coverage: %d%%\n", cloud_coverage);
    
    if (temperature < 0) // extreme cold weather
    {
        printf("It is extremely cold outside, be sure to wear warm clothing and limit your time outdoors.\n");
    }
    else if (temperature >= 0 && temperature <= 10 && humidity >= 80) // cold and humid weather
    {
        printf("It is cold and humid outside, be sure to wear warm, waterproof clothing and limit your time outdoors.\n");
    }
    else if (temperature >= 0 && temperature <= 10 && humidity < 80) // cold but not humid weather
    {
        printf("It is cold outside, be sure to wear warm clothing and limit your time outdoors.\n");
    }
    else if (temperature > 10 && temperature <= 25 && wind_speed > 25) // windy weather
    {
        printf("It is windy outside, be sure to secure loose objects and avoid areas with tall trees or buildings.\n");
    }
    else if (temperature > 25 && cloud_coverage > 80) // hot and cloudy weather
    {
        printf("It is hot and cloudy outside, be sure to stay hydrated and limit your time outdoors.\n");
    }
    else if (temperature > 25 && cloud_coverage <= 80 && humidity >= 60) // hot and humid weather
    {
        printf("It is hot and humid outside, be sure to stay hydrated and limit your time outdoors.\n");
    }
    else if (temperature > 25 && cloud_coverage <= 80 && humidity < 60) // hot and dry weather
    {
        printf("It is hot outside, be sure to stay hydrated and limit your time outdoors.\n");
    }
    else // pleasant weather conditions
    {
        printf("It is pleasant outside, enjoy the day!\n");
    }
    
    return 0;
}