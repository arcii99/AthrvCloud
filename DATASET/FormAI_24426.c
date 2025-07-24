//FormAI DATASET v1.0 Category: Weather simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int temp, humidity, wind_speed, chance_of_rain;

    srand(time(NULL)); //initializing the randomseed generator

    //generating random values for temperature, humidity, wind speed and chance of rain
    temp = rand() % 50;
    humidity = rand() % 100;
    wind_speed = rand() % 30;
    chance_of_rain = rand() % 100;

    printf("Today's weather forecast:\n");

    if(temp <= 10)
    {
        printf("It's going to be a cold day with a temperature of %d degrees Celsius.\n", temp);
    }
    else if(temp <= 25)
    {
        printf("It's going to be a pleasant day with a temperature of %d degrees Celsius.\n", temp);
    }
    else
    {
        printf("It's going to be a hot day with a temperature of %d degrees Celsius.\n", temp);
    }

    if(humidity <= 30)
    {
        printf("The air will be dry with a humidity of %d percent.\n", humidity);
    }
    else if(humidity <= 70)
    {
        printf("The air will be moderately humid with a humidity of %d percent.\n", humidity);
    }
    else
    {
        printf("The air will be very humid with a humidity of %d percent.\n", humidity);
    }

    if(wind_speed <= 10)
    {
        printf("There will be light winds with a speed of %d km/h.\n", wind_speed);
    }
    else if(wind_speed <= 20)
    {
        printf("There will be moderate winds with a speed of %d km/h.\n", wind_speed);
    }
    else
    {
        printf("There will be strong winds with a speed of %d km/h.\n", wind_speed);
    }

    if(chance_of_rain <= 30)
    {
        printf("There's a low chance of rain at %d percent.\n", chance_of_rain);
    }
    else if(chance_of_rain <= 70)
    {
        printf("There's a moderate chance of rain at %d percent.\n", chance_of_rain);
    }
    else
    {
        printf("There's a high chance of rain at %d percent.\n", chance_of_rain);
    }

    return 0;
}