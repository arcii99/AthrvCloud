//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp;
    srand(time(NULL));
    temp = rand() % 61 - 20; // generates random temperature between -20 and 40 degrees Celsius
    printf("Current temperature: %d degrees Celsius\n", temp);

    if (temp < 0) {
        printf("It is below freezing!\n");
    } else if (temp >= 0 && temp <= 10) {
        printf("It is very cold.\n");
    } else if (temp > 10 && temp <= 20) {
        printf("It is chilly!\n");
    } else if (temp > 20 && temp <= 30) {
        printf("It is warm outside.\n");
    } else if (temp > 30 && temp <= 40) {
        printf("It is hot outside!\n");
    }

    int wind_speed = rand() % 101; // generates random wind speed between 0 and 100 km/h
    printf("Current wind speed: %d km/h\n", wind_speed);

    if (wind_speed < 10) {
        printf("Wind is calm.\n");
    } else if (wind_speed >= 10 && wind_speed <= 30) {
        printf("Wind is moderate.\n");
    } else if (wind_speed > 30 && wind_speed <= 60) {
        printf("Wind is strong.\n");
    } else if (wind_speed > 60) {
        printf("Wind is very strong!\n");
    }

    int humidity = rand() % 101; // generates random humidity between 0 and 100
    printf("Current humidity: %d%%\n", humidity);

    if (humidity < 30) {
        printf("It is dry outside.\n");
    } else if (humidity >= 30 && humidity <= 60) {
        printf("It is comfortable.\n");
    } else if (humidity > 60) {
        printf("It is humid outside.\n");
    }

    return 0;
}