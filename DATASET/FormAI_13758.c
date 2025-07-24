//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP 0
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0
#define MAX_WIND_SPEED 50
#define MIN_WIND_SPEED 0
#define MAX_PRESSURE 1100
#define MIN_PRESSURE 900

void simulateWeather() {
    srand(time(NULL)); // seed random number generator
    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    int wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    int pressure = rand() % (MAX_PRESSURE - MIN_PRESSURE + 1) + MIN_PRESSURE;

    printf("Temperature: %d °C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Wind Speed: %d mph\n", wind_speed);
    printf("Pressure: %d mbar\n", pressure);
}

int main() {
    printf("Today's Weather Report:\n");
    simulateWeather();

    return 0;
}