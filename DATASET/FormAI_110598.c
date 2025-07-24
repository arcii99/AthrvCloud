//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature;
    int wind_speed;
    int wind_direction;
    int humidity;
    int precipitation;

    srand(time(NULL)); // initialize random seed

    temperature = rand() % 31; // generate temperature between 0-30 degrees Celsius
    wind_speed = rand() % 51; // generate wind speed between 0-50 km/h
    wind_direction = rand() % 360; // generate wind direction between 0-359 degrees
    humidity = rand() % 101; // generate humidity percentage between 0-100%
    precipitation = rand() % 11; // generate precipitation amount between 0-10 mm

    printf("Today's weather forecast:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Wind direction: %d degrees\n", wind_direction);
    printf("Humidity: %d%%\n", humidity);
    printf("Precipitation: %d mm\n", precipitation);

    return 0;
}