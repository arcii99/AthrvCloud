//FormAI DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, wind_speed, precipitation;
    int rare_chance = 20;

    //weather conditions
    char *weather[5] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy"};

    //initialize random seed
    srand(time(NULL));

    //generate random weather conditions
    int random_weather = rand() % 5;

    //calculate temperature, humidity, wind speed, and precipitation based on weather conditions
    switch (random_weather)
    {
        case 0: //sunny
            temperature = rand() % 30 + 20; //20 to 50 degrees Celsius
            humidity = rand() % 30 + 30; //30 to 60 percent humidity
            wind_speed = rand() % 5; //0 to 4 km/h wind speed
            precipitation = 0; //no precipitation
            break;

        case 1: //cloudy
            temperature = rand() % 20 + 10; //10 to 30 degrees Celsius
            humidity = rand() % 40 + 40; //40 to 80 percent humidity
            wind_speed = rand() % 10 + 5; //5 to 14 km/h wind speed
            precipitation = rand() % 3; //0 to 2 mm precipitation
            break;

        case 2: //rainy
            temperature = rand() % 15 + 5; //5 to 20 degrees Celsius
            humidity = rand() % 60 + 70; //70 to 130 percent humidity
            wind_speed = rand() % 15 + 10; //10 to 24 km/h wind speed
            precipitation = rand() % 10 + 5; //5 to 14 mm precipitation
            break;

        case 3: //stormy
            temperature = rand() % 10 + 0; //0 to 10 degrees Celsius
            humidity = rand() % 80 + 90; //90 to 170 percent humidity
            wind_speed = rand() % 30 + 20; //20 to 49 km/h wind speed
            precipitation = rand() % 40 + 20; //20 to 59 mm precipitation
            break;

        case 4: //snowy
            temperature = rand() % 10 - 10; //-10 to 0 degrees Celsius
            humidity = rand() % 50 + 70; //70 to 119 percent humidity
            wind_speed = rand() % 10 + 5; //5 to 14 km/h wind speed
            precipitation = rand() % 5 + 5; //5 to 9 mm precipitation
            break;

        default:
            break;
    }

    //check if rare event occurs (20% chance)
    if (rand() % 100 < rare_chance)
    {
        printf("A rare event occurs!\n");

        //generate random rare event
        int rare_event = rand() % 3;

        switch (rare_event)
        {
            case 0: //dragon attack
                printf("A dragon attacks the kingdom!\n");
                break;

            case 1: //plague outbreak
                printf("A plague breaks out in the kingdom!\n");
                break;

            case 2: //flood
                printf("A flood devastates the kingdom!\n");
                break;

            default:
                break;
        }
    }

    //display weather conditions
    printf("The weather today is %s.\n", weather[random_weather]);
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Precipitation: %d mm\n", precipitation);

    return 0;
}