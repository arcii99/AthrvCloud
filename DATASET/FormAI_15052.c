//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temp = rand() % 50;
    int humidity = rand() % 100;
    int rain_chance = rand() % 100;
    int wind_speed = rand() % 50;
    int air_quality = rand() % 500;

    printf("Welcome to the paranoid weather simulator. Today's weather readings are:\n");
    printf("Temperature: %d degrees Celsius\n", temp);
    printf("Humidity: %d%%\n", humidity);
    printf("Rain chance: %d%%\n", rain_chance);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Air quality: %d AQI\n", air_quality);

    if (temp >= 35) {
        printf("WARNING: High temperature alert! Stay indoors and stay hydrated.\n");
    } else if (temp < 0) {
        printf("WARNING: Freezing temperatures! Dress warmly and avoid going outside.\n");
    }

    if (humidity >= 80) {
        printf("WARNING: High humidity levels. Beware of mold growth and sticky conditions.\n");
    }

    if (rain_chance > 50) {
        printf("WARNING: High chance of rain. Don't forget your umbrella and rain gear.\n");
    }

    if (wind_speed >= 30) {
        printf("WARNING: Strong winds in the area. Beware of falling debris and secure loose objects.\n");
    }

    if (air_quality >= 300) {
        printf("WARNING: Hazardous air quality conditions. Avoid outdoor activities and limit exposure to air pollution.\n");
    }

    printf("Stay safe and don't forget to check the weather before heading out!\n");

    return 0;
}