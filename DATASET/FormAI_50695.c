//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator
    int temperature = (rand() % 30) + 20; // starting temperature between 20 and 49 degrees Celsius
    int humidity = (rand() % 90) + 10; // starting humidity between 10 and 99%
    int clouds = (rand() % 100) + 1; // starting cloudiness between 1 and 100%
    int wind_speed = (rand() % 20) + 1; // starting wind speed between 1 and 20 km/h
    char wind_direction[] = "north"; // starting wind direction is north
    int rain_chance = (rand() % 100) + 1; // starting chance of rain between 1 and 100%
    
    printf("Welcome to our cheerful weather simulation!\n");
    printf("Today's temperature is %d degrees Celsius.\n", temperature);
    printf("The humidity is %d percent.\n", humidity);
    printf("The cloudiness is %d percent.\n", clouds);
    printf("The wind speed is %d km/h coming from the %s.\n", wind_speed, wind_direction);
    printf("The chance of rain today is %d percent.\n", rain_chance);
    
    int hour = 0;
    while(hour < 24)
    {
        // increase or decrease temperature by up to 5 degrees Celsius
        int temperature_change = (rand() % 11) - 5;
        temperature += temperature_change;
        if(temperature > 49) // temperature cannot exceed 49 degrees Celsius
        {
            temperature = 49;
        }
        else if(temperature < 20) // temperature cannot be below 20 degrees Celsius
        {
            temperature = 20;
        }
        
        // increase or decrease humidity by up to 10%
        int humidity_change = (rand() % 21) - 10;
        humidity += humidity_change;
        if(humidity > 99) // humidity cannot exceed 99%
        {
            humidity = 99;
        }
        else if(humidity < 10) // humidity cannot be below 10%
        {
            humidity = 10;
        }
        
        // increase or decrease cloudiness by up to 10%
        int clouds_change = (rand() % 21) - 10;
        clouds += clouds_change;
        if(clouds > 100) // cloudiness cannot exceed 100%
        {
            clouds = 100;
        }
        else if(clouds < 1) // cloudiness cannot be below 1%
        {
            clouds = 1;
        }
        
        // change wind direction
        int wind_change = (rand() % 4) - 1; // wind direction can change by 0, 90, -90, or 180 degrees
        if(wind_change == 0)
        {
            // wind direction does not change
        }
        else if(wind_change == 1)
        {
            strcpy(wind_direction, "east");
        }
        else if(wind_change == -1)
        {
            strcpy(wind_direction, "west");
        }
        else if(wind_change == 2 || wind_change == -2)
        {
            strcpy(wind_direction, "south");
        }
        else if(wind_change == 3 || wind_change == -3)
        {
            strcpy(wind_direction, "north");
        }
        else if(wind_change == 4 || wind_change == -4)
        {
            strcpy(wind_direction, "northeast");
        }
        
        // determine chance of rain based on humidity and cloudiness
        if(humidity > 70 && clouds > 70)
        {
            rain_chance = (rand() % 50) + 50; // high chance of rain if both humidity and cloudiness are high
        }
        else if(humidity > 50 && clouds > 50)
        {
            rain_chance = (rand() % 25) + 25; // moderate chance of rain if both humidity and cloudiness are moderate
        }
        else
        {
            rain_chance = (rand() % 10) + 1; // low chance of rain otherwise
        }
        
        // print current weather conditions
        printf("Hour %d:\n", hour+1);
        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d percent\n", humidity);
        printf("Cloudiness: %d percent\n", clouds);
        printf("Wind speed: %d km/h coming from the %s.\n", wind_speed, wind_direction);
        printf("Chance of rain: %d percent\n\n", rain_chance);
        
        hour++;
    }
    
    printf("Thank you for using our cheerful weather simulation!");
    
    return 0;
}