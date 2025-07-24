//FormAI DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int minTemperature = -20;
    int maxTemperature = 50;
    int minWindSpeed = 0;
    int maxWindSpeed = 100;
    int minRainfall = 0;
    int maxRainfall = 500;
    int minHumidity = 0;
    int maxHumidity = 100;

    int days = 7;

    printf("Seven day weather forecast: \n\n");

    for (int i = 1; i <= days; i++)
    {
        printf("Day %d:\n", i);

        int temperature = rand() % (maxTemperature - minTemperature + 1) + minTemperature;
        int windSpeed = rand() % (maxWindSpeed - minWindSpeed + 1) + minWindSpeed;
        int rainfall = rand() % (maxRainfall - minRainfall + 1) + minRainfall;
        int humidity = rand() % (maxHumidity - minHumidity + 1) + minHumidity;

        printf("Temperature: %dC\n", temperature);
        printf("Wind Speed: %dkm/h\n", windSpeed);
        printf("Rainfall: %dmm\n", rainfall);
        printf("Humidity: %d%%\n\n", humidity);
    }

    return 0;
}