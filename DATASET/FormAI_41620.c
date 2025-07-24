//FormAI DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char weatherType[5][10] = {"Sunny", "Rainy", "Windy", "Cloudy", "Stormy"};
    char windDirection[4][10] = {"North", "South", "East", "West"};
    int temp, humidity, windSpeed, indexWT, indexWD;
    srand(time(NULL)); // To make the output random every time
    
    printf("\nToday's Weather Forecast:\n\n");
    printf("-----------------------------------\n");
    
    indexWT = rand() % 5; // Selects a random index for weather type
    printf("%s\n", weatherType[indexWT]);
    
    temp = rand() % 40; // Generates a random temperature between 0 and 40°C
    printf("Temperature: %d°C\n", temp);
    
    humidity = rand() % 100; // Generates a random humidity percentage from 0-100%
    printf("Humidity: %d%%\n", humidity);
    
    windSpeed = rand() % 50; // Generates a random wind speed in km/h
    printf("Wind Speed: %dkm/h\n", windSpeed);
    
    indexWD = rand() % 4; // Selects a random index for wind direction
    printf("Wind Direction: %s\n", windDirection[indexWD]);
    
    printf("-----------------------------------\n");
    
    if(temp > 30 && humidity > 80 && indexWT == 1) // If temperature is above 30 and humidity is above 80%, then there is a chance of rain
    {
        printf("Thunderstorm Alert!\nTake a raincoat with you.\n");
    }
    else if(temp < 10 && windSpeed > 20 && indexWT == 2) // If temperature is below 10°C and wind speed is greater than 20 km/h, then there is a chance of a freezing wind
    {
        printf("Freezing Wind Alert!\nWear a warm jacket.\n");
    }
    else if(windSpeed > 40 && humidity < 30 && indexWT != 0) // If wind speed is greater than 40 km/h and humidity is less than 30%, then there is a chance of a sandstorm
    {
        printf("Sandstorm Alert!\nCover your face with a mask and seek shelter.\n");
    }
    else if(temp > 30 && windSpeed > 35 && indexWT == 2) // If temperature is above 30°C and wind speed is greater than 35 km/h, then there is a chance of a dust storm
    {
        printf("Dust Storm Alert!\nStay indoors and keep your windows closed.\n");
    }
    else if(humidity > 90 && indexWT != 2) // If humidity is greater than 90%, then there is a chance of fog or mist
    {
        printf("Fog Alert!\nDrive carefully and turn on your fog lights.\n");
    }
    else // If none of the above alerts have been triggered, then the weather is normal
    {
        printf("No weather alert today.\nEnjoy your day!\n");
    }
    
    return 0;
}