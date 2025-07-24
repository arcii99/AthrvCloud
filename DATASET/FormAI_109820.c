//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 60 - 30; // Generate random temperature between -30 and 30 Celsius
    int humidity = rand() % 100; // Generate random humidity percentage between 0 and 100
    int windSpeed = rand() % 100; // Generate random wind speed in km/h
    int isRaining = rand() % 2; // Generate random boolean for raining or not
    
    printf("Today's weather simulation:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", windSpeed);
    
    if (isRaining) {
        printf("It is currently raining.\n");
    } else {
        printf("It is not currently raining.\n");
    }
    
    if (temperature < -10) {
        printf("It's quite chilly outside. Make sure to bundle up!\n");
    } else if (temperature >= -10 && temperature < 0) {
        printf("It's cold outside. Dress warmly!\n");
    } else if (temperature >= 0 && temperature < 10) {
        printf("It's a bit chilly outside. Bring a light jacket!\n");
    } else if (temperature >= 10 && temperature < 20) {
        printf("It's a nice day outside. Enjoy the weather!\n");
    } else if (temperature >= 20 && temperature < 30) {
        printf("It's quite warm outside. Stay hydrated!\n");
    } else if (temperature >= 30) {
        printf("It's extremely hot outside. Avoid staying outside for too long.\n");
    }
    
    if (humidity < 30) {
        printf("It's quite dry outside. Consider using moisturizer!\n");
    } else if (humidity >= 30 && humidity < 60) {
        printf("It's a normal humidity today. Enjoy the weather!\n");
    } else if (humidity >= 60) {
        printf("It's quite humid outside. Stay cool!\n");
    }
    
    if (windSpeed < 30) {
        printf("It's quite calm outside. Enjoy the weather!\n");
    } else if (windSpeed >= 30 && windSpeed < 70) {
        printf("It's quite windy outside. Hold onto your hats!\n");
    } else if (windSpeed >= 70) {
        printf("It's extremely windy outside. Stay safe!\n");
    }
    
    return 0;
}