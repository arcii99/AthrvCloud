//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, wind_speed, weather_chance;

    srand(time(0)); //Seed random generator with current time

    printf("Welcome to the Weather Simulator!\n\n");

    for (int i = 1; i <= 7; i++) //Loop for 7 days
    {
        printf("Day %d:\n", i);

        temperature = rand() % 20 + 5; //Generate temperature between 5 and 25 degrees Celsius
        humidity = rand() % 30 + 50; //Generate humidity between 50 and 80 percent
        wind_speed = rand() % 20; //Generate wind speed between 0 and 20 km/h
        weather_chance = rand() % 100; //Generate chance of precipitation between 0 and 100 percent

        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);

        if (weather_chance < 30) //30% chance of precipitation
        {
            printf("Chance of precipitation: %d%%\n", weather_chance);
            printf("Forecast: Rain\n");
        }
        else //70% chance of no precipitation
        {
            printf("Chance of precipitation: %d%%\n", weather_chance);
            printf("Forecast: No rain\n");
        }

        printf("\n"); //Add some space between days
    }

    printf("Thank you for using the Weather Simulator!\n");
    return 0;
}