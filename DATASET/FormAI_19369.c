//FormAI DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define CITY_COUNT 3
#define WEATHER_VALUES 4
#define TEMPERATURE_OFFSET 18

char *cities[CITY_COUNT] = {"New York", "Montreal", "Toronto"};

void generate_weather(int city_index, int *weather_output);

int main() {
    int i, j;
    int weather[CITY_COUNT][WEATHER_VALUES];
    printf("Welcome to the Weather Simulation\n");
    printf("------------------------------\n");

    for (i = 0; i < CITY_COUNT; i++) {
        generate_weather(i, weather[i]);
    }

    printf("\nToday's Weather Forecast\n");
    printf("------------------------------\n");

    for (i = 0; i < CITY_COUNT; i++) {
        printf("%s:\t", cities[i]);
        for (j = 0; j < WEATHER_VALUES; j++) {
            printf("%d\t", weather[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void generate_weather(int city_index, int *weather_output) {
    //Generate temperature between 18 and 38 degrees celsius
    int temperature = TEMPERATURE_OFFSET + (rand() % 21);
    //Generate chance of precipitation between 0 and 100
    int chance_of_precipitation = rand() % 101;
    //Generate wind speed between 0 and 20 km/h
    int wind_speed = rand() % 21;
    //Generate humidity between 0 and 100
    int humidity = rand() % 101;

    *(weather_output) = temperature;
    *(weather_output + 1) = chance_of_precipitation;
    *(weather_output + 2) = wind_speed;
    *(weather_output + 3) = humidity;

    printf("%s's weather generated -> temperature: %dC, chance of precipitation: %d%%, wind speed: %dkm/h, humidity: %d%%\n", cities[city_index], temperature, chance_of_precipitation, wind_speed, humidity);
}