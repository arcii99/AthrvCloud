//FormAI DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generator using current time

    int temperature = rand() % 100; // Generate a random temperature value between 0 and 99
    int humidity = rand() % 100; // Generate a random humidity value between 0 and 99
    int wind_speed = rand() % 50; // Generate a random wind speed value between 0 and 49
    int wind_direction = rand() % 360; // Generate a random wind direction value between 0 and 359

    printf("Current temperature: %d degrees\n", temperature);
    printf("Current humidity: %d%%\n", humidity);
    printf("Current wind speed: %d km/h\n", wind_speed);
    printf("Current wind direction: %d degrees\n", wind_direction);

    if (temperature <= 0) {
        printf("It's freezing outside!\n");
    } else if (temperature > 0 && temperature <= 10) {
        printf("It's very cold outside.\n");
    } else if (temperature > 10 && temperature <= 20) {
        printf("It's chilly outside.\n");
    } else if (temperature > 20 && temperature <= 25) {
        printf("It's pleasant outside.\n");
    } else if (temperature > 25 && temperature <= 30) {
        printf("It's warm outside.\n");
    } else if (temperature > 30 && temperature <= 35) {
        printf("It's hot outside.\n");
    } else if (temperature > 35 && temperature <= 40) {
        printf("It's very hot outside.\n");
    } else {
        printf("It's extremely hot outside!\n");
    }

    if (humidity <= 20) {
        printf("The air is very dry.\n");
    } else if (humidity > 20 && humidity <= 40) {
        printf("The air is somewhat dry.\n");
    } else if (humidity > 40 && humidity <= 60) {
        printf("The air is neither dry nor humid.\n");
    } else if (humidity > 60 && humidity <= 80) {
        printf("The air is somewhat humid.\n");
    } else {
        printf("The air is very humid.\n");
    }

    if (wind_speed < 5) {
        printf("The wind is calm.\n");
    } else if (wind_speed >= 5 && wind_speed < 15) {
        printf("There is a light breeze.\n");
    } else if (wind_speed >= 15 && wind_speed < 30) {
        printf("The wind is moderate.\n");
    } else if (wind_speed >= 30 && wind_speed < 50) {
        printf("The wind is strong.\n");
    } else {
        printf("The wind is very strong!\n");
    }

    if (wind_direction >= 0 && wind_direction < 90) {
        printf("The wind is coming from the North-East direction.\n");
    } else if (wind_direction >= 90 && wind_direction < 180) {
        printf("The wind is coming from the South-East direction.\n");
    } else if (wind_direction >= 180 && wind_direction < 270) {
        printf("The wind is coming from the South-West direction.\n");
    } else {
        printf("The wind is coming from the North-West direction.\n");
    }

    return 0;
}